#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;

int main()
{
  int x, y;
  cin >> x >> y;
  for (int a = 0; a <= x; ++a)
  {
    for (int b = 0; b <= x; ++b)
    {
      if (a + b == x && 2 * a + 4 * b == y)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
