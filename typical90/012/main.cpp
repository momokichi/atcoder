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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int h, w;

bool g[2002][2002];
vector<vector<bool>> visited;

int ra, ca, rb, cb;

void dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= h || y >= w) return;
  if (g[x][y] == false) return;
  if (visited[x][y]) return;
  if (g[x][y] == false) return;

  visited[x][y] = true;  // 現在地を訪問済みにする
  if (x == rb && y == cb) return;

  for (int direction = 0; direction < 4; ++direction) {
    dfs(x + dx[direction], y + dy[direction]);
  }
}

int main() {
  cin >> h >> w;
  ll q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int r, c;
      cin >> r >> c;
      r--, c--;
      g[r][c] = true;
    } else if (t == 2) {
      cin >> ra >> ca >> rb >> cb;
      ra--, ca--, rb--, cb--;
      bool f1 = g[ra][ca] && g[rb][cb];
      visited.assign(2002, vector<bool>(2002, false));
      dfs(ra, ca);
      bool f2 = visited[rb][cb];

      if (f1 && f2)
        cout << yes << endl;
      else
        cout << no << endl;
    }
  }
  // cout << fixed << setprecision(9) << ans << endl;
}
