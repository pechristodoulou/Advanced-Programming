#include "Pipeline.hh"

int main() {
  Pipeline p(12, 3, 700);  // 12 items, 3 consumers, max 700ms delay
  p.run();

  return 0;
}
