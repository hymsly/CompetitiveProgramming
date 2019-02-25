#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
const int INF = (1e9);
typedef pair<int, int> Pair;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long n;
void askM(int x, bool &res) {
  cout << "> " << x << endl;
  cin >> res;
}
void askV(int idx, Long &res) {
  cout << "? " << idx << endl;
  cin >> res;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  Long lo = 0, hi = INF;
  bool ok;
  Long used = 60;
  while (hi - lo > 1) {
    Long mi = (hi + lo) / 2;
    askM(mi, ok);
    used--;
    if (ok)
      lo = mi;
    else
      hi = mi;
  }
  // hi es el maximo
  vector<Long> v;
  Long res;
  fore(i, 0, used) {
    int val = rng() % n + 1;
    askV(val, res);
    v.pb(res);
  }
  v.pb(hi);
  sort(all(v));
  auto it = unique(all(v));
  v.resize(distance(v.begin(), it));
  Long d = 0;
  fore(i, 1, SZ(v)) { d = __gcd(d, v[i] - v[i - 1]); }
  Long menor = v[0];
  int minimo = hi - (n - 1) * d;
  vector<int> divisores;
  for (Long i = 1; i * i <= d; i++) {
    if (d % i == 0) {
      divisores.pb(i);
      if (d / i != i) divisores.pb(d / i);
    }
  }
  sort(all(divisores));
  fore(i, 0, SZ(divisores)) {
    int val = divisores[i];
    if ((hi - menor) / val + 1 > n) continue;
    cout << "! " << minimo << " " << d << endl;
    return 0;
  }
  assert(false);

  return 0;
}