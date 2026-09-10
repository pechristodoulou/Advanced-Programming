#include "Pipeline.hh"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

Pipeline::Pipeline(int items, int consumers, int delay)
  : n_items(items), n_consumers(consumers), max_delay(delay), done(false) {}

Pipeline::~Pipeline() {
  if (prod_thread.joinable()) prod_thread.join();
  for (auto& t : consumer_threads)
    if (t.joinable()) t.join();
}

void Pipeline::run() {
  prod_thread = thread(&Pipeline::produce, this);

  for (int i = 0; i < n_consumers; ++i)
    consumer_threads.emplace_back(&Pipeline::consume, this, i);
}

void Pipeline::produce() {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<> delay(0, 500);

  for (int i = 0; i < n_items; ++i) {
    double val = i + 0.5;
    this_thread::sleep_for(milliseconds(delay(mt)));

    {
      lock_guard<mutex> lock(mtx);
      q.push(val);
      cout << "[Producer] Pushed: " << val << endl;
    }

    cv.notify_one();
  }

  {
    lock_guard<mutex> lock(mtx);
    done = true;
  }
  cv.notify_all();
}

void Pipeline::consume(int id) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<> delay(0, max_delay);

  while (true) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [this] { return !q.empty() || done; });

    if (!q.empty()) {
      double val = q.front();
      q.pop();
      cout << "[Consumer " << id << "] Got: " << val << endl;
      lock.unlock();
      this_thread::sleep_for(milliseconds(delay(mt)));
    } else if (done) {
      break;
    }
  }

  cout << "[Consumer " << id << "] Exiting.\n";
}
