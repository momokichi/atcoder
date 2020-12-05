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
  string s;
  cin >> s;
  int n = 3;
  for (int bit = 0; bit < (1 << n); ++bit) {
    // cout << bit << endl;
    // cout << bitset<3>(bit) << endl;
    int ans = s[0] - '0';
    int index = 1;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i))
        ans += s[index] - '0';
      else
        ans -= s[index] - '0';
      index++;
    }
    // cout << ans << endl;
    if (ans == 7) {
      for (int i = 0; i < n; ++i) {
        cout << s[i];
        if (bit & (1 << i))
          cout << '+';
        else
          cout << '-';
      }
      cout << s[3] << "=7" << endl;
      return 0;
    }
  }
  // cout << fixed << setprecision(9) <<  << endl;
}
