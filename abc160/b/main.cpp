#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main()
{
  ll x;
  cin >> x;
  ll ans = 0;
  if (x >= 500)
  {
    ans = 1000 * (x / 500);
    x -= 500 * (x / 500);
  }
  if (x >= 5)
  {
    ans += 5 * (x / 5);
  }
  cout << ans << endl;
}
