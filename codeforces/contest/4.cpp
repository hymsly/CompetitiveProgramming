#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (Long i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<Long, Long> Pair;
const int N = (100);
Long cnt[N + 2];
Long lejos[N + 2];
int n, m;
Long f(Long a, Long b) {
  if (b > a) return b - a;
  return b + n - a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  Long a, b;
  fore(i, 0, m) {
    cin >> a >> b;
    a--;
    b--;
    cnt[a]++;
    if (cnt[a] == 1)
      lejos[a] = f(a, b);
    else
      lejos[a] = min(lejos[a], f(a, b));
  }
  fore(i, 0, n) cout << cnt[i] << " " << lejos[i] << endl;
  fore(i, 0, n) {
    Long ans = 0;
    fore(j, 0, n) if (cnt[j]) {
      ans = max(ans, (cnt[j] - 1) * n + f(i, j) + lejos[j]);
    }
    cout << ans << (char)(i + 1 == n ? 10 : 32);
  }

  return 0;
}