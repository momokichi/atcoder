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
  string n;
  cin >> n;
  vector<int> num(10);
  int sum = 0;
  rep(i, n.length()) {
    num[n[i] - '0']++;
    sum += n[i];
  };

  if (sum % 3 == 0) {
    cout << '0' << endl;
    return 0;
  }

  int ans = 18;
  for (int x = 2; x < 163; x++) {
    if (x % 3 == 0) {
      int a = x - sum;
    }
  }

  if (ans == 18) {
    cout << "-1" << endl;
    return 0;
  }

  cout << ans << endl;
}
