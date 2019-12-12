#ifndef PROBLEM_C_FREQUENCY_GENERATOR_HPP
#define PROBLEM_C_FREQUENCY_GENERATOR_HPP

#include <vector>
#include <utility>
#include "../utils/constraints.hpp"
#include "../lib/random_number.hpp"
#include "../lib/graph.hpp"


// [入力] 座標
// [出力] vector (frequency)
std::vector<edge::cost_type> problem_c_frequency_generator(const std::vector<double> &x, const std::vector<double> &y,
							   const size_t speed_way_col, const size_t speed_way_row,
							   random_number &rnd) {
  assert(x.size() == y.size());
  size_t N = x.size();
  assert(MIN_N <= N and N <= MAX_N);
	
  size_t M = 1;
  for(size_t num = 1;; num++) {
    if(num * num > N) break;
    M = num;
  }
	
  double delta = M / (double)2.0;
  std::pair<double, double> centerPoint;
  centerPoint = std::make_pair(rnd.next_double() * delta + M / (double)4.0, rnd.next_double() * delta + M / (double)4.0);
  std::vector<edge::cost_type> f(N);
  for(size_t i = 0; i < N; i++) {
    double distance = (x[i] - centerPoint.first) * (x[i] - centerPoint.first) + (y[i] - centerPoint.second) * (y[i] - centerPoint.second);
    distance = std::pow(distance, 0.5);
    if(distance <= rnd.next_double() * M / (double)8.0 + M / (double)8.0) f[i] = MAX_FREQ;
    else f[i] = MIN_FREQ;
  }
	
  for(size_t j = 0; j < M; j++) {
    size_t i = speed_way_col;
    size_t u = i * M + j;
    f[u] = 0;
  }
	
  for(size_t i = 0; i < M; i++) {
    size_t j = speed_way_row;
    size_t u = i * M + j;
    f[u] = 0;
  }

  return f;

}

#endif
