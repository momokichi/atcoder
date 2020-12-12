#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
vector<int> visited(false);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(const Graph &G, int v) {
  visited[v] = true;
  for (auto next : G[v]) {
    if (visited[next]) continue;
    dfs(G, next);
  }
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

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
  vector<int> a(n);

  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = 0;

  // rep(i, n) cout << a[i];

  vector<int> left(n + 1, 0), right(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    left[i + 1] = gcd(left[i], a[i]);
  }

  for (int i = n - 1; i >= 0; --i) {
    right[i] = gcd(right[i + 1], a[i]);
  }

  for (int i = 0; i < n; ++i) {
    int l = left[i];
    int r = right[i + 1];
    ans = max(ans, gcd(l, r));
  }

  cout << ans << endl;

  // cout << fixed << setprecision(9) <<  << endl;
}
