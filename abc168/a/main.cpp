#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  string n;
  cin >> n;
  if(stoi(n)>=100)
   n = n[2];
  else if(stoi(n)>=10)
   n = n[1];

  int k;
  k = stoi(n);
  if(k == 2 || k ==4 || k == 5 || k == 7 || k == 9)
    cout << "hon" << endl;
  else if (k == 0 || k == 1 || k== 6 || k == 8)
    cout << "pon" << endl;
  else
    cout << "bon" << endl;
}
