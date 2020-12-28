#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
typedef long double ld;

const double PI = acos(-1);
#define yes "Yes"
#define no "No"

using Graph = vector<vector<int>>;
vector<int> visited(false);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// pairを要素に持つvectorをsecondを基準にソートする比較関数

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;

  sort(a.begin(), a.end());
  vector<ll> s(n + 1, 0);
  rep(i, n) s[i + 1] = s[i] + a[i];

  rep(i, n - 1) {
    ll sum = s[n] - s[i + 1];
    ll sub = a[i] * (n - i - 1);
    // cout << sum << " " << sub << endl;
    ans += sum - sub;
  }

  cout << ans << endl;
}
