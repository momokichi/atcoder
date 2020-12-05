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

char a[10][10];
bool reached[10][10];

int count() {
  int num = 0;
  rep(i, 10) {
    rep(j, 10) {
      if (reached[i][j]) num++;
    }
  }
  return num;
}

void init() {
  rep(i, 10) {
    rep(j, 10) { reached[i][j] = false; }
  }
}

void dfs(int x, int y) {
  if (x < 0 || x >= 10 || y < 0 || y >= 10) return;
  if (a[x][y] == 'x') return;

  if (reached[x][y]) return;

  reached[x][y] = true;

  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}

int main() {
  int num = 0;
  rep(i, 10) {
    rep(j, 10) {
      cin >> a[i][j];
      if (a[i][j] == 'o') num++;
    }
  }

  // rep(i, 10) {
  //   rep(j, 10) { cout << a[i][j]; }
  //   cout << endl;
  // }

  rep(i, 10) {
    rep(j, 10) {
      init();
      char t = a[i][j];
      a[i][j] = 'o';
      dfs(i, j);
      a[i][j] = t;

      if (count() == num + 1) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;

  // cout << fixed << setprecision(9) <<  << endl;
}
