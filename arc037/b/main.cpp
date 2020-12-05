#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
vector<int> visited(false);
vector<int> used(false);

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

bool loop;

void dfs(const Graph &G, int v) {
  visited[v] = true;
  for (auto next : G[v]) {
    if (visited[next]) {
      loop = true;
      continue;
    };
    dfs(G, next);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph g(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
  }

  int ans = 0;
  visited.assign(n, false);

  rep(v, n) {
    loop = false;
    if (visited[v]) continue;
    dfs(g, v);
    if (!loop) ans++;
  }
  cout << ans << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}
