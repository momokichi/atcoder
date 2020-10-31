#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  double a, b;
  cin >> a >> b;
  for (double i = 10; i <= 1000; ++i) {
    if (floor(i * 0.08) == a && floor(i * 0.1) == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
}
