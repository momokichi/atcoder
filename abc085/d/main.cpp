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
bool comp(pair<ll, ll> a, pair<ll, ll> b) { return a.second > b.second; }

int main() {
  ll n, h;
  cin >> n >> h;
  vector<pair<ll, ll>> katanas(n);
  ll storong_katana = 0;

  rep(i, n) {
    cin >> katanas[i].first >> katanas[i].second;
    storong_katana = max(storong_katana, katanas[i].first);
  }

  sort(katanas.begin(), katanas.end(), comp);

  int ans = 0;
  ll index = 0;
  while (h > 0) {
    if (index < n && (katanas[index].second > storong_katana)) {
      h -= katanas[index].second;
      index++;
      ans++;
    } else {
      ans += ceil((double)h / (double)storong_katana);
      break;
    }
  }

  cout << ans << endl;
  // rep(i, n) cout << katanas[i].first << " " << katanas[i].second << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}
