#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;

int main()
{
  ll n;
  cin >> n;
  vector<char> ans;
  for (int i = 1; i < 20; i++)
  {
    int t = n % (27);
    char c = (char)(t + 96);
    ans.push_back(c);
    n = n - pow(27.0, i) + 1;
    cout
        << "n: " << n << endl;
    if (n <= 0)
      break;
  }

  reverse(ans.begin(), ans.end());
  for (char x : ans)
    cout
        << x;
  cout << endl;
}
