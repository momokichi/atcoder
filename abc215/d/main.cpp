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

// 最大公約数
ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}

// 最小公倍数
ll lcm(ll a, ll b) { return abs(a) / gcd(a, b) * abs(b); }

set<int> st;

void divisors(ll n) {
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      st.insert(i);
      if (n / i != i) st.insert(n / i);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    divisors(a[i]);
  }

  for (int i = 1; i <= m; ++i) {
    if (st.count(i) == 0) cout << i << endl;
    ;
  }

  // cout << fixed << setprecision(9) << ans << endl;
}
