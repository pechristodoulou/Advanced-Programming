#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>
using namespace std;

queue<double> q;
mutex mtx;
condition_variable cv;
bool done = false;

int n_elem = 10;
int num_consumers = 2;
int consumer_sleep_max = 1000;

// Random generator
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<> producer_delay(0, 500);
uniform_int_distribution<> consumer_delay(0, consumer_sleep_max);

void produce() {
    for (int i = 0; i < n_elem; ++i) {
        double val = i + 0.5; // placeholder work
        this_thread::sleep_for(chrono::milliseconds(producer_delay(mt)));

        {
            unique_lock<mutex> lock(mtx);
            q.push(val);
            cout << "[Producer] Pushed: " << val << endl;
        }

        cv.notify_one();
    }

    {
        unique_lock<mutex> lock(mtx);
        done = true;
    }

    cv.notify_all();
}

void consume(int id) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !q.empty() || done; });

        if (!q.empty()) {
            double val = q.front();
            q.pop();
            cout << "[Consumer " << id << "] Got: " << val << endl;
            lock.unlock();

            this_thread::sleep_for(chrono::milliseconds(consumer_delay(mt)));
        } else if (done) {
            break;
        }
    }

    cout << "[Consumer " << id << "] Exiting.\n";
}

int main() {
    thread p(produce);
    vector<thread> consumers;

    for (int i = 0; i < num_consumers; ++i)
        consumers.emplace_back(consume, i);

    p.join();
    for (auto& c : consumers)
        c.join();

    return 0;
}
