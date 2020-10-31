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
  ll k, n;
  cin >> k >> n;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  ll ans = 0;
  rep(i, n - 1)
  {
    ans = max(ans, a[i + 1] - a[i]);
  }
  ans = max(ans, k - a[a.size() - 1] + a[0]);
  cout << k - ans << endl;
}
