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
  int ac = 0, wa = 0, tle = 0, re = 0;
  while (n--)
  {
    string input;
    cin >> input;
    if (input == "AC")
      ac++;
    else if (input == "WA")
      wa++;
    else if (input == "TLE")
      tle++;
    else
      re++;
  }
  printf("AC x %d\n", ac);
  printf("WA x %d\n", wa);
  printf("TLE x %d\n", tle);
  printf("RE x %d\n", re);
}
