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
  int hoge;
  cin >> hoge;
  int ans[10050] = {0};

  for (int x = 1; x * x <= 10050; ++x)
  {
    for (int y = 1; y * y <= 10050; ++y)
    {
      for (int z = 1; z * z <= 10050; ++z)
      {
        int a = pow(x, 2) + pow(y, 2) + pow(z, 2) + x * y + y * z + z * x;
        if (a <= 10010)
          ans[a]++;
      }
    }
  }

  for (int i = 1; i <= hoge; ++i)
    cout << ans[i] << endl;
  // cout << i << " " << ans[i] << endl;
}
