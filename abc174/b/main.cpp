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
  int n;
  double d;
  cin >> n >> d;
  int ans = 0;
  while (n--)
  {
    ll x, y;
    cin >> x >> y;
    double dist = sqrt(x * x + y * y);
    // cout << dist << endl;
    if (dist <= d)
      ans++;
  }
  cout << ans << endl;
}
