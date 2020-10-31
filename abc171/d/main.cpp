#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
typedef long long int ll;

int main()
{
  ll n, q;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];

  cin >> q;

  vector<ll> b, c;
  rep(i, q)
  {
    ll s, d;
    cin >> s >> d;
    b.push_back(s);
    c.push_back(d);
  }

  sort(a.begin(), a.end());

  map<ll, ll> map;
  for (ll i = 0; i < n; i++)
  {
    auto itr = map.find(a[i]);
    if (itr != map.end())
      map[a[i]]++;
    else
      map[a[i]] = 1;
  }

  // for (auto x : map)
  //   cout << x.first << " " << x.second << endl;
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  // cout << sum << endl;

  vector<ll> s;
  for (ll i = 0; i < q; i++)
  {
    sum += (c[i] - b[i]) * (map[b[i]]);
    s.push_back(sum);
    map[c[i]] += map[b[i]];
    map[b[i]] = 0;

    // for (auto x : map)
    //   cout << x.first << " " << x.second << endl;
  }

  for (auto ans : s)
    cout << ans << endl;
}
