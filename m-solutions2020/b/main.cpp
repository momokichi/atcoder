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
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  while (a >= b)
  {
    b *= 2;
    k--;
  }
  while (b >= c)
  {
    c *= 2;
    k--;
  }

  if (k >= 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
