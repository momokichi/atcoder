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

template <class T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

struct UnionFind {
  vector<int> par, siz;
  UnionFind(int n) : par(n, -1), siz(n, 1) {}
  int root(int x) {
    if (par[x] == -1) return x;
    return par[x] = root(par[x]);
  }
  bool isSame(int x, int y) { return root(x) == root(y); }
  bool unite(int x, int y) {
    x = root(x), y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }
  int size(int x) { return siz[root(x)]; }
};

using Graph = vector<vector<int>>;
vector<int> visited(false);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

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

vector<int> eratosthenes(int n) {
  vector<bool> is_prime(n + 1, true);
  vector<int> p;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      for (int j = i * 2; j <= n; j += i) {
        is_prime[j] = false;
      }
      p.push_back(i);
    }
  }
  return p;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  ll ans = 0;

  if (a == b) {
    cout << n * n << endl;
    return 0;
  }

  vector<int> d(n, 0), e(n, 0);
  rep(i, n) {
    d[a[i] - 1]++;
    e[b[i] - 1]++;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i] == b[c[j] - 1]) ans++;
    }
  }
  cout << ans << endl;
  // cout << fixed << setprecision(9) << ans << endl;
}
