#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = (n / (a + b)) * a;
  if ((n % (a + b)) >= a)
    ans += a;
  else
    ans += (n % (a + b));
  cout << ans << endl;
}
