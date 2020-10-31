#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;

string change(string s) {
  int len = s.length();
  for (int i = 0; i < len; i++) {
    if (s[i] == 'A')
      s[i] = 'T';
    else if (s[i] == 'C')
      s[i] = 'G';
    else if (s[i] == 'T')
      s[i] = 'A';
    else if (s[i] == 'G')
      s[i] = 'C';
  }
  return s;
}

void count(const string &s, int dict[]) {
  int len = s.length();
  for (int i = 0; i < len; i++) {
    if (s[i] == 'A')
      dict[0]++;
    else if (s[i] == 'C')
      dict[1]++;
    else if (s[i] == 'G')
      dict[2]++;
    else if (s[i] == 'T')
      dict[3]++;
  }
}

map<string, int> mp;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 2; j <= n - i; j++) {
      int dict[4] = {0, 0, 0, 0};
      string t = s.substr(i, j);
      if (mp.find(t) != mp.end()) {
        ans += mp[t];
        continue;
      }
      count(t, dict);
      if (dict[0] == dict[3] && dict[1] == dict[2]) {
        ans++;
        mp[t] = 1;
        continue;
      }
      mp[t] = 0;
    }
  }
  cout << ans << endl;
}
