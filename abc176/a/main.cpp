#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main()
{
  int n,x,t;
  cin >> n >> x >> t;
  int ans = 0;
  while (n > 0) {
    n -= x;
    ans +=t;
  }
  cout << ans << endl;
}
