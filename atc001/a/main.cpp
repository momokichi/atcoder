#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

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

int h, w;
const int maxH = 500, maxW = 500;
char c[maxH][maxW];

bool reached[maxH][maxW];

void dfs(int x, int y) {
  if (x < 0 || x >= h || y < 0 || y >= w) return;
  if (c[x][y] == '#') return;

  if (reached[x][y]) return;

  reached[x][y] = true;

  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}

int main() {
  cin >> h >> w;
  pair<int, int> start, goal;
  rep(i, h) {
    rep(j, w) {
      cin >> c[i][j];
      if (c[i][j] == 's') start = make_pair(i, j);
      if (c[i][j] == 'g') goal = make_pair(i, j);
    }
  }
  // cout << start.first << " " << start.second << endl;
  // cout << goal.first << " " << goal.second << endl;

  dfs(start.first, start.second);

  if (reached[goal.first][goal.second])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  // cout << fixed << setprecision(9) <<  << endl;
}
