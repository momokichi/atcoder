#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  int n;
  cin >> n;
  vector<ll> l(n);
  int count = 0;
  rep(i, n) { cin >> l[i]; };
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (l[i] + l[j] > l[k] && l[j] + l[k] > l[i] && l[k] + l[i] > l[j]) {
          if (l[i] != l[j] && l[j] != l[k] && l[k] != l[i]) count++;
        }
      }
    }
  }
  cout << count << endl;
}
