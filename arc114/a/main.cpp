#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef unsigned long long int ll;
typedef long double ld;

const int inf = 1e8;
const ll llinf = 1e18;
const double PI = acos(-1);
#define yes "Yes"
#define no "No"
#define all(n) n.begin(), n.end()

vector<pair<ll, ll>> f(ll n) {
  vector<pair<ll, ll>> res;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;

    ll e = 0;
    while (n % i == 0) {
      e++;
      n /= i;
    }
    res.push_back({i, e});
  }
  if (n != 1) res.push_back({n, 1});
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  ll ans = 1;

  set<ll> st;

  rep(i, n) {
    vector<pair<ll, ll>> v = f(x[i]);
    sort(all(v));
    bool flag = true;
    for (auto a : v) {
      if (st.find(a.first) != st.end()) {
        flag = false;
        break;
      }
    }
    if (flag) {
      for (auto a : v) {
        if (st.find(a.first) == st.end()) {
          st.insert(a.first);
          break;
        }
      }
    }
  }

  for (auto a : st) ans *= a;
  cout << ans << endl;
}