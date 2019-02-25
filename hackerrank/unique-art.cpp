#include<bits/stdc++.h>

using namespace std;
const int N = (1e6);
const int BLOCK = (1005);
map<int,int> s;
int n;
int A[N+3];
int cnt[N+3];
int res[N+3];
int ans;
struct node {
	int L, R, pos;
}Q[N+3];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}


void add(int x){
	if(cnt[A[x]]==0) ans++;
	if(cnt[A[x]]==1) ans--;
	cnt[A[x]]++;
}

void borrar(int x){
	if(cnt[A[x]]==2) ans++;
	if(cnt[A[x]]==1) ans--;
	cnt[A[x]]--;
}

void solve(int q){
	int l=0,r=0;
	for(int i=0;i<q;i++){
		while(r <= Q[i].R){
			add(r++);
		}
		while(l > Q[i].L){
			add(--l);
		}
		while(r > Q[i].R+1){
			borrar(--r);
		}
		while(l < Q[i].L){
			borrar(l++);
		}
		res[Q[i].pos] = ans;
	}
}

int main(){
	cin>>n;
	int ind = 0;
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		if(s.count(num)){
			A[i] = s[num];
		}else{
			A[i] = ind;
			s[num] = ind++;
		}
	}
	int q;cin>>q;
	for(int i=0;i<q;i++){
		cin>>Q[i].L>>Q[i].R;
		Q[i].L--;
		Q[i].R--;
		Q[i].pos = i;
	}
	sort(Q,Q+q,cmp);
	solve(q);
	for(int i=0;i<q;i++) cout<<res[i]<<'\n';

	return 0;
}

