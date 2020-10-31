#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int x = 1; x <= n - 1; ++x) {
    int prime = 0;
    for (int y = 1; y * y <= x; ++y) {
      if (x % y == 0) {
        prime++;
        if (x / y != y) prime++;
      }
    }
    count += prime;
  }
  cout << count << endl;
}
