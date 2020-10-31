#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  if (abs(k * d) <= abs(x)) {
    cout << abs(x) - abs(d * k) << endl;
    return 0;
  }

  if ((k - (x / d)) % 2 == 0) {
    cout << abs(abs(x) - abs((x / d) * k)) << endl;
  } else
    cout << abs(abs(x) - abs((x / d + 1) * k)) << endl;
}
