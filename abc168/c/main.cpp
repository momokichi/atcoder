#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  double a,b,h,m ;
  cin >> a >> b >> h >> m ;
  cout << fixed << setprecision(10);

  double ans = 0.0;
  double C= 0.0;
  double hour = (h*60.0+ m) * 0.5 * acos(-1)/180.0;
  double min = m * 6.0 * acos(-1)/180.0;

  ans = a*a + b*b - (2.0*a*b* cos(hour - min));
  // cout << ans << endl;
  cout << sqrtl(ans) << endl;

}
