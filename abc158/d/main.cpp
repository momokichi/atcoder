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
  int q;
  cin >> s >> q;
  bool flag = true;
  string s1, s2;
  s1 = s;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) swap(s1, s2);
    if (t == 2) {
      int f;
      string c;
      cin >> f >> c;
      if (f == 1)
        s2 += c;
      else
        s1 += c;
    }
  }
  reverse(s2.begin(), s2.end());
  cout << s2 << s1 << endl;
}
