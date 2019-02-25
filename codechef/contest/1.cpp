#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  fore(i, 0, n) cin >> v[i];
  sort(all(v));
  int cnt = 0;
  fore(i, 0, n) {
    if (v[i] <= cnt) cnt++;
  }
  cout << cnt << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}