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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> ans(n, 0);
  for (int i = 1; i < n; ++i)
  {
    for (int j = i + 1; j <= n; j++)
    {
      int dist = min(j - i, abs(i - x) + abs(j - y) + 1);
      ans[dist]++;
    }
  }
  for (int i = 1; i < n; i++)
    cout << ans[i] << endl;
}
