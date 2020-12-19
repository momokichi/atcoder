#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

int main()
{
  ll k;
  cin >> k;
  if (k % 2 == 0)
  {
    cout << "-1" << endl;
    return 0;
  }
  ll a = 7;
  for (int i = 0; i <= k; ++i)
  {
    a %= k;
    if (a == 0)
    {
      cout << i + 1 << endl;
      return 0;
    }
    a = a * 10 + 7;
  }
  cout << "-1" << endl;
}
