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

int main() {
  string s;
  cin >> s;
  if (s == string(s.rbegin(), s.rend())) {
    cout << yes << endl;
  } else {
    int c1 = 0, c2 = 0;

    while (s.back() == 'a') {
      s.pop_back();
      c2++;
    }
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == 'a')
        c1++;
      else
        break;
    }
    string t = s.substr(min(c1, c2));
    // cout << t << endl;
    if (t == string(t.rbegin(), t.rend()))
      cout << yes << endl;
    else
      cout << no << endl;
  }
}
