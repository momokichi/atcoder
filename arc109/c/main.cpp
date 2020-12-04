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

char vs(char a, char b) {
  if (a == b) return a;

  if (a == 'R')
    return b == 'S' ? a : b;
  else if (a == 'P')
    return b == 'R' ? a : b;
  else if (a == 'S')
    return b == 'P' ? a : b;
}

int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;

  // cout << fixed << setprecision(9) <<  << endl;
}
