#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
const int MX = (1e6 + 1);
struct ft {  // Indexado de 1
  Long tree[MX + 8];
  ft() {}
  void init(int m, Long val = 0) {
    for (int i = 0; i <= m; i++) tree[i] = val;
  }
  Long query(Long i, Long num = 0) {
    while (i > 0) num += tree[i], i -= (i & -i);
    return num;
  }
  void update(Long i, Long del) {
    while (i <= MX) tree[i] += del, i += (i & -i);
    return;
  }
  Long queryRange(int l, int r) {
    return query(r) - query(l - 1);
  }
};
ft BIT;
int kth(int k) {
  int lo = 0, hi = MX;
  while (hi - lo > 1) {
    int mi = (hi + lo) / 2;
    if (BIT.query(mi) >= k)
      hi = mi;
    else
      lo = mi;
  }
  return hi;
}
void remove(int k) {
  int val = kth(k);
  BIT.update(val, -1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  int num;
  fore(i, 0, n) {
    cin >> num;
    BIT.update(num, 1);
  }
  while (q--) {
    cin >> num;
    if (num < 0) {
      remove(-num);
    } else {
      BIT.update(num, 1);
    }
  }
  if (BIT.query(MX) == 0)
    cout << 0 << '\n';
  else
    cout << kth(1) << '\n';

  return 0;
}
