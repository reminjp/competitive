#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

constexpr int W = 20, H = 20;
constexpr int NODE_COUNT = H * W;
constexpr int EDGE_COUNT = (2 * W - 1) * H - W;

const string TOKEN = "18e91e7bf2abe2e42daf000675f41f6b";
const string API_URL = "https://contest.gbc-2020.tenka1.klab.jp/api";
constexpr int CLAIM_TIME_LIMIT = 4000;

std::string HttpGet(std::string url) {
  FILE *f = popen(("curl -sk \"" + url + "\"").c_str(), "r");
  if (f == nullptr) perror("error");
  char buffer[1024];
  std::string response;
  while (!feof(f)) {
    if (fgets(buffer, 1024, f) == NULL) break;
    response += (std::string)(buffer);
  }
  pclose(f);
  return response;
}

struct Game {
  int id, t;
};

struct Stage {
  int n;
  vector<vector<int>> v, a, b;
};

void get_game(Game &game) {
  stringstream ss;
  ss << HttpGet(API_URL + "/game");
  ss >> game.id >> game.t;
}

void get_stage(int game_id, Stage &stage) {
  stringstream ss;
  ss << HttpGet(API_URL + "/stage/" + to_string(game_id));
  int n;
  ss >> n;
  if (n != stage.n) {
    stage.n = n;
    stage.v = vector<vector<int>>(n, vector<int>(n));
    stage.a = vector<vector<int>>(n, vector<int>(n));
    stage.b = vector<vector<int>>(n, vector<int>(n));
  }
  for (auto &row : stage.v) {
    for (auto &e : row) ss >> e;
  }
  for (auto &row : stage.a) {
    for (auto &e : row) e = 0;
  }
  for (auto &row : stage.b) {
    for (auto &e : row) e = 0;
  }
}

void get_areas(int game_id, Stage &stage) {
  stringstream ss;
  ss << HttpGet(API_URL + "/areas/" + TOKEN + "/" + to_string(game_id));
  string _;
  ss >> _;
  for (auto &row : stage.a) {
    for (auto &e : row) ss >> e;
  }
  for (auto &row : stage.b) {
    for (auto &e : row) ss >> e;
  }
}

string get_claim(int game_id, int y, int x, int size) {
  stringstream ss;
  ss << HttpGet(API_URL + "/claim/" + TOKEN + "/" + to_string(game_id) + "/" + to_string(y) + "-" + to_string(x) + "-" +
                to_string(size));
  string response;
  ss >> response;
  return response;
}

int calculate_time_to_claim(int size) { return (size + 1) * (size + 1) * 125; }

int main() {
  Game game{-1, 0};
  Stage stage;

  int next_claim_time = 1e9;

  while (true) {
    {
      auto prev_game = game;
      get_game(game);

      if (game.id == -1) break;
      if (prev_game.id == -1 || prev_game.id != game.id) {
        cerr << "game " << game.id << endl;
        get_stage(game.id, stage);

        next_claim_time = 1e9;
      }
    }

    auto prev_stage = stage;
    get_areas(game.id, stage);

    vector<vector<double>> s(stage.n, vector<double>(stage.n));
    for (int y = 0; y < stage.n; y++) {
      for (int x = 0; x < stage.n; x++) {
        // double d = pow(stage.v[y][x], 2.0) / pow(1000, 2.0) * 50;
        double d = (double)stage.v[y][x] / 1000 * 50;
        s[y][x] = stage.v[y][x] / max(20.0, d);
      }
    }

    int y_claim = 0, x_claim = 0, size_claim = 1;
    double m = 0;
    for (int y = 0; y < stage.n; y++) {
      for (int x = 0; x < stage.n; x++) {
        for (int size = 1; size < min(stage.n - y, stage.n - x); size++) {
          int c = 0;
          double t = 1e9;

          for (int i = y; i < y + size; i++) {
            for (int j = x; j < x + size; j++) {
              if (prev_stage.b[i][j] || stage.b[i][j]) continue;
              c++;
              t = min(t, s[i][j]);
            }
          }
          if (t < 10.0) continue;
          t *= c;
          t /= calculate_time_to_claim(size);

          if (t > m) {
            m = t;
            y_claim = y;
            x_claim = x;
            size_claim = size;
          }
        }
      }
    }

    for (int y = y_claim; y < y_claim + size_claim; y++) {
      for (int x = x_claim; x < x_claim + size_claim; x++) {
        stage.b[y][x] = 1;
      }
    }

    {
      Game g;
      auto pg = g;
      get_game(g);
      if (pg.id != g.id) continue;

      if (g.t > next_claim_time) {
        usleep(1000 * (g.t - next_claim_time));
      }
      next_claim_time = min(next_claim_time, g.t);
      next_claim_time -= calculate_time_to_claim(size_claim);
    }

    cerr << y_claim << " " << x_claim << " " << size_claim << " ... ";
    auto response = get_claim(game.id, y_claim, x_claim, size_claim);
    cerr << response << endl;
    if (response == "game_finished") next_claim_time = 1e9;
  }
}
