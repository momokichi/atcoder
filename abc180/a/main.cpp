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
    gcd(b, a % b);
}

int lcm(int a, int b) { return abs(a) / gcd(a, b) * abs(b); }

using Graph = vector<vector<int>>;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << n - a + b << endl;
}
