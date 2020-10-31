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
  int k;
  cin >> k;
  vector<ll> v;
  for (int i = 1; i < 10; i++)
    v.push_back(i);
  while (1)
  {
    if (k <= v.size())
    {
      cout << v[k - 1] << endl;
      return 0;
    }
    k -= v.size();
    vector<ll> prev = v;
    v.clear();
    for (auto x : prev)
    {
      for (int i = -1; i < 2; i++)
      {
        int d = x % 10 + i;
        if (d < 0 || d > 9)
          continue;
        ll n = x * 10 + d;
        v.push_back(n);
      }
    }
  }
}
