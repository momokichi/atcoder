#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
vector<int> visited(false);

void dfs(const Graph &G, int v) {
  visited[v] = true;
  for (auto next : G[v]) {
    if (visited[next]) continue;
    dfs(G, next);
  }
}

ll gcd(ll a, ll b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return abs(a) / gcd(a, b) * abs(b); }

vector<ll> divisors(ll n) {
  vector<ll> a;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      a.push_back(i);
      if (n / i != i) a.push_back(n / i);
    }
  }
  sort(a.begin(), a.end());
  return a;
}

// pairを要素に持つvectorをsecondを基準にソートする比較関数
bool comp(pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; }

ll lcm2(const vector<ll> &v) {
  ll val = v[0];
  for (ll i = 1; i < v.size(); ++i) val = lcm(val, v[i]);
  return val;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n - 1);
  rep(i, n - 1) a[i] = i + 2;

  // cout << lcm2(a) + 1 << endl;
  ll ans = 0;
  ans =
      accumulate(a.begin(), a.end(), 1LL, [](ll m, ll n) { return lcm(m, n); });
  cout << ans + 1 << endl;
  // // cout << fixed << setprecision(9) <<  << endl;
}
