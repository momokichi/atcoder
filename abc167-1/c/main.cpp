#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> c(n);

  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  int min_cost;
}