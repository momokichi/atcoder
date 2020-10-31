#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main()
{
  int n;
  cin >> n;
  unsigned long long a[n];
  for (int i = 0; i < n; i++)
  {
    unsigned long long tmp;
    cin >> tmp;
    a[i] = tmp;
  }

  sort(a, a + sizeof(a) / sizeof(a[0]));

  unsigned long long ans = a[0];
  unsigned long long cmp = 1000000000000000000;

  bool flag = true;

  for (int i = 1; i < n; i++)
  {
    if (ans > cmp / a[i])
    {
      cout << "-1" << endl;
      flag = false;
      break;
    }
    else
    {
      ans *= a[i];
    }
  }

  if (flag)
    cout << ans << endl;
}
