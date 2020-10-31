#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

int main()
{
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  a[0] = -1;
  for (int i = 1; i <= n; ++i)
  {
    int tmp;
    cin >> tmp;
    a[i] = tmp;
  }
  int b[n + 1];
  b[0] = -1;

  while (k--)
  {
    for (int i = 1; i <= n; ++i)
    {
      int count = 0;
      for (int j = 1; j <= n; ++j)
      {
        double left, right;
        left = j - a[j] - 0.5;
        right = j + a[j] + 0.5;
        if (left <= i && i <= right)
          count++;
      }
      b[i] = count;
    }
    for (int i = 1; i <= n; ++i)
    {
      a[i] = b[i];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}
