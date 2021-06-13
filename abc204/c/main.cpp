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

using Graph = vector<vector<int>>;
vector<int> visited(false);
ll ans = 0;

void dfs(const Graph &G, int v) {
  visited[v] = true;
  for (auto next : G[v]) {
    if (visited[next]) continue;
    ans++;
    dfs(G, next);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }

  rep(i, n) {
    visited.assign(n, 0);
    dfs(g, i);
  }

  cout << ans + n << endl;
  // cout << fixed << setprecision(9) << ans << endl;
}
