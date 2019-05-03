#include "moving_counter.hpp"

MovingCounter::MovingCounter(uint8_t _num) : num(_num) {
  count_vec = std::vector<uint8_t> (num, 0);
}

uint16_t MovingCounter::push(uint8_t val) {
  sum += val - count_vec[ind];
  count_vec[ind] = val;
  ind = (ind + 1) % num;
  return sum;
};

MovingCounter::operator uint16_t() const noexcept { return sum; };

MovingCounter& MovingCounter::operator+=(const uint8_t& val) {
  push(val);
};
