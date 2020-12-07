#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef unsigned long long int ll;
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

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int lcm(int a, int b) { return abs(a) / gcd(a, b) * abs(b); }

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

int main() {
  int n;
  cin >> n;
  string t;
  cin >> t;
  ll ans = 0;

  string s = "";
  rep(i, n) s += "110";
  auto itr = s.find(t);
  if (itr == string::npos) {
    cout << "0" << endl;
    return 0;
  }

  if (t == "1") {
    ans = (ll)(2 * 1e10);
  } else if (t == "11") {
    ans = (ll)1e10;
  } else {
    ll k = count(t.begin(), t.end(), '0');

    if (t[n - 1] == '0') {
      ans = (ll)1e10 - k + 1;
    } else if (t[n - 1] == '1') {
      ans = (ll)1e10 - k;
    }
  }
  cout << ans << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}
