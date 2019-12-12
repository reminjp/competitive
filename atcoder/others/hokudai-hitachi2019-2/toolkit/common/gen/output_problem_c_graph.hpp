#ifndef OUTPUT_PROBLEM_C_GRAPH_HPP
#define OUTPUT_PROBLEM_C_GRAPH_HPP

#include "../lib/graph.hpp"
#include "../lib/random_number.hpp"
#include "../utils/constraints.hpp"

#include <cinttypes>
#include <vector>
#include <map>
#include <utility>
#include <tuple>
#include <cassert>

int convert_bit_to_num(int bit) {
  int bit_ = bit, popcnt = 0;
  while(bit_) {
    if(bit_ & 1) popcnt++;
    bit_ >>= 1;
  }
  assert(popcnt == 1);

  for(int i=0; i<=6; i++) {
    if(bit >> i & 1) return i;
  }
  assert(false);
}

void output_problem_c_graph(const graph<edge> &G, random_number &rnd, FILE *fp) {
  size_t N = G.size();

  std::map< std::pair<size_t, size_t>, std::tuple<edge::cost_type, int, int> > edges;
  for(size_t i=0; i<N; i++) {
    for(auto e : G[i]) {
      size_t u = e.src, v = e.dst;
      edge::cost_type c = e.cost; int b = e.bit;

      std::pair<size_t, size_t> m = std::minmax(u, v);
      std::get<0>(edges[m]) = c;
      if(u < v) std::get<1>(edges[m]) = b;
      if(u > v) std::get<2>(edges[m]) = b;
    }
  }

  std::vector< std::tuple<size_t, size_t, edge::cost_type, int, int> > vec;
  for(auto e : edges) {
    size_t u, v; std::tie(u, v) = e.first;
    edge::cost_type c; int b1, b2; std::tie(c, b1, b2) = e.second;
    vec.emplace_back(u, v, c, b1, b2);
  }

  rnd.shuffle(vec.begin(), vec.end());

  size_t M = vec.size();
  fprintf(fp, "%zu %zu\n", N, M);
  for(auto e : vec) {
    size_t u, v; edge::cost_type c; int b1, b2;
    std::tie(u, v, c, b1, b2) = e;
    u += INDEXED, v += INDEXED;
    
    if(rnd.next_int(0, 1)) {
      std::swap(u, v);
      std::swap(b1, b2);
    }

    b1 = convert_bit_to_num(b1);
    b2 = convert_bit_to_num(b2);
    fprintf(fp, "%zu %zu %" PRId64 " %d %d\n", u, v, c, b1, b2);
  }
  
  fflush(fp);
}

#endif
