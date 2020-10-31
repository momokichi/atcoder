#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  int n;
  cin >> n;
  int flag = 0;
  while (n--) {
    int d1, d2;
    cin >> d1 >> d2;
    if (d1 == d2) {
      flag++;
    } else {
      flag = 0;
    }
    if (flag == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
