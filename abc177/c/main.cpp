#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long int ll;
const ll m = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; j++) {
      ans += (a[i] * a[j]);
      ans %= m;
    }
  }
  printf("%lld\n", ans);
}
