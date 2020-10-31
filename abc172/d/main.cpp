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
  typedef pair<ll, ll> Factor;
  ll m;
  cin >> m;
  ll k = m;
  vector<Factor> v;
  while (k > 0)
  {
    ll n = k;
    vector<Factor> factor;
    for (ll i = 2; i * i <= n; i++)
    {
      if (n % i != 0)
        continue;
      ll exp = 0;
      while (n % i == 0)
      {
        exp++;
        n /= i;
      }
      factor.push_back(Factor(i, exp));
    }
    if (n != 1)
      factor.push_back(Factor(n, 1));

    // cout << "n: " << k << endl;
    ll num = 1;
    for (auto x : factor)
    {
      // cout << x.first << " " << x.second << endl;
      num *= x.second + 1;
    }
    // cout << num << endl;
    v.push_back(Factor(k, num));
    k--;
  };
  ll ans = 0;
  for (auto x : v)
  {
    ans += x.first * x.second;
  }
  cout << ans << endl;
}
