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
  int l, r, d;
  cin >> l >> r >> d;
  int ans = 0;
  for (int i = l; i <= r; ++i)
  {
    if (i % d == 0)
      ans++;
  }
  cout << ans << endl;
}
