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
  int n;
  ll Y;
  cin >> n >> Y;
  Y /= 1000;

  for (int x = 0; x <= 1e4; ++x) {
    for (int y = 0; y <= 1e4; ++y) {
      int z = n - x - y;
      if (z >= 0 && z <= 1e4 && 10 * x + 5 * y + z == Y) {
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  // cout << fixed << setprecision(9) <<  << endl;
}