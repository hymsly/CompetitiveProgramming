#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const long long N = 211111;
const long long A = 1111111;
const int BLOCK = 450; // ~sqrt(N)

long long cnt[A], a[N], ans[N], answer = 0;

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

void add(int position) {
	cnt[a[position]]++;
	answer+=a[position]*(2*cnt[a[position]]-1);
}

void remove(int position) {
	cnt[a[position]]--;
	answer-=a[position]*(2*cnt[a[position]]+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<m; i++) {
		cin>>q[i].L>>q[i].R;
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		cout<<ans[i]<<'\n';
}
