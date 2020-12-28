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
  ll n, k, q;
  cin >> n >> k >> q;
  vector<ll> a(n, 0);
  vector<ll> points(n, k);
  rep(i, q) {
    int m;
    cin >> m;
    m--;
    a[m]++;
  }

  rep(i, n) {
    if (k - (q - a[i]) > 0)
      cout << yes << endl;
    else
      cout << no << endl;
  }
  // cout << fixed << setprecision(9) <<  << endl;
}
