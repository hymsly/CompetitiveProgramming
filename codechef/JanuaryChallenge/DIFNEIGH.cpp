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
const int N = (50);
int A[N + 2][N + 2];
int B[4][N + 2];
int C[N + 2][4];
int getValue(int px, int py, int k) {
  set<int> S;
  if (px > 2) S.insert(A[px - 2][py]);
  if (py > 2) S.insert(A[px][py - 2]);
  S.insert(A[px - 1][py - 1]);
  S.insert(A[px - 1][py + 1]);
  fore(i, 1, k + 1) if (S.find(i) == S.end()) return i;
  return -1;
}
bool works(int n, int m, int k) {
  memset(A, 0, sizeof A);
  fore(i, 1, n + 1) fore(j, 1, m + 1) {
    A[i][j] = getValue(i, j, k);
    if (A[i][j] == -1) return false;
  }
  return true;
}
void solve() {
  int n, m;
  cin >> n >> m;
  if (n > 2 && m > 2) {
    cout << 4 << '\n';
    fore(i, 1, n + 1) fore(j, 1, m + 1) {
      cout << A[i][j] << (char)(j == m ? 10 : 32);
    }
    return;
  }
  if (n == 1 || m == 1) {
    if (n * m <= 2) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
    if (n == 1) {
      fore(i, 1, n + 1) fore(j, 1, m + 1) {
        cout << A[i][j] << (char)(j == m ? 10 : 32);
      }
    } else {
      fore(i, 1, n + 1) fore(j, 1, m + 1) {
        cout << A[j][i] << (char)(j == m ? 10 : 32);
      }
    }
    return;
  }
  if (max(n, m) == 2) {
    cout << 2 << '\n';
    cout << "1 1\n";
    cout << "2 2\n";
    return;
  }
  cout << 3 << '\n';
  if (n == 2) {
    fore(i, 1, n + 1) fore(j, 1, m + 1) {
      cout << B[i][j] << (char)(j == m ? 10 : 32);
    }
  } else {
    fore(i, 1, n + 1) fore(j, 1, m + 1) {
      cout << C[i][j] << (char)(j == m ? 10 : 32);
    }
  }
}

void init() {
  memset(A, 0, sizeof A);
  works(50, 50, 4);
  int val = 0;
  fore(i, 1, 3) {
    fore(j, 1, 51) {
      B[i][j] = val / 2 + 1;
      C[j][i] = B[i][j];
      val++;
      val %= 6;
    }
    val = 3;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  init();
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}