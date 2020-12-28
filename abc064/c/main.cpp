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
#define all(n) n.begin(), n.end()

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

int rating(int n) {
  if (n < 400)
    return 0;
  else if (n < 800)
    return 1;
  else if (n < 1200)
    return 2;
  else if (n < 1600)
    return 3;
  else if (n < 2000)
    return 4;
  else if (n < 2400)
    return 5;
  else if (n < 2800)
    return 6;
  else if (n < 3200)
    return 7;
  else
    return 8;
}

int main() {
  int n;
  cin >> n;
  vector<int> rate(9, 0);
  rep(i, n) {
    int a;
    cin >> a;
    rate[rating(a)]++;
  }

  if (rate[8] != 0) {
    int mini = 0;
    int ma = 0;
    rep(i, 8) {
      if (rate[i] != 0) mini++;
    }
    ma = mini + rate[8];
    if (mini == 0) mini = 1;  // 色が0種類はダメ

    cout << mini << " " << ma << endl;
  } else {
    int ans = 0;
    rep(i, 8) {
      if (rate[i] != 0) ans++;
    }
    cout << ans << " " << ans << endl;
  }
  // cout << fixed << setprecision(9) <<  << endl;
}
