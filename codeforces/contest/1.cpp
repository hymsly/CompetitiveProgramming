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
  int n;
  cin >> n;
  vector<Long> v(n);
  fore(i, 0, n) cin >> v[i];
  sort(v.begin(), v.end());
  int mid = n / 2;
  cout << v[mid] << '\n';

  return 0;
}