#include <cstdio>
#include "../common/gen/problem_c_graph_generator.hpp"
#include "../common/gen/output_problem_c_graph.hpp"
#include "../common/gen/problem_c_graph_relabeling.hpp"
#include "../common/gen/jam_generator.hpp"
#include "../common/lib/agent.hpp"
#include "../common/lib/order.hpp"
#include "../common/lib/state_for_problem_C.hpp"
#include "../common/gen/output_frequency.hpp"

int main(int argc, char** argv) {
  if(argc != 2) {
    fprintf(stderr, "Usage: %s <seed>\n", argv[0]);
    return 1;
  }

  uint_fast64_t seed = strtoull(argv[1], nullptr, 10);
  random_number rnd(seed);
  size_t N = rnd.next_int(MIN_N, MAX_N);
  size_t M = rnd.next_int((N*3 + 1) / 2, N*2);
  
  graph<edge> G = generate_problem_c_graph(N, M, rnd);
  G = problem_c_graph_relabeling(G, rnd);

  output_problem_c_graph(G, rnd, stdout);
  output_frequency(G, stdout);

  std::vector< std::vector<size_t> > t_jam(4, std::vector<size_t>(4, 0));
  for(size_t i=0; i<4; i++) {
    for(size_t j=0; j<4; j++) {
      t_jam[i][j] = rnd.next_uint(0, TIME_LIMIT - 1);
    }
    std::sort(t_jam[i].begin(), t_jam[i].end());
    for(size_t j=0; j<4; j++) {
      fprintf(stdout, "%zu%c", t_jam[i][j], " \n"[j + 1 == 4]);
    }
  }

  int p_light = rnd.next_int(P_LIGHT_MIN, P_LIGHT_MAX);
  int t_warning = rnd.next_int(T_WARNING_MIN, T_WARNING_MAX);
  fprintf(stdout, "%d\n%d\n", p_light, t_warning);
  
  const int max_step = TIME_LIMIT;
  fprintf(stdout, "%d\n", max_step);
  fflush(stdout);

  std::vector< std::vector<bool> > jam = generate_jam(t_jam, rnd);		
  std::vector< std::pair<double, double> > prob_segment;
  double med = rnd.next_double() * 0.95;
  prob_segment.emplace_back(0.0 , 0.0);
  prob_segment.emplace_back(med , 1.0);
  prob_segment.emplace_back(0.95, 0.0);
  prob_segment.emplace_back(1.1 , 0.0);

  unsigned long long int seed_for_state = rnd.next_ulong();
  state st(G, max_step,
	   p_light, t_warning,
	   jam,
	   prob_segment,
	   seed_for_state);

  bool valid = true;
  for(int i=0; i<max_step; i++) {
    valid &= st.increment_step();
    if(!valid) break;
  }

  if(valid) fprintf(stderr, "Accepted: %" PRId64 "\n", st.calculate_score());
  else fprintf(stderr, "Error: your program did not get Accepted\n");
  return 0;
}
