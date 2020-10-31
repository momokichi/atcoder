#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  vector<int> a;
  rep(i, n) a.push_back(2);
  rep(i, m) a.push_back(3);
  for (int i = 0; i < n + m; i++) {
    for (int j = i + 1; j < n + m; j++) {
      if ((a[i] + a[j]) % 2 == 0) ans++;
    }
  }
  cout << ans << endl;
}
