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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n)
          cin >>
      a[i];
  int ans = 0;
  rep(i, n)
  {
    if ((i + 1) % 2 == 1 && a[i] % 2 == 1)
      ans++;
  }
  cout << ans << endl;
}
