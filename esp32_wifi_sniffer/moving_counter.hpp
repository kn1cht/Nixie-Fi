#ifndef __MOVING_COUNTER_HPP__
#define __MOVING_COUNTER_HPP__

#include<stdint.h>
#include <vector>

class MovingCounter {
private:
  int8_t ind = 0;
  int8_t num = 0;
  int16_t sum = 0;
  std::vector<int8_t> count_vec;
public:
  MovingCounter(uint8_t _num);
  void push(int8_t val);
  int16_t get();
  double get_average();
  explicit operator int16_t() const noexcept;
  MovingCounter& operator+=(const int8_t& val) ;
};

#endif // MOVING_COUNTER_HPP
