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

struct p {
  ll x, y;
};

bool comp(p a, p b) { return a.x < b.x; }

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
  vector<p> points(n);
  rep(i, n) cin >> points[i].x >> points[i].y;
  ll ans = 0;
  sort(all(points), comp);

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        for (int l = k + 1; l < n; ++l) {
          if (points[i].x != points[j].x) break;
          if (points[k].x != points[l].x) break;

          if (points[i].x == points[j].x && points[k].x == points[l].x) {
            if (points[i].y == points[k].y && points[j].y == points[l].y) {
              ans++;
            }
          }
        }
      }
    }
  }

  // rep(i, n) cout << points[i].x << " " << points[i].y << endl;
  cout << ans << endl;
  // cout << fixed << setprecision(9) << ans << endl;
}
