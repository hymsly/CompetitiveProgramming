#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
int n, k;
const int MAXN = (1e5);
struct ft {  // Indexado de 1
  Long tree1[MAXN + 8], tree2[MAXN + 8];
  ft() {}
  void init(int m, Long val = 0) {
    for (int i = 0; i <= m; i++) tree1[i] = val, tree2[i] = val;
  }
  Long query1(Long i, Long num = 0) {
    while (i > 0) num += tree1[i], i -= (i & -i);
    return num;
  }
  void update1(Long i, Long del) {
    while (i <= MAXN) tree1[i] += del, i += (i & -i);
    return;
  }
  Long query2(Long i, Long num = 0) {
    while (i > 0) num += tree2[i], i -= (i & -i);
    return num;
  }
  void update2(Long i, Long del) {
    while (i <= MAXN) tree2[i] += del, i += (i & -i);
    return;
  }
  void update(Long l, Long r, Long val) {  // [ l , r ] acotados
    update1(l, val);
    update1(r + 1, -val);
    update2(l, val * (l - 1));
    update2(r + 1, -val * r);
    return;
  }
  Long query(Long l, Long r) {  // [ l , r ] acotados
    Long a = query1(r) * r - query2(r),
         b = query1(l - 1) * (l - 1) - query2(l - 1);
    return a - b;
  }
};
ft BIT;
int howmany(vector<int> &v, int x) {
  int p = lower_bound(v.begin(), v.end(), x + 1) - v.begin();
  return p;
}
void solve() {
  BIT.init(MAXN + 1, 0);
  cin >> n >> k;
  vector<Pair> v(n);
  fore(i, 0, n) cin >> v[i].first >> v[i].second;
  fore(i, 0, n) BIT.update(v[i].first, v[i].second, 1);
  vector<int> countK, countK1;
  fore(i, 1, MAXN + 1) {
    int val = BIT.query(i, i);
    if (val == k) countK.pb(i);
    if (val == k + 1) countK1.pb(i);
  }
  int cntK = SZ(countK);
  int ans = 0;
  fore(i, 0, n) {
    int manyK = howmany(countK, v[i].second) - howmany(countK, v[i].first - 1);
    int manyK1 =
        howmany(countK1, v[i].second) - howmany(countK1, v[i].first - 1);
    ans = max(ans, cntK - manyK + manyK1);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}