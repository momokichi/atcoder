#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
typedef long double ld;

const double PI = acos(-1);
#define yes "Yes"
#define no "No"

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

bool isPrime(ll n) {
  if (n < 2) return false;
  for (ll i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}

// 最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数
ll lcm(ll a, ll b) { return abs(a) / gcd(a, b) * abs(b); }

ll gcd2(const vector<ll> &v) {
  ll val = v[0];
  for (ll i = 1; i < v.size(); ++i) val = gcd(val, v[i]);
  return val;
}

ll lcm2(const vector<ll> &v) {
  ll val = v[0];
  for (ll i = 1; i < v.size(); ++i) val = lcm(val, v[i]);
  return val;
}

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
  ll n, m;
  cin >> n >> m;

  if (n == m) {
    cout << 0 << endl;
    return 0;
  }

  if (m == 0) {
    cout << 1 << endl;
    return 0;
  }

  vector<ll> a(m);
  rep(i, m) { cin >> a[i]; }
  sort(a.begin(), a.end());

  // 番兵追加
  a.insert(a.begin(), 0);
  a.push_back(n + 1);

  ll width = n;
  vector<ll> v;  // 白色区間の長さを入れる

  rep(i, m + 1) {
    ll len = a[i + 1] - a[i] - 1;
    if (len > 0) {
      width = min(width, a[i + 1] - a[i] - 1);
      v.push_back(len);
    }
  }
  // cout << "width " << width << endl;

  ll ans = 0;
  ll prev = 1;

  for (auto len : v) {
    // ans += ((len + width - 1) / width);
    ans += ceil((ld)len / (ld)width);
  }

  cout << ans << endl;

  // cout << fixed << setprecision(9) <<  << endl;
}
