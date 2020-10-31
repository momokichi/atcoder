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

using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  ll man = 0;
  rep(i, n) { man += abs(x[i]); }
  long double yuku = 0;
  rep(i, n) { yuku += abs(x[i]) * abs(x[i]); }
  yuku = sqrt(yuku);
  ll cheb = 0;
  rep(i, n) { cheb = max(abs(x[i]), cheb); }
  cout << man << endl;
  cout << fixed << setprecision(15) << yuku << endl;
  cout << cheb << endl;
}
