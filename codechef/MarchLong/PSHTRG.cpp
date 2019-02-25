#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> T[262144];
ll N=1;

vector<ll> merge(vector<ll> a,vector<ll> b){
	vector<ll> ans;
	int i=0,j=0;
	while(i<a.size() || j<b.size()){
		if(i==a.size()) ans.push_back(b[j++]);
		else if(j==b.size()) ans.push_back(a[i++]);
		else{
			if(a[i] < b[j]) ans.push_back(a[i++]);
			else ans.push_back(b[j++]);
		}
	}
	return ans;
}

void build(){
	for(int i=N-1;i>0;i--) T[i] = merge(T[i<<1],T[i<<1|1]);
}

void update(int p,ll x){
	p+=N;
	T[p].pop_back();
	T[p].push_back(x);
	while(p>1){
		T[p>>1] = merge(T[p],T[p^1]);
		p>>=1;
	}
}

ll binary(int nodo,ll val){
	int lo=0,hi=T[nodo].size();
	while((hi-lo)>1){
		int mi = (hi+lo)/2;
		if(T[nodo][mi] > val) hi=mi;
		else lo=mi;
	}
	return T[nodo][lo];
}

ll triangle(ll c,vector<int> &nodos){
	
}

ll query(ll l,ll r){
	if(r-l<3) return 0;
	vector<int> ans;
	l+=N;
	r+=N;
	while(l<r){
		if(l&1){
			ans.push_back(l++);
		}
		if(r&1){
			ans.push_back(--r);
		}
		l>>=1;
		r>>=1;
	}
	ll lo=0,hi=(1e9+1);
	while((hi-lo)>1){
		ll mi = (hi+lo)/2;
		ll x = 0;
		for(int i=0;i<ans.size();i++){
			x = max(x,binary(ans[i],mi));
		}
		if(triangle(x,ans)) lo=mi;
		else hi=mi;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	ll n,q;cin>>n>>q;
	while(N<n) N<<=1;
	ll num;
	for(int i=N;i<N+n;i++){
		cin>>num;
		T[i].push_back(num);
	}
	build();
	int t;
	while(q--){
		cin>>t;
		if(t==1){
			int p;ll val;
			cin>>p>>val;
			p--;
			update(p,val);
		}else{
			int l,r;
			cin>>l>>r;
			l--;
			cout<<query(l,r)<<'\n';
		}
	}
	

	return 0;
}

