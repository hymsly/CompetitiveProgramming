#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll T[262144][40];
ll N = 1;

void build(){
	for(int i=N-1;i>0;i--){
		for(int j=0;j<31;j++){
			T[i][j] = T[2*i][j]+T[2*i+1][j];
		}
	}
}

int query(int l,int r,int j){
	l += N;
	r += N;
	ll ans = 0;
	while(l<r){
		if(l&1){
			ans += T[l++][j];
		}
		if(r&1){
			ans += T[--r][j];
		}
		l >>= 1;
		r >>= 1;
	}
	return ans;
}

ll POT[40];

void init(){
	POT[0] = 1;
	for(int i=1;i<40;i++) POT[i]=2*POT[i-1];
}

ll solve(int l,int r){
	ll ans = 0;
	for(int j=0;j<31;j++){
		int cnt = query(l,r,j);//cantidad de 1's
		int resto = (r-l-cnt);//cantidad de 0's
		if(cnt < resto) ans+=POT[j];
	}
	return ans;
}

int main(){
	init();
	int n,q;
	cin>>n>>q;
	while(N<n) N<<=1;
	ll num;
	for(int i=0;i<n;i++){
		cin>>num;
		for(int j=0;j<31;j++){
			if(num & (1<<j)) T[N+i][j]=1;
			else T[N+i][j]=0;
		}
	}
	build();
	int l,r;
	while(q--){
		cin>>l>>r;
		l--;
		cout<<solve(l,r)<<'\n';		
	}

	return 0;
}

