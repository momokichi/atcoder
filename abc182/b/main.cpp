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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int count = 0;
  int ans = 0;
  for (int k = 2; k <= 1000; k++) {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] % k == 0) tmp++;
    }
    if (count < tmp) {
      ans = k;
      count = tmp;
    }
  }
  cout << ans << endl;
}
