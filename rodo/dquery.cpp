#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int block = 500;
ll M[30005];
ll cnt[1000002];
ll ans = 0;
ll res[200002];

struct Query{
	int l,r,pos;
	Query(){
		l=0;r=0;pos=0;
	}
	Query(int _l,int _r,int _pos){
		l = _l;
		r = _r;
		pos = _pos;
	}
};

bool cmp(Query x, Query y) {
	if(x.l/block != y.l/block) {
		// different blocks, so sort by block.
		return x.l/block < y.l/block;
	}
	// same block, so sort by R value
	return x.r < y.r;
}

Query Q[200002];

void add(int x){
	if(cnt[M[x]]==0) ans++;
	cnt[M[x]]++;
}

void borrar(int x){
	if(cnt[M[x]]==1) ans--;
	cnt[M[x]]--;
}

void solve(int q){
	int l=0,r=0;
	for(int i=0;i<q;i++){
		while(r <= Q[i].r){
			add(r++);
		}
		while(l > Q[i].l){
			add(--l);
		}
		while(r > Q[i].r+1){
			borrar(--r);
		}
		while(l < Q[i].l){
			borrar(l++);
		}
		res[Q[i].pos] = ans;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;cin>>n;
	for(int i=0;i<n;i++) cin>>M[i];
	int q;cin>>q;
	int l,r;
	for(int i=0;i<q;i++){
		cin>>l>>r;
		Q[i] = Query(l-1,r-1,i);
	}
	sort(Q,Q+q,cmp);
	solve(q);
	for(int i=0;i<q;i++) cout<<res[i]<<'\n';

	return 0;
}

