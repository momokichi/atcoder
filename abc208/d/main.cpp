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

struct E {
  ll to, cost;
};

using Graph = vector<vector<E>>;
vector<ll> c;

int n, m;
ll ans = 0;

ll d(const Graph& G, ll s, ll t, ll k) {
  c.assign(n, llinf);
  c[s] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.emplace(0, s);
  while (!pq.empty()) {
    pair<ll, ll> p = pq.top();
    pq.pop();
    ll v = p.second;
    // if (p.second > k) continue;
    if (c[v] < p.first) continue;
    for (auto& e : G[v]) {
      if (c[e.to] > c[v] + e.cost) {
        if (e.to != t && e.to > k) continue;
        c[e.to] = c[v] + e.cost;
        pq.emplace(c[e.to], e.to);
      }
    }
  }
  return (c[t] == llinf ? 0 : c[t]);
}

int main() {
  cin >> n >> m;
  Graph g(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
  }
  vector<vector<ll>> tmp(n, vector<ll>(n, 0));
  for (int s = 0; s < n; s++) {
    for (int t = s + 1; t < n; t++) {
      rep(k, n) {
        ll a = d(g, s, t, k);
        tmp[s][t] = a;
        ans += a;
      }
    }
  }
  // d(g, 0);
  cout << ans << endl;
  // cout << fixed << setprecision(9) << ans << endl;
}
