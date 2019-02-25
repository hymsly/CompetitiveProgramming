#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (1e5);

ll A[N+2];
ll ST[N+2][25];
int n;


void build(){
	for(int i=0;i<n;i++){
		ST[i][0] = A[i];	
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=0;i+(1<<j)<=n;i++){
			ST[i][j] = min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
		}
	}
}

ll query(int l,int r){
	int d = r-l;
	int lg = 31 - (__builtin_clz(d));
	return min(ST[l][lg],ST[r-(1<<lg)][lg]);
}

int binary2(int pos,ll x){
	int lo=-1,hi=pos;
	while(hi-lo>1){
		int mi = (hi+lo)/2;
		if(x == query(mi,pos+1)) hi=mi;
		else lo=mi;
	}
	return hi;
}

int binary1(int pos,ll x){
	int lo=pos,hi=n;
	while(hi-lo>1){
		int mi = (hi+lo)/2;
		if(x==query(pos,mi+1)) lo = mi;
		else hi = mi;
	}
	return lo;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];
	build();
	ll ans = 0;
	for(int i=0;i<n;i++){
		int hi = binary1(i,A[i]);
		int lo = binary2(i,A[i]);
		ans = max(ans,(hi-lo+1)*A[i]);
	}
	cout<<ans<<endl;

	return 0;
}

