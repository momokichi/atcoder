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

vector<string> a(2000);
int h, w;
int aoki = 0, takahashi = 0;

void dfs(int x, int y, int turn) {
  if (x >= h || y >= w) return;
  if (x == 0 && y == 0) {
    dfs(x + 1, y, turn);
    dfs(x, y + 1, turn);
  }
}

int main() {
  cin >> h >> w;
  rep(i, h) cin >> a[i];

  dfs(0, 0, 0);

  if (aoki == takahashi)
    cout << "Draw" << endl;
  else if (aoki < takahashi)
    cout << "Takahashi" << endl;
  else if (aoki > takahashi)
    cout << "Aoki" << endl;
  // cout << fixed << setprecision(9) << ans << endl;
}
