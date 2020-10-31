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
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<int>> c(h, vector<int>(w, 0));
  // 白を0, 黒を1とする。
  int black = 0;
  rep(i, h)
  {
    string s;
    cin >> s;
    rep(j, w)
    {
      if (s[j] == '#')
      {
        c[i][j] = 1;
        black++;
      }
    }
  }

  // rep(i, h)
  // {
  //   rep(j, w)
  //   {
  //     cout << c[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int ans = 0;
  vector<vector<int>> s(h + 1, vector<int>(w + 1, 0));
  rep(i, h)
  {
    rep(j, w)
    {
      s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + c[i][j];
    }
  }
  // cout << "done," << endl;

  for (int x1 = 0; x1 < h + 1; x1++)
  {
    for (int x2 = x1 + 1; x2 < h + 1; x2++)
    {
      for (int y1 = 0; y1 < w + 1; y1++)
      {
        for (int y2 = y1 + 1; y2 < w + 1; y2++)
        {
          printf("x1 %d x2 %d y1 %d y2 %d\n", x1, x2, y1, y2);
          int red = s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
          cout << red << endl;
          if (black - red == k)
            ans++;
        }
      }
    }
  }
  cout << "ans: " << ans << endl;
}
