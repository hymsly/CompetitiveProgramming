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
const int INF = (2e9);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int mini = INF, maxi = -INF;
  int minIdx, maxIdx;
  int num;
  fore(i, 0, n) {
    cin >> num;
    if (maxi < num) {
      maxi = num;
      maxIdx = i;
    }
  }
  fore(i, 0, m) {
    cin >> num;
    if (mini > num) {
      mini = num;
      minIdx = i;
    }
  }
  fore(i, 0, m) cout << maxIdx << " " << i << '\n';
  fore(i, 0, n) {
    if (i == maxIdx) continue;
    cout << i << " " << minIdx << '\n';
  }

  return 0;
}
