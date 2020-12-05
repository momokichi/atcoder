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
  int a, b;
  cin >> a >> b;
  int n;
  cin >> n;
  rep(i, n) {
    int c, d;
    cin >> c >> d;
    bool x = (a <= c) && (b <= d);
    bool y = (a <= d) && (b <= c);
    bool z = (c * c + d * d >= a * a + b * b);
    if (x || y || z)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  // cout << fixed << setprecision(9) <<  << endl;
}
