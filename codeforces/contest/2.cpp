#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.rbegin(), v.rend()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
const Long N = (2e5);
const Long INF = (2e9);
vector<Long> M[N + 2];

Long f(vector<Long> a, vector<Long> b) {
  return min({abs(a[0] - b[0]) + abs(a[1] - b[1]),
              abs(a[1] - b[0]) + abs(a[0] - b[1])});
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  fore(i, 0, 2 * n) {
    int num;
    cin >> num;
    num--;
    M[num].pb(i);
  }
  Long ans = 0;
  vector<Long> ini = {0LL, 0LL};
  fore(i, 0, n) {
    ans += f(ini, M[i]);
    ini = M[i];
  }
  cout << ans << '\n';

  return 0;
}