#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  vector<Long> v(4);
  fore(i, 0, 4) cin >> v[i];
  sort(all(v));
  bool triangle = 0, segment = 0;
  do {
    if (v[0] < v[1] || v[0] < v[2]) continue;
    if (v[0] < v[1] + v[2]) triangle = 1;
    if (v[0] == v[1] + v[2]) segment = 1;
  } while (next_permutation(all(v)));
  if (triangle)
    cout << "TRIANGLE\n";
  else if (segment)
    cout << "SEGMENT\n";
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}