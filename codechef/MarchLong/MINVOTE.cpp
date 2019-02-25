#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int M = (1e6);
int N=1;

struct BIT{
	ll tree[M+1];
	BIT(){
		for(int i=0;i<=M;i++) tree[i] = 0;
	}
	void Clear(){
		for(int i=0;i<=4*N;i++) tree[i] = 0;
	}
	ll Query(int i){
		ll sum = 0;
		while(i > 0){
			sum += tree[i];
			i -= ( i & -i );
		}
		return sum;
	}
	void Update(int i,ll val){
		while(i <= N){
			tree[i] += val;
			i += (i & -i);
		}
	}
} FT;

int T[262144];

void update(int l,int r){
	l += N;
	r += N;
	while(l<r){
		if(l&1){
			T[l++]++;
		}
		if(r&1){
			T[--r]++;
		}
		l >>= 1;
		r >>= 1;
	}
}

int query(int x){
	x += N;
	int ans = 0;
	while(x){
		ans += T[x];
		x >>= 1;
	}
	return ans;
}

void clear(int n){
	for(int i=1;i<N+n;i++) T[i] = 0;
}

int main(){
	int t;cin>>t;
	int n;
	while(t--){
		cin>>n;
		N = 1;
		while(N < n+1) N<<=1;
		FT.Clear();
		clear(n+1);
		ll num;
		for(int i=1;i<=n;i++){
			cin>>num;
			FT.Update(i,num);
		}
		for(int i=1;i<=n;i++){
			//DERECHA
			int lo=i,hi=n+1;
			ll val = FT.Query(i)-FT.Query(i-1);
			while((hi-lo)>1){
				int mi = (hi+lo)/2;
				ll suma = FT.Query(mi-1)-FT.Query(i);
				if( suma > val) hi=mi;
				else lo=mi;
			}
			update(i+1,hi);
			//IZQUIERDA
			lo=0,hi=i;
			while((hi-lo)>1){
				int mi = (hi+lo)/2;
				if(FT.Query(i)-FT.Query(mi)>2*val) lo=mi;
				else hi=mi;
			}
			update(hi,i);
		}
		for(int i=1;i<=n;i++) cout<<query(i)<<(char)(i==n?10:32);
	}

	return 0;
}

