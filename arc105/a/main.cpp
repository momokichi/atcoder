#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll sum = a + b + c + d;
  if (a == sum - a || b == sum - b || c == sum - c || d == sum - d)
    cout << "Yes" << endl;
  else if (a + b == sum - a - b || a + c == sum - a - c ||
           a + d == sum - a - d || b + c == sum - b - c ||
           b + d == sum - b - d || c + d == sum - c - d)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
