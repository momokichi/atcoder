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

int main() {
  ll n;
  cin >> n;

  set<ll> st;

  for (ll a = 2; a * a < n + 1; ++a) {
    ll c = a;
    rep(b, 38) {
      c *= a;
      if (c <= n)
        st.insert(c);
      else
        break;
    }
  }

  // for (auto x : st) {
  //   cout << x << " ";
  // }
  // cout << endl;

  cout << n - st.size() << endl;
}
