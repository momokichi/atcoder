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
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  map<ll, ll> b;
  rep(i, n) b[a[i]]++;
  ll ans = 0;
  for (auto x : b)
    ans += x.second * (x.second - 1) / 2;
  rep(i, n)
  {
    ll before = b[a[i]] * (b[a[i]] - 1) / 2;
    ll after = (b[a[i]] - 1) * (b[a[i]] - 2) / 2;
    cout << ans - (before - after) << endl;
  }
}
