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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  int total = accumulate(a.begin(), a.end(), 0);
  double border = double(total) / (4 * m);
  // cout << border << endl;
  int num = 0;
  rep(i, n)
  {
    if (a[i] >= border)
      num++;
  }
  if (num >= m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
