#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  rep(i, n) { cin >> p[i]; };
  ll num = 0;
  for (int i = 0; i < n; i++) {
    if (num < p[i]) {
      cout << p[i] + 1 << endl;
      num = p[i];
    } else {
      cout << num << endl;
    }
  }
}
