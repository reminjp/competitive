#ifndef JAM_GENERATOR
#define JAM_GENERATOR

#include "../lib/random_number.hpp"
#include "../utils/constraints.hpp"

int64_t calc_delay(random_number &rnd) {
  return static_cast<int64_t>(rnd.next_double_by_power_law(3, 100));
}

int64_t calc_duration(random_number &rnd) {
  return static_cast<int64_t>(rnd.next_double_by_exponential(1000));
}

std::vector<std::vector<bool>> generate_jam(const std::vector<std::vector<size_t>> &t, random_number &rnd) {
  std::vector<std::vector<bool>> jam(4, std::vector<bool> (TIME_LIMIT));
  
  for(size_t i = 0; i < 4; i++) {
    for(size_t j = 0; j < 4; j++) {			
      if(rnd.next_double() > P_JAM) continue;
      int64_t t_start = t[i][j] + calc_delay(rnd);
      int64_t t_end = t_start + calc_duration(rnd);
      for(int64_t k = t_start; k <= t_end and k < TIME_LIMIT; k++) {
	jam[i][k] = true;
      }
    }
  }

  return jam;
}

#endif
