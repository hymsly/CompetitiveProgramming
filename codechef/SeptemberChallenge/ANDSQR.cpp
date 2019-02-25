#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e5);
const ll INF = (1<<30)-1;

ll A[N+2];
ll ST[262144];
ll N;

vector<ll> square;

bool isSquare(ll x){
	int p = lower_bound(square.begin(),square.end(),x) - square.begin();
	if(p==square.size()) return false;
	return (square[p]==x);
}

ll query(ll l,ll r){//[l,r>
	ll ans = 0;
	for(int i=l;i<r;i++){
		ll cur = A[i];
		if(isSquare(cur)) ans++;
		for(int j=i+1;j<r;j++){
			cur &=A[j];
			if(isSquare(cur)) ans++;
		}
	}
	return ans;
}

void build(){
	for(int i=N-1;i>0;i--) ST[i] = ST[i<<1]&ST[(i<<1)|1];
}

ll queryST(ll l,ll r){
	l+=N;
	r+=N;
	ll ans = INF;
	while(l<r){
		if(l&1) ans&=ST[l++];
		if(r&1) ans&=ST[--r];
		l>>=1;
		r>>=1;
	}
	return ans;
}

void solve(){
	int n,q;
	cin>>n>>q;
	N=1;
	while(N<n) N<<=1;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++) ST[i+N-1] = A[i];
	build();
	ll l,r;
	while(q--){
		cin>>l>>r;
		cout<<query(l,r+1)<<'\n';
	}
}

void init(){
	for(int i=0;i<(1<<15);i++) square.push_back(i*i);
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

