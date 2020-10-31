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
  ll n;
  cin >> n;
  for (int a = 0; a <= 30; ++a) {
    for (int b = 0; b <= 27; ++b) {
      ll A = pow(3, a);
      ll B = pow(5, b);
      cout << A + B << endl;
      cout << A << " " << B << endl;
      // if (pow(3, a) + pow(5, b) == n) {
      //   cout << a << " " << b << endl;
      //   return 0;
      // }
    }
  }
  cout << "-1" << endl;
}
