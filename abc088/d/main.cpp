#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
typedef long double ld;

const double PI = acos(-1);
#define yes "Yes"
#define no "No"

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

bool isPrime(ll n) {
  if (n < 2) return false;
  for (ll i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}

// 最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数
ll lcm(ll a, ll b) { return abs(a) / gcd(a, b) * abs(b); }

ll gcd2(const vector<ll> &v) {
  ll val = v[0];
  for (ll i = 1; i < v.size(); ++i) val = gcd(val, v[i]);
  return val;
}

ll lcm2(const vector<ll> &v) {
  ll val = v[0];
  for (ll i = 1; i < v.size(); ++i) val = lcm(val, v[i]);
  return val;
}

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
  int h, w;
  cin >> h >> w;
  int black = 0, white = 0;
  vector<string> s(h);
  rep(i, h) {
    string t;
    cin >> t;
    rep(j, w) if (t[j] == '#') black++;
    s[i] = t;
  }

  white = h * w - black;

  vector<vector<int>> dist(h, vector<int>(w, -1));
  dist[0][0] = 0;

  queue<pair<int, int>> que;
  que.push({0, 0});

  while (!que.empty()) {
    pair<int, int> current = que.front();
    que.pop();

    int x = current.first;
    int y = current.second;

    for (int direction = 0; direction < 4; ++direction) {
      int next_x = x + dx[direction];
      int next_y = y + dy[direction];
      if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) continue;
      if (s[next_x][next_y] == '#') continue;

      if (dist[next_x][next_y] == -1) {
        que.push({next_x, next_y});
        dist[next_x][next_y] = dist[x][y] + 1;
      }
    }
  }

  int ans = dist[h - 1][w - 1] == -1 ? -1 : (white - (dist[h - 1][w - 1] + 1));

  cout << ans << endl;

  // rep(i, h + 2) cout << s[i] << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}
