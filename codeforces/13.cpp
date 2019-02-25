#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 211111;
const int BLOCK = 455; // ~sqrt(N)

int a[N] ,ans[N], answer = 0;

struct node {
	int L, R, i;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}


int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	int m;
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			if(a[currentL+1] < a[currentL]) answer--;
			currentL++;
		}
		while(currentL > L) {
			if(a[currentL-1] > a[currentL]) answer++;
			currentL--;
		}
		while(currentR <= R) {
			if(a[currentR] < a[currentR-1]) answer++;
			currentR++;
		}
		while(currentR > R+1) {
			if(a[currentR-1] > a[currentR-2]) answer--;
			currentR--;
		}
		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);
}
