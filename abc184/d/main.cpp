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

map<tuple<double, double, double>, double> memo;

double solve(double a, double b, double c) {
  int total = a + b + c;
  if (a == 100 || b == 100 || c == 100) return 0.0;

  tuple<double, double, double> t = make_tuple(a, b, c);

  auto itr = memo.find(t);
  if (itr != memo.end()) return memo[t];

  return memo[t] = ((a / total) * (solve(a + 1, b, c) + 1)) +
                   ((b / total) * (solve(a, b + 1, c) + 1)) +
                   ((c / total) * (solve(a, b, c + 1) + 1));
}

int main() {
  double a, b, c;
  cin >> a >> b >> c;

  double ans = solve(a, b, c);

  cout << fixed << setprecision(9) << ans << endl;
}
