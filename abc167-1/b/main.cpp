#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int sum = 0;
  while (k != 0)
  {
    if (a > 0)
    {
      a--;
      sum++;
    }
    else if (b > 0)
    {
      b--;
    }
    else if (c > 0)
    {
      c--;
      sum--;
    }
    k--;
  }
  cout << sum;
}