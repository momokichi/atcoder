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

template <class T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

struct UnionFind {
  vector<int> par, siz;
  UnionFind(int n) : par(n, -1), siz(n, 1) {}
  int root(int x) {
    if (par[x] == -1) return x;
    return par[x] = root(par[x]);
  }
  bool isSame(int x, int y) { return root(x) == root(y); }
  bool unite(int x, int y) {
    x = root(x), y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }
  int size(int x) { return siz[root(x)]; }
};

using Graph = vector<vector<int>>;
vector<int> visited;

void dfs(const Graph &G, int v, int depth) {
  visited[v] = min(visited[v], depth);
  for (auto next : G[v]) {
    if (visited[next] != inf) continue;
    dfs(G, next, depth + 1);
  }
}

int main() {
  int n;
  cin >> n;
  Graph g(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  visited.assign(n, inf);
  dfs(g, 0, 0);

  auto itr = max_element(all(visited));
  int index = distance(visited.begin(), itr);

  visited.assign(n, inf);
  dfs(g, index, 0);

  auto ans = max_element(all(visited));

  cout << *ans + 1 << endl;

  // cout << fixed << setprecision(9) << ans << endl;
}
