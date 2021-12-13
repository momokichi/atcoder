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
vector<int> visited(false);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> points(n, 0);
  rep(i, n) {
    rep(j, 3) {
      int t = 0;
      cin >> t;
      points[i] += t;
    }
  }

  vector<int> t = points;
  sort(all(t));

  rep(i, n) {
    auto itr = upper_bound(all(t), points[i] + 300);
    int index = distance(t.begin(), itr);
    index = n - index;
    if (index < k)
      cout << yes << endl;
    else
      cout << no << endl;
  }
  // cout << fixed << setprecision(9) << ans << endl;
}
