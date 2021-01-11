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

void warshall_floyd(int n, vector<vector<int>> d) {
  rep(k, n) {
    rep(i, n) {
      rep(j, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    }
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  int n = 10;
  vector<vector<int>> v(n, vector<int>(n, 0));
  rep(i, n) rep(j, n) cin >> v[i][j];

  rep(k, n) {
    rep(i, n) {
      rep(j, n) { v[i][j] = min(v[i][j], v[i][k] + v[k][j]); }
    }
  }

  ll ans = 0;
  rep(i, h) {
    rep(j, w) {
      int a;
      cin >> a;
      if (a == -1) continue;
      ans += v[a][1];
    }
  }
  cout << ans << endl;
  // cout << fixed << setprecision(9) << ans << endl;
}
