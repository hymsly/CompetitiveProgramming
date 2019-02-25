#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll par,impar;

void solve(){
	par = 0;
	impar = 0;
	int n;cin>>n;
	map<ll,ll> M;
	vector<ll> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(v[i]%2==0){
			ans += par;
			par++;
		}else{
			ans+=impar;
			impar++;
		}
		ll search = v[i]^2;
		if(M.count(search)) ans-=M[search];
		if(M.count(v[i])) ans-=M[v[i]];
		M[v[i]]++;
	}
	cout<<ans<<'\n';
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

