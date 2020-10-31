#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  string n;
  cin >> n;
  ll len = n.length();
  ll sum = 0;
  for (ll i = 0; i < len; i++) {
    sum += (int)(n[i] - '0');
  }

  if (sum % 9 == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
