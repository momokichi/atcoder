#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  int k;
  string s;
  cin >> k;
  cin >> s;
  if(s.size() <=k)
    cout << s << endl;
  else {
    s= s.erase(k);
    s += "...";
    cout << s << endl;
  }
}
