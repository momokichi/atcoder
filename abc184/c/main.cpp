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
  ll r1, r2, c1, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  pair<ll, ll> start = make_pair(r1, c1);
  pair<ll, ll> goal = make_pair(r2, c2);
  ll ans = 0;

  cout << ans << endl;
}