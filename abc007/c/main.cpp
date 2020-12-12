#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
vector<int> visited(false);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(const Graph &G, int v) {
  visited[v] = true;
  for (auto next : G[v]) {
    if (visited[next]) continue;
    dfs(G, next);
  }
}

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int lcm(int a, int b) { return abs(a) / gcd(a, b) * abs(b); }

vector<ll> divisors(ll n) {
  vector<ll> a;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      a.push_back(i);
      if (n / i != i) a.push_back(n / i);
    }
  }
  sort(a.begin(), a.end());
  return a;
}

// pairを要素に持つvectorをsecondを基準にソートする比較関数
bool comp(pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; }

int main() {
  int r, c;
  cin >> r >> c;
  pair<int, int> start;
  pair<int, int> goal;
  cin >> start.first >> start.second >> goal.first >> goal.second;
  start.first--, start.second--, goal.first--, goal.second--;

  vector<string> f(r);
  rep(i, r) { cin >> f[i]; }

  vector<vector<int>> dist(r, vector<int>(c, -1));
  dist[start.first][start.second] = 0;

  queue<pair<int, int>> que;
  que.push(start);

  while (!que.empty()) {
    pair<int, int> current = que.front();
    que.pop();

    int x = current.first;
    int y = current.second;

    for (int direction = 0; direction < 4; ++direction) {
      int next_x = x + dx[direction];
      int next_y = y + dy[direction];
      if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c) continue;
      if (f[next_x][next_y] == '#') continue;

      if (dist[next_x][next_y] == -1) {
        que.push(make_pair(next_x, next_y));
        dist[next_x][next_y] = dist[x][y] + 1;
      }
    }
  }

  cout << dist[goal.first][goal.second] << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}
