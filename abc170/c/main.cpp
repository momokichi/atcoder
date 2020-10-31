#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;

int main()
{
  int x, n;
  cin >> x >> n;
  vector<int> p;
  while (n--)
  {
    int input;
    cin >> input;
    p.push_back(input);
  }
  sort(p.begin(), p.end());

  int minimum = 9999;
  for (int i = -100; i <= 200; ++i)
  {
    // cout << i << endl;
    if (find(p.begin(), p.end(), i) == p.end())
    {
      // cout << i << "is not exited" << endl;
      if (abs(minimum - x) > abs(i - x))
      {
        minimum = i;
        // cout << i << "updated" << endl;
      }
    }
  }
  cout << minimum << endl;
}
