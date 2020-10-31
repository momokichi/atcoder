#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main()
{
  unsigned long long a;
  long double b;
  cin >> a >> b;

  unsigned long long ans = a * floor(b * 100) / 100;
  cout << ans << endl;
}
