#ifndef PIPELINE_HH
#define PIPELINE_HH

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

class Pipeline {
public:
  Pipeline(int n_items = 10, int n_consumers = 2, int max_delay = 1000);
  ~Pipeline();

  void run();

private:
  void produce();
  void consume(int id);

  std::queue<double> q;
  std::mutex mtx;
  std::condition_variable cv;
  bool done;

  int n_items;
  int n_consumers;
  int max_delay;

  std::thread prod_thread;
  std::vector<std::thread> consumer_threads;
};

#endif
