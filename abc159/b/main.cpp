#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;

bool isKaibun(string s) {
  // cout << s << endl;
  string r = s;
  reverse(r.begin(), r.end());
  int len = s.length();
  rep(i, len) {
    if (s[i] != r[i]) return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  int n = s.length();
  if (isKaibun(s) && isKaibun(s.substr(0, (n - 1) / 2)) &&
      isKaibun(s.substr((n + 3) / 2 - 1, n)))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
