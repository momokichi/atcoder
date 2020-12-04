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
  ll a, b, c;
  cin >> a >> b >> c;
  ll sa = (a * (a + 1) / 2) % 998244353;
  ll sb = (b * (b + 1) / 2) % 998244353;
  ll sc = (c * (c + 1) / 2) % 998244353;

  ll ans = (((sa * sb) % 998244353) * sc) % 998244353;
  cout << ans << endl;
}