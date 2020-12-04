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

int main() {
  long double n;
  cin >> n;

  // ll x = floor((-1 + sqrt(1 + 4 * (2 * n + 2))) / 2);
  // cout << to_string(2 * n + 2.25) << endl;
  ll x = floor(sqrt(2 * n + 2.25) - 0.5);

  ll ans = n + 1 - x;

  cout << ans << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}
