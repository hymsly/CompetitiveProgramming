#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;

const ll N = 200001;
const int BLOCK = 448; // ~sqrt(N)

ll a[N], ans[N] ;
ll answer[N];
map<int,int> M;

struct node {
	int L, R, i, k;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position){
	M[a[position]]++;
	answer[M[a[position]]-1]++;
}

void remove(int position) {
	answer[M[a[position]]-1]--;
	if(M[a[position]]==1) M.erase(a[position]);
	else M[a[position]]--;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		M.clear();
		memset(answer,0,sizeof(answer));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
	
		for(int i=0; i<m; i++) {
			scanf("%d%d%d",&q[i].L,&q[i].R,&q[i].k);
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
			ans[q[i].i] = M.size() - answer[q[i].k];
		}
	
		for(int i=0; i<m; i++)
			printf("%d\n",ans[i]);
	}
}
