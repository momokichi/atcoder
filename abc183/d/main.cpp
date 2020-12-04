#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);
int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int lcm(int a, int b) { return abs(a) / gcd(a, b) * abs(b); }

ll n, w;

bool comp(ll x) { return x > w; }

int main() {
  cin >> n >> w;
  vector<tuple<ll, ll, ll>> x;
  rep(i, n) {
    ll s, t, p;
    cin >> s >> t >> p;
    x.emplace_back(s, t, p);
  }
  sort(begin(x), end(x));
  rep(i, n) {
    // cout << get<0>(x[i]) << " " << get<1>(x[i]) << " " << get<2>(x[i]) <<
    // endl;
    ll l = 0;
    ll a = get<1>(x[i]);
    l += get<2>(x[i]);
    for (int j = i + 1; j < n; j++) {
      if (get<0>(x[j]) < a && get<1>(x[j]) >= a) {
        // cout << l << endl;
        l += get<2>(x[j]);
      } else {
        break;
      }
    }
    // cout << l << endl;
    if (l > w) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
