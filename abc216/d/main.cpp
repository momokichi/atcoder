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

bool comp(queue<int> a, queue<int> b) {
  if (a.front() < b.front())
    return true;
  else if (a.front() > b.front())
    return false;
  else
    return a.size() < b.size();
}

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

void print_queue(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> k(m);
  vector<queue<int>> a(m);
  rep(i, m) {
    cin >> k[i];
    rep(j, k[i]) {
      int t;
      cin >> t;
      a[i].push(t);
    }
  }

  while (1) {
    if (m == 0) break;
    if (m == 1) {
      cout << no << endl;
      return 0;
    }

    sort(all(a), comp);

    // rep(i, m) { print_queue(a[i]); }

    bool f = true;
    for (int j = 0; j < m - 1; ++j) {
      if (a[j].front() == a[j + 1].front()) {
        f = false;
        a[j].pop();
        a[j + 1].pop();
        if (a[j].empty()) {
          a[j].push(inf);
          m--;
        }
        if (a[j + 1].empty()) {
          a[j + 1].push(inf);
          m--;
        }
        // k[j]--;
        // k[j + 1]--;
      }
    }
    if (f) {
      cout << no << endl;
      return 0;
    }
  }

  cout << yes << endl;
}
