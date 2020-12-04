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
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> s(n + 1, 0);
  rep(i, n) s[i + 1] = s[i] + a[i];

  rep(i, n + 1) cout << s[i] << endl;
  auto itr = find_if(s.begin(), s.end(), [](int x) { return x < 0; });
  if (itr == s.end()) {
    ll ans = 0;
    rep(i, n + 1) ans += s[i];
    cout << ans << endl;
    return 0;
  } else {
    ll index = distance(s.begin(), itr);
    ll ans = 0;
    rep(i, index) ans += s[i];
    rep(i, index) {
      ll b = ans;
      b += a[i];
      ans = max(ans, b);
    }
    cout << ans << endl;
    return 0;
  }
}
