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
  string s2, t;
  cin >> s2 >> t;
  vector<string> ans;

  for (int i = 0; i <= (int)(s2.length() - t.length()); ++i) {
    string k = s2.substr(i, t.length());
    // cout << "k: " << k << endl;
    bool ok = true;
    for (int j = 0; j < (int)(t.length()); ++j) {
      if (k[j] == '?' || (k[j] == t[j])) continue;
      ok = false;
      break;
    }
    if (ok) {
      // cout << "ok" << endl;
      string b = regex_replace(s2, regex("[?]"), "a");
      string s = b.replace(i, t.length(), t);
      // cout << s << endl;
      ans.push_back(s);
    }
  }

  if (ans.empty()) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  sort(ans.begin(), ans.end());
  cout << ans[0] << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}
