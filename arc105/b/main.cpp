#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  ll n;
  cin >> n;
  set<ll> st;
  rep(i, n) {
    ll a;
    cin >> a;
    st.insert(a);
  };

  while (*st.begin() != *st.rbegin()) {
    ll a = *st.rbegin() - *st.begin();
    st.erase(*st.rbegin());
    st.insert(a);
  }
  cout << *st.begin() << endl;
}
