#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;
typedef long double ld;

const int inf = 1e8;
const ll llinf = 1e18;
const double PI = acos(-1);
#define yes "Yes"
#define no "No"
#define all(n) n.begin(), n.end()

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

string f(int direction) {
  switch (direction) {
    case 0:
      return "D";
    case 1:
      return "R";
    case 2:
      return "U";
    case 3:
      return "L";
  }
}

int main() {
  int si, sj;
  cin >> si >> sj;
  int n = 50;
  vector<vector<int>> t(n, vector<int>(n, 0));
  vector<vector<int>> p(n, vector<int>(n, 0));
  rep(i, n) rep(j, n) cin >> t[i][j];
  rep(i, n) rep(j, n) cin >> p[i][j];

  vector<bool> visited(n, false);

  ll point = 0;
  string route = "";

  int curri = si, currj = sj;

  if (si < n / 2) {
    if (sj < n / 2) {
      // 左上
      while (!(curri == n - 1 || currj == n - 1)) {
        if (t[curri][currj] == t[curri][currj + 1]) {
          route += 'D';
          curri++;
        } else {
          route += 'R';
          currj++;
        }
      }
    } else {
      // 右上
      while (!(curri == n - 1 || currj == 0)) {
        if (t[curri][currj] == t[curri][currj - 1]) {
          route += 'D';
          curri++;
        } else {
          route += 'L';
          currj--;
        }
      }
    }
  } else {
    if (sj < n / 2) {
      // 左下
      while (!(curri == 0 || currj == n - 1)) {
        if (t[curri][currj] == t[curri][currj + 1]) {
          route += 'U';
          curri--;
        } else {
          route += 'R';
          currj++;
        }
      }
    } else {
      // 右下
      while (!(curri == 0 || currj == 0)) {
        if (t[curri][currj] == t[curri][currj - 1]) {
          route += 'U';
          curri--;
        } else {
          route += 'L';
          currj--;
        }
      }
    }
  }

  cout << route << endl;
  // cout << fixed << setprecision(9) << ans << endl;
}
