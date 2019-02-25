#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
Long sqr(Long x) { return x * x; }
struct Point {
  Long x, y;
  Point() {}
  Point(Long _x, Long _y) {
    x = _x;
    y = _y;
  }
};
struct Rect {
  Point a, b;
  Long id;
  Rect() {}
  Rect(Point _a, Point _b) {
    a = _a;
    b = _b;
  }
  bool fit(Point x) {
    if (x.x > a.x && x.x < b.x && x.y > b.y && x.y < a.y) return true;
    return false;
  }
};
struct Circle {
  Point c;
  Long r;
  Long id;
  Circle() {}
  Circle(Point _c, Long _r) {
    c = _c;
    r = _r;
  }
  bool fit(Point x) {
    Long dist = sqr(x.x - c.x) + sqr(x.y - c.y);
    if (dist < sqr(r)) return true;
    return false;
  }
};
void read(string x, Long &y) {
  bool neg = 0;
  if (x[0] == '-') neg = 1;
  y = 0;
  fore(i, 0, SZ(x)) {
    if (x[i] == '.' || x[i] == '-') continue;
    y *= 10;
    y += (x[i] - '0');
  }
  if (neg) y = -y;
  // cout << x << " " << y << endl;
}
bool vis[20];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  char type;
  vector<Rect> v;
  vector<Circle> w;
  int cnt = 1;
  while (cin >> type) {
    string a, b, c, d;
    if (type == '*') break;
    if (type == 'r') {
      cin >> a >> b >> c >> d;
      Rect cur;
      read(a, cur.a.x);
      read(b, cur.a.y);
      read(c, cur.b.x);
      read(d, cur.b.y);
      // cout << a << " " << b << " " << c << " " << d << endl;
      // cout << cur.a.x << " " << cur.a.y << endl;
      // cout << cur.b.x << " " << cur.b.y << endl;
      cur.id = cnt++;
      v.pb(cur);
    } else {
      cin >> a >> b >> c;
      Circle cur;
      read(a, cur.c.x);
      read(b, cur.c.y);
      read(c, cur.r);
      // cout << cur.c.x << " " << cur.c.y << endl;
      // cout << cur.r << endl;
      cur.id = cnt++;
      w.pb(cur);
    }
  }
  string a, b;
  Point cur;
  int cntP = 1;
  while (cin >> a >> b) {
    if (a == "9999.9" && b == "9999.9") break;
    memset(vis, 0, sizeof vis);
    read(a, cur.x);
    read(b, cur.y);
    // cout << cur.x << " " << cur.y << endl;
    for (auto x : v) {
      if (x.fit(cur)) vis[x.id] = 1;
    }
    for (auto x : w) {
      if (x.fit(cur)) vis[x.id] = 1;
    }
    bool ok = 0;
    fore(i, 0, cnt) {
      if (vis[i])
        cout << "Point " << cntP << " is contained in figure " << i << '\n',
            ok = 1;
    }
    if (!ok) cout << "Point " << cntP << " is not contained in any figure\n";
    cntP++;
  }
  return 0;
}