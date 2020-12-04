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
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int i = 0;
  while (i < n - 2) {
    if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'x') {
      string t = s.substr(0, i) + s.substr(i + 3, n - i - 3);
      n -= 3;
      s.swap(t);
      i -= 3;
    }
    ++i;
  }
  printf("%d\n", n);
}
