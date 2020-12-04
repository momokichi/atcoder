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
int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<vector<ll>> t(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> t[i][j];
  ll ans = 0;
  vector<int> v(n);
  iota(v.begin(), v.end(), 1);
  do {
    if (v[0] == 1) {
      ll tmp = 0;
      for (int i = 0; i < n - 1; i++) {
        tmp += t[v[i] - 1][v[i + 1] - 1];
      }
      tmp += t[v[n - 1] - 1][0];

      if (tmp == k) ans++;
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << ans << endl;
}
