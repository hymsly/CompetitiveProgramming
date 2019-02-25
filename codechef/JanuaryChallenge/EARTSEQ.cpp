#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> Pair;
const ll N = (613000);
const ll INF = (1e9);
bool isPrimo[N + 2];
deque<ll> primos;
vector<ll> primosOrden;
void criba() {
  memset(isPrimo, 1, sizeof isPrimo);
  for (ll i = 2; i * i <= N; i++)
    if (isPrimo[i]) {
      for (ll j = i * i; j <= N; j += i) isPrimo[j] = 0;
    }
  fore(i, 2, N) if (isPrimo[i]) primos.pb(i);
  bool ok = 1;
  while (SZ(primos)) {
    ll num;
    if (ok) {
      num = primos.front();
      primos.pop_front();
    } else {
      num = primos.back();
      primos.pop_back();
    }
    ok = 1 - ok;
    primosOrden.pb(num);
  }
  cout << SZ(primosOrden) << endl;
}
bool validar(vector<ll> &v) {
  int n = SZ(v);
  fore(i, 0, n) {
    ll x = v[i];
    ll y = v[(i + 1) % n];
    ll z = v[(i + 2) % n];
    if (__gcd(x, y) == 1) return false;
    if (__gcd(x, __gcd(y, z)) > 1) return false;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<ll> ans;
  fore(i, 0, n) {
    ll x = primosOrden[i];
    ll y = primosOrden[(i + 1) % n];
    if (x * y > INF) {
      assert(false);
    }
    ans.pb(x * y);
  }
  // cout << validar(ans) << endl;
  // fore(i, 0, n) cout << ans[i] << (char)(i + 1 == n ? 10 : 32);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  criba();
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}