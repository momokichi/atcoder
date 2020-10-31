#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long ll;
const double PI = acos(-1);

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int lcm(int a, int b) { return abs(a) / gcd(a, b) * abs(b); }

using Graph = vector<vector<int>>;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<ll> c(m);
  vector<ll> d(m);
  rep(i, m) cin >> c[i] >> d[i];

  vector<ll> e(n);
  rep(i, n) e[i] = b[i] - a[i];
  // rep(i, n) cout << e[i] << endl;

  ll x = 0;
  for (int i = 0; i < m; i++) {
    x += e[c[i] - 1] + e[d[i] - 1];
  }
  // cout << x << endl;
  if (x == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
