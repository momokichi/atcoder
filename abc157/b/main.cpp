#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  int a[3][3];
  rep(i, 3) {
    rep(j, 3) { cin >> a[i][j]; }
  }

  int n;
  cin >> n;

  rep(k, n) {
    int b;
    cin >> b;
    rep(i, 3) {
      rep(j, 3) {
        if (b == a[i][j]) {
          a[i][j] = -1;
        }
      }
    }
  }
  rep(i, 3) {
    if (a[0][i] == -1 && a[1][i] == -1 && a[2][i] == -1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  rep(i, 3) {
    if (a[i][0] == -1 && a[i][1] == -1 && a[i][2] == -1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (a[0][0] == -1 && a[1][1] == -1 && a[2][2] == -1) {
    cout << "Yes" << endl;
    return 0;
  }
  if (a[0][2] == -1 && a[1][1] == -1 && a[2][0] == -1) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
