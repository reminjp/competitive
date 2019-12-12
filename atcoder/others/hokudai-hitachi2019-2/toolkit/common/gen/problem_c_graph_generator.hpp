#ifndef PROBLEM_C_GRAPH_GENERATOR_HPP
#define PROBLEM_C_GRAPH_GENERATOR_HPP

#include <queue>
#include <tuple>
#include <cinttypes>
#include <utility>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm> 
#include "../utils/constraints.hpp"
#include "../lib/graph.hpp"
#include "../lib/random_number.hpp"
#include "../lib/union_find.hpp"
#include "./random_points_generator.hpp"
#include "./problem_c_frequency_generator.hpp"

void kruskal(graph<edge> &G, std::vector<std::vector<double>> &distance) {	
  const double INF = 1e9;
  // the number of vertices
  size_t N = distance.size();
  assert(MIN_N <= N and N <= MAX_N);
  using Point = std::pair<size_t, size_t>;
  // edges {cost, point}
  std::vector<std::pair<double, Point>> edges;

  for(size_t u = 0; u < N; u++) {
    for(size_t v = u + 1; v < N; v++) {
      edges.push_back({distance[u][v], {u, v}});
    }
  }

  // sort edges
  std::sort(edges.begin(), edges.end());

  // manage connected components by using Union Find
  UnionFind uf(N);

  // すでにつながっている辺は unite しておく
  for(size_t i = 0; i < N; i++) {
    for(auto e : G[i]) {
      size_t u, v;
      u = e.src;
      v = e.dst;
      if(u > v) continue;
      uf.unite(u, v);
    }
  }

  // create minimum spanning tree
  for(size_t ei = 0; ei < edges.size(); ei++) {
    size_t u, v;
    std::tie(u, v) = edges[ei].second;
    double dis_u_v = edges[ei].first;
    if(dis_u_v == INF) continue;
		
    if(uf.unite(u, v)) {
      edge::cost_type e_cost = ceil(dis_u_v * SCALE_ROAD);
      if(e_cost == 0) e_cost = 1;
      G.add_edge(u, v, e_cost, (1 << 0));
      G.add_edge(v, u, e_cost, (1 << 0));
    }
  }
}

