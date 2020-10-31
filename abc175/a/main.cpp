#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  string s;
  cin >> s;
  int count = 0;
  int ans = 0;
  if (s == "RSS") {
    cout << "1" << endl;
    return 0;
  }
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'R')
      count++;
    else {
      ans = count;
      count = 0;
    }
  }
  cout << max(ans, count) << endl;
}
