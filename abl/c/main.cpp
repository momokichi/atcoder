#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);
vector<int> visited(false);
vector<int> prevVisited(false);
using Graph = vector<vector<int>>;
void dfs(const Graph &G, int v) {
  visited[v] = true;
  for (auto next : G[v]) {
    if (visited[next]) continue;
    dfs(G, next);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph adjList(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  int count = 0;
  visited.assign(n, false);
  prevVisited.assign(n, false);

  for (auto itr = visited.begin(); itr != visited.end(); ++itr) {
    int i = distance(visited.begin(), itr);
    // cout << i << endl;
    dfs(adjList, i);
    if (all_of(visited.begin(), visited.end(), [](bool v) { return v; })) {
      cout << count << endl;
      return 0;
    }
    if (prevVisited != visited) count++;
    prevVisited = visited;
  }
}
