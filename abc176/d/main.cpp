#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
struct pos {
  ll x;
  ll y;
};
int h, w;
int ch, cw, dh, dw;
ll ans = 0;
vector<string> s;
queue<pos> q;

int xVec[4] = {-1, +1, 0, 0};
int yVec[4] = {0, 0, -1, +1};

ll bfs() {
  q.push({ch, cw});

  while (!q.empty()) {
    pos now = q.front();
    q.pop();
    ll x = now.x;
    ll y = now.y;
    // 終了条件
    if (x == dw && y == dh) return ans;

    rep(i, 4) {
      pos next = {x + xVec[i], y + yVec[i]};
      if (next.x <= 0 && next.x >= w - 1 && next.y <= 0 && next.y >= h - 1 &&
          s[next.x][next.y] == '#') {
      }
    };
  }
  return -1;
}

int main() {
  cin >> h >> w;
  cin >> ch >> cw >> dh >> dw;
  s.resize(h);

  rep(i, h) cin >> s[i];

  cout << bfs() << endl;
}
