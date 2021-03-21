#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;
typedef long double ld;

const int inf = 10000;

struct Point {
  int x;
  int y;
};

struct Rect {
  Point start;
  Point end;
};

int main() {
  int n;
  cin >> n;
  vector<Point> ad(n);

  // input
  rep(i, n) {
    int _;  // 一旦面積は考えない
    cin >> ad[i].x >> ad[i].y;
    cin >> _;
  }

  vector<Rect> ans(n);
  // calc
  rep(i, n) {
    ans[i].start.x = ad[i].x;
    ans[i].start.y = ad[i].y;
  }

  // set x
  rep(i, n) {
    int c = inf;

    rep(j, n) {
      if (i == j) continue;

      if (ad[i].x < ad[j].x) {
        c = min(c, ad[j].x);
      }
    }
    ans[i].end.x = (c == ad[i].x) ? ad[i].x + 1 : c;
  }

  // set y
  rep(i, n) {
    bool isSameX = false;
    rep(j, n) {
      if (i == j) continue;
      if (ad[i].x == ad[j].x) {
        isSameX = true;
        break;
      }
    }
    if (isSameX) {
      ans[i].start.y = ad[i].y;
      ans[i].end.y = ad[i].y + 1;
    } else {
      ans[i].start.y = 0;
      ans[i].end.y = inf;
    }
  }

  // output
  rep(i, n) {
    int a = ans[i].start.x;
    int b = ans[i].start.y;
    int c = ans[i].end.x;
    int d = ans[i].end.y;
    printf("%d %d %d %d\n", a, b, c, d);
  }
}
