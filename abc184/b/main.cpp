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
  int n, x;
  string s;
  cin >> n >> x >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      x++;
    } else {
      if (x > 0) x--;
    }
  }
  cout << x << endl;
}
