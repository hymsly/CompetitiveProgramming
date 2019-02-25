#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
const Long INF = (2e18);
typedef pair<Long, Long> Pair;
const int N = (50);
int vis[N + 2][N + 2];
char M[N + 2][N + 2];
int ax, ay, bx, by;
int sqr(int x) { return x * x; }
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n;
void dfs(int x, int y, int val) {
  vis[x][y] = val;
  fore(i, 0, 4) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
    if (M[xx][yy] == '1') continue;
    if (vis[xx][yy]) continue;
    dfs(xx, yy, val);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  cin >> ax >> ay >> bx >> by;
  ax--;
  ay--;
  bx--;
  by--;
  fore(i, 0, n) fore(j, 0, n) cin >> M[i][j];
  dfs(ax, ay, 1);
  if (vis[bx][by] == 1) {
    cout << 0 << '\n';
    return 0;
  }
  dfs(bx, by, 2);
  vector<Pair> uno, dos;
  fore(i, 0, n) fore(j, 0, n) {
    if (vis[i][j] == 1) uno.pb({i, j});
    if (vis[i][j] == 2) dos.pb({i, j});
  }
  int ans = (1e9);
  fore(i, 0, SZ(uno)) fore(j, 0, SZ(dos)) {
    ans = min(
        sqr(uno[i].first - dos[j].first) + sqr(uno[i].second - dos[j].second),
        ans);
  }
  cout << ans << '\n';

  return 0;
}