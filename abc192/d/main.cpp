#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef unsigned long long ll;
typedef long double ld;
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
const int inf = 1e8;
const ll llinf = 1e18;
const double PI = acos(-1);
#define yes "Yes"
#define no "No"
#define all(n) n.begin(), n.end()

using Graph = vector<vector<int>>;
vector<int> visited(false);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

ll f(string x, ll n) {
  mp::cpp_int ret = 0;

  mp::cpp_int b = 1;
  for (int i = 0; i < x.length(); ++i) {
    // cout << b << endl;
    ret += b * (x[i] - '0');
    b *= n;
  }
  return ret;
}

bool isOK(ll n, ll key, string x) { return (f(x, n) > key); }

ll bin_search(ll key, ll n, string x) {
  ll left = n;
  ll right = (ll)1e18;
  while (right - left > 1) {
    ll mid = left + (right - left) / 2;

    if (isOK(mid, key, x))
      right = mid;
    else
      left = mid;
  }
  return right;
}

int main() {
  string x;
  ll m;
  cin >> x >> m;
  string y = x;
  sort(all(y), greater<ll>());
  int d = y[0] - '0';
  ll ans = 0;
  reverse(all(x));

  if (x.length() == 1) {
    ll a = x[0] - '0';
    if (a <= m)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }

  ll b = bin_search(m, d + 1, x);
  ans = b - (d + 1);

  cout << ans << endl;
  // cout << fixed << setprecision(9) << ans << endl;
}
