#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];
  ll ans = 0;
  ll h = a[0];
  for (ll i = 1; i < n; i++) {
    if (a[i] < h) {
      ans += h - a[i];
    } else
      h = a[i];
  }
  cout << ans << endl;
}
