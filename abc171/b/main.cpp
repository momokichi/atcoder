#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> p;
  for (int i = 0; i < n; i++)
  {
    int s;
    cin >> s;
    p.push_back(s);
  }
  sort(p.begin(), p.end());

  int ans = 0;
  for (int i = 0; i < k; i++)
  {
    ans += p[i];
  }
  cout << ans << endl;
}
