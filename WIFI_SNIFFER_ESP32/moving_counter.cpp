#include "moving_counter.hpp"
#include <Print.h>

MovingCounter::MovingCounter(uint8_t _num) : num(_num) {
  count_vec = std::vector<int8_t> (num, 0);
}

int16_t MovingCounter::get() {
  return sum;
};

double MovingCounter::get_average() {
  return (double)sum / num;
};

void MovingCounter::push(int8_t val) {
  sum += val - count_vec[ind];
  count_vec[ind] = val;
  ind = (ind + 1) % num;
};

MovingCounter::operator int16_t() const noexcept { return sum; };

MovingCounter& MovingCounter::operator+=(const int8_t& val) {
  push(val);
};