graph<edge> generate_problem_c_graph(size_t N, size_t M, random_number &rnd) {
  assert(MIN_N <= N and N <= MAX_N);
  assert(N - 1 <= M and M <= N * (N - 1) / 2);
	
  size_t R = 1;
  const double INF = 1e9;
  for(size_t num = 1;; num++) {
    if(num * num > N) break;
    R = num;
  }	

  std::vector<double> x;
  std::vector<double> y;
  std::vector<size_t> degree(N, 0);
  std::tie(x, y) = random_points_generator(N, rnd);			      // point
  std::vector<std::vector<double>> distance(N, std::vector<double> (N, 0.0)); // all to all distance
  using Point = std::pair<size_t, size_t>;

  for(size_t u = 0; u < N; u++) {
    for(size_t v = u + 1; v < N; v++) {
      distance[u][v] = distance[v][u] = std::pow((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]), 0.5);
    }
  }

  // create speed way
  size_t speed_way_col = rnd.next_uint(R / 3, 2 * R / 3);
  size_t speed_way_row = rnd.next_uint(R / 2, 2 * R / 3);
  size_t line_row      = rnd.next_uint(R / 6, R / 3);
  std::vector<edge::cost_type> freq = problem_c_frequency_generator(x, y, speed_way_col, speed_way_row, rnd);  // freqency
  graph<edge> G(N, freq);

  for(size_t j = 0; j < R - 1; j++) {
    size_t i = speed_way_col;
    assert(i < R and j < R);
    size_t u = i * R + j;	
    size_t v = i * R + j + 1;
    G.add_edge(u, v, COST_SPEEDWAY, (1 << 1));
    G.add_edge(v, u, COST_SPEEDWAY, (1 << 2));
    distance[u][v] = distance[v][u] = INF;
  }

  for(size_t i = 0; i < R - 1; i++) {
    size_t j = speed_way_row;
    assert(i < R and j < R);
    size_t u = i * R + j;
    size_t v = (i + 1) * R + j;
    G.add_edge(u, v, COST_SPEEDWAY, (1 << 3));
    G.add_edge(v, u, COST_SPEEDWAY, (1 << 4));
    distance[u][v] = distance[v][u] = INF;
  }
	
  // 交差点から上下方向へ
  for(size_t delta = INTERVAL; delta < R; delta += INTERVAL) {
    for(int dir = -1; dir <= 1; dir += 2) {
      size_t i = speed_way_col + dir * delta;
				
      if(R <= i) continue;
      size_t j = speed_way_row;
      assert(i < R and j < R);
      size_t u = i * R + j;
      size_t v1 = i * R + j - 1;
      size_t v2 = i * R + j + 1;
				
      edge::cost_type e_cost_1 = ceil(distance[u][v1] * SCALE_HIGHWAY);
      edge::cost_type e_cost_2 = ceil(distance[u][v2] * SCALE_HIGHWAY);
      G.add_edge(u, v1, e_cost_1, (1 << 6));
      G.add_edge(v1, u, e_cost_1, (1 << 5));
      G.add_edge(u, v2, e_cost_2, (1 << 6));
      G.add_edge(v2, u, e_cost_2, (1 << 5));
      distance[u][v1] = distance[v1][u] = INF;
      distance[u][v2] = distance[v2][u] = INF;
    }
  }
	
  // 交差点から左右方向へ
  for(size_t delta = INTERVAL; delta < R; delta += INTERVAL) {
    for(int dir = -1; dir <= 1; dir += 2) {
      size_t j = speed_way_row + dir * delta;
      if(R <= j) continue;
      size_t i = speed_way_col;
      assert(i < R and j < R);
      size_t u = i * R + j;
      size_t v1 = (i - 1) * R + j;
      size_t v2 = (i + 1) * R + j;
      edge::cost_type e_cost_1 = ceil(distance[u][v1] * SCALE_HIGHWAY);
      edge::cost_type e_cost_2 = ceil(distance[u][v2] * SCALE_HIGHWAY);

      G.add_edge(u, v1, e_cost_1, (1 << 6));
      G.add_edge(v1, u, e_cost_1, (1 << 5));
      G.add_edge(u, v2, e_cost_2, (1 << 6));
      G.add_edge(v2, u, e_cost_2, (1 << 5));
      distance[u][v1] = distance[v1][u] = INF;
      distance[u][v2] = distance[v2][u] = INF;
    }
  }

  // 線路に対して上下方向へ
  for(size_t delta = INTERVAL; delta < R; delta += INTERVAL) {
    for(int dir = -1; dir <= 1; dir += 2) {
      size_t i = speed_way_col + dir * delta;
      if(R <= i) continue;
      size_t j = line_row;
      assert(i < R and j < R);
      size_t u = i * R + j;
      size_t v = i * R + j + 1;
      edge::cost_type e_cost = ceil(distance[u][v] * SCALE_HIGHWAY);
      G.add_edge(u, v, e_cost, (1 << 0));
      G.add_edge(v, u, e_cost, (1 << 0));
			
      distance[u][v] = distance[v][u] = INF;
    }
  }

  // すでに使った辺は INF になっている。領域を横断する辺を INF にしてから kruskal

  // speed way 上の頂点 u から出る辺は INF にする
  for(size_t i = 0; i < R; i++) {
    size_t j = speed_way_row;
    size_t u = i * R + j;
    for(size_t v = 0; v < N; v++) {
      distance[u][v] = distance[v][u] = INF;
    }
  }	
  for(size_t j = 0; j < R; j++) {
    size_t i = speed_way_col;
    size_t u = i * R + j;
    for(size_t v = 0; v < N; v++) {
      distance[u][v] = distance[v][u] = INF;
    }
  }	
  for(size_t i1 = 0; i1 < R; i1++) {
    for(size_t i2 = 0; i2 < R; i2++) {
      for(size_t j1 = 0; j1 < R; j1++) {
	for(size_t j2 = 0; j2 < R; j2++) {
	  size_t u = i1 * R + j1;
	  size_t v = i2 * R + j2;
	  if(u == v) continue;
	  // speed way に乗ってたら、	INF
	  if(i1 == speed_way_col or i2 == speed_way_col or j1 == speed_way_row or j2 == speed_way_row) {
	    distance[u][v] = distance[v][u] = INF;
	  } else {
	    size_t area1 = 0;
	    if(i1 > speed_way_col) area1 += 3;
	    if(j1 > line_row) area1++;
	    if(j1 > speed_way_row) area1++;
	    size_t area2 = 0;
	    if(i2 > speed_way_col) area2 += 3;
	    if(j2 > line_row) area2++;
	    if(j2 > speed_way_row) area2++;

	    if(area1 != area2) {
	      distance[u][v] = distance[v][u] = INF;
	    }
	  }
	}
      }
    }
  }

  kruskal(G, distance);

  // caluculate degree of certices
  for(size_t i = 0; i < N; i++) {
    for(auto e : G[i]) {
      size_t u, v;
      u = e.src;
      v = e.dst;
      if(u > v) continue;
      degree[u]++;
      degree[v]++;
    }
  }

  // select edge greedy
  size_t restEdge = M - (N - 1);
  G.sort_edges();
	
  std::vector<std::vector<double>> edgeCost(N, std::vector<double> (N, INF));
  std::set<std::pair<double, Point>> edgeSet;

  // edgeCost[i][j] := deg[i] * deg[j] * distance。もう使われている辺は INF とする。 
  // edgeSet := {cost, {i, j}} で格納。

  for(size_t i = 0; i < N; i++) {
    for(size_t j = i + 1; j < N; j++) {
      if(G.find(i, j) != static_cast<size_t>(-1)) continue;
      double cost = distance[i][j];
      assert(degree[i] != 0 and degree[j] != 0);
      cost = cost * degree[i] * degree[j];
      size_t x1 = i % R;
      size_t x2 = j % R;
      size_t y1 = i / R;
      size_t y2 = j / R;
      if((x1 + x2 + y1 + y2) % 2 == 0) {
	cost *= 5;
      }

      edgeCost[i][j] = cost;
      edgeSet.insert({cost, {i, j}});
    }
  }
	
  // edgeSet のなかでコスト最小の辺を取り出す
  // 辺を追加
  // 次数を更新して、edgeSet, edgeCost を更新
  for(; restEdge > 0; restEdge--) {
    size_t u, v;
    std::pair<double, std::pair<size_t, size_t>> firstEdge = *edgeSet.begin();
    std::tie(u, v) = firstEdge.second;
    double cost = firstEdge.first;
    assert(cost == edgeCost[u][v]);
    if(cost == INF) break;
    edgeSet.erase({cost, {u, v}});
    edgeSet.insert({INF, {u, v}});
    edgeCost[u][v] = INF;
    assert(u < v);

    if(degree[u] < MAX_DEGREE and degree[v] < MAX_DEGREE) {
      degree[u]++;
      degree[v]++;
			
      // u, v に隣接している辺に関するコストを再計算
      for(size_t x = 0; x < N; x++) {				
	if(x == u or x == v) continue;
	// 辺 (u, x)
	{
	  size_t a = std::min(u, x);
	  size_t b = std::max(u, x);
	  double curCost = edgeCost[a][b];
	  if(curCost != INF) {
	    assert(edgeSet.find({curCost, {a, b}}) != edgeSet.end());
	    double nxtCost = curCost * degree[u] / (degree[u] - 1);
	    edgeSet.erase({curCost, {a, b}});
	    edgeSet.insert({nxtCost, {a, b}});
	    edgeCost[a][b] = nxtCost;
	  }
	}

	// 辺 (u, x)
	{
	  size_t a = std::min(v, x);
	  size_t b = std::max(v, x);
	  double curCost = edgeCost[a][b];
	  if(curCost != INF) {
	    assert(edgeSet.find({curCost, {a, b}}) != edgeSet.end());
	    double nxtCost = curCost * degree[v] / (degree[v] - 1);
	    edgeSet.erase({curCost, {a, b}});
	    edgeSet.insert({nxtCost, {a, b}});
	    edgeCost[a][b] = nxtCost;
	  }
	}
      }		
	
      edge::cost_type e_cost = ceil(distance[u][v] * SCALE_HIGHWAY);
      if(e_cost == 0) e_cost = 1;
      G.add_edge(u, v, e_cost, (1 << 0));
      G.add_edge(v, u, e_cost, (1 << 0));
    }
  }	
  return G;
}
#endif
