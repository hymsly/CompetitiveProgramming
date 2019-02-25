#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll T[524288];
ll M[200005];
ll val[200005];
ll N=1;
update(int l,int r){
	l+=N;
	r+=N;
	while(l<r){
		if(l&1){
			T[l++]++;
		}
		if(r&1){
			T[--r]++;
		}
		l>>=1;
		r>>=1;
	}
}

ll get(int x){
	x += N;
	ll ans = 0;
	while(x){
		ans += T[x];
		x>>=1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;cin>>n;
	int q;cin>>q;
	while(N<n) N<<=1;
	for(int i=0;i<n;i++) cin>>M[i];
	sort(M,M+n);
	//for(int i=0;i<n;i++) cout<<M[i]<<(char)(i+1==n?10:32);
	int l,r;
	while(q--){
		cin>>l>>r;
		update(l-1,r);
	}
	for(int i=0;i<n;i++){
		val[i] = get(i);
	}
	sort(val,val+n);
	//for(int i=0;i<n;i++) cout<<val[i]<<(char)(i+1==n?10:32);
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans += (val[i]*M[i]);
	}
	cout<<ans<<'\n';

	return 0;
}

