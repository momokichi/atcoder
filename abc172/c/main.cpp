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
  ll n, m, k;
  cin >> n >> m >> k;
  queue<ll> a, b;
  rep(i, n)
  {
    ll input;
    cin >> input;
    a.push(input);
  }
  rep(i, m)
  {
    ll input;
    cin >> input;
    b.push(input);
  }

  ll ans = 0;
  ll time = 0;
  while (time < k)
  {
    if (!a.empty() && !b.empty())
    {
      if (a.front() <= b.front())
      {
        time += a.front();
        a.pop();
        if (time <= k)
          ans++;
      }
      else
      {
        time += b.front();
        b.pop();
        if (time <= k)
          ans++;
      }
    }
    else if (a.empty() && !b.empty())
    {
      time += b.front();
      b.pop();
      if (time <= k)
        ans++;
    }
    else if (b.empty() && !a.empty())
    {
      time += a.front();
      a.pop();
      if (time <= k)
        ans++;
    }
    else if (a.empty() && b.empty())
    {
      break;
    }
  }

  cout << ans << endl;
}
