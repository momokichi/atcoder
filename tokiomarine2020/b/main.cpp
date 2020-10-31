#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;

int main()
{
  ll a, v, b, w, t;
  cin >> a >> v;
  cin >> b >> w;
  cin >> t;
  // printf("%d %d %d %d %d", a, v, b, w, t);

  ll x = abs(a - b);
  ll y = (v - w) * t;
  // cout << result << endl;

  if (x <= y)
  {
    cout << "YES" << endl;
  }
  else
    cout << "NO" << endl;
}
