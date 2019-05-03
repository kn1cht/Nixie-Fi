#ifndef __MOVING_COUNTER_HPP__
#define __MOVING_COUNTER_HPP__

#include<stdint.h>
#include <vector>

class MovingCounter {
private:
  uint8_t ind = 0;
  uint8_t num = 0;
  uint16_t sum = 0;
  std::vector<uint8_t> count_vec;
public:
  MovingCounter(uint8_t _num);
  uint16_t push(uint8_t val);
  explicit operator uint16_t() const noexcept;
  MovingCounter& operator+=(const uint8_t& val) ;
};

#endif // MOVING_COUNTER_HPP
