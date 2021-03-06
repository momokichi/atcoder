#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef unsigned long long int ll;
typedef long double ld;

ll calc(string s) {
  ll ans = 0;
  vector<int> v(10);
  rep(i, 5) {
    // cout << s[i] << endl;
    int a = s[i] - '0';
    v[a - 1]++;
  }

  rep(i, 9) { ans += (i + 1) * pow(10, v[i]); }

  return ans;
}

int main() {
  ll k;
  string s, t;
  cin >> k >> s >> t;

  vector<ld> v(9, k);

  rep(i, 4) {
    int a = s[i] - '0';
    int b = t[i] - '0';
    v[a - 1]--;
    v[b - 1]--;
  }

  // for (auto x : v) cout << x << " ";
  // cout << endl;

  ll sum = 0;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      ll takahashi = calc(s.substr(0, 4) + to_string(i));
      ll aoki = calc(t.substr(0, 4) + to_string(j));

      if (takahashi > aoki) {
        if (i == j) {
          if (v[i - 1] > 1) {
            sum += (v[i - 1]) * ((v[j - 1]) - 1);
          }
        } else {
          if (v[i - 1] > 0 && v[j - 1] > 0) {
            sum += (v[i - 1]) * (v[j - 1]);
          }
        }
      }
      // cout << endl;
    }
  }
  // cout << sum << endl;
  // cout << ((9 * k - 8) * (9 * k - 9)) << endl;
  ld ans = sum / (ld)((9 * k - 8) * (9 * k - 9));

  if (ans > 1) ans = 1;
  cout << fixed << setprecision(16) << ans << endl;
}
