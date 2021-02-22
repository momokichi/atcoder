#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;
typedef long double ld;

const int inf = 1e8;
const ll llinf = 1e18;
const double PI = acos(-1);
#define yes "Yes"
#define no "No"
#define all(n) n.begin(), n.end()

using Edge = pair<ll, ll>;
using Graph = vector<vector<Edge>>;
vector<bool> visited(false), finished(false);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

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

void dijkstra(const Graph &g, int s, vector<ll> &dis, vector<int> &prev) {
  int n = g.size();
  dis.resize(n, llinf);
  prev.resize(n, -1);
  using p = pair<ll, ll>;
  priority_queue<p, vector<p>, greater<p>> pq;
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    p k = pq.top();
    pq.pop();
    int v = k.second;
    if (dis[v] < k.first) continue;

    for (auto &e : g[v]) {
      if (dis[e.first] > dis[v] + e.second) {
        dis[e.first] = dis[v] + e.second;
        prev[e.first] = v;
        pq.emplace(dis[e.first], e.first);
      }
    }
  }
}

vector<int> h(const vector<int> &pre, int t) {
  vector<int> path;
  for (int curr = t; curr != -1; curr = pre[curr]) {
    path.push_back(curr);
  }
  reverse(all(path));
  return path;
}

vector<int> min_cycle;

void f(Graph &g) {
  int V = (int)g.size();
  rep(v, V) {
    ll ans = llinf;
    for (int i = 0; i < (int)g[v].size(); ++i) {
      Edge e = g[v][i];
      g[v].erase(g[v].begin() + i);
      vector<ll> dist;
      vector<int> pre;
      dijkstra(g, e.first, dist, pre);
      if (ans > dist[v] + e.second) {
        ans = dist[v] + e.second;
        min_cycle = h(pre, v);
      }
      g[v].insert((g[v].begin() + i), e);
    }
    if (ans == llinf)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph g(n);

  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
  }
  f(g);
  // cout << fixed << setprecision(9) << ans << endl;
}
