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
  double sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  double x;
  x = ((gx - sx) * (-sy) / (-gy - sy)) + sx;
  cout << std::fixed << std::setprecision(15) << x << endl;
}