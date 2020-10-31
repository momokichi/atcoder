#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  int ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 1; j < w; ++j) {
      char prev = s[i][j - 1];
      char now = s[i][j];
      if (prev == '.' && now == '.') ans++;
    }
  }
  for (int i = 1; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char prev = s[i - 1][j];
      char now = s[i][j];
      if (prev == '.' && now == '.') ans++;
    }
  }
  cout << ans << endl;
}
