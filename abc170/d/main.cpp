#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;

int main()
{
  int n, nn;
  cin >> n;
  nn = n;
  vector<int> a;
  while (nn--)
  {
    int input;
    cin >> input;
    a.push_back(input);
  }

  int count = 0;
  sort(a.begin(), a.end(), greater<>());

  for (int i = 0; i < n - 1; i++)
  {
    bool flag = true;
    for (int j = i + 1; j < n; j++)
    {
      cout << a[i] << " % " << a[j] << endl;
      if (a[i] % a[j] == 0)
      {
        cout << i << " " << j << endl;
        flag = false;
        break;
      }
    }
    if (flag)
    {
      count++;
    }
  }
  cout << count << endl;
}
