#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll top(ll x,ll y){
	if(x%y==0) return x/y;
	else return x/y + 1;
}

int main(){
	ll l;cin>>l;
	int n;cin>>n;
	vector<ll> v(n);
	vector<ll> acum(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(i) acum[i] = acum[i-1]+v[i];
		else acum[i] = v[i];
	}
	ll res = 0;
	for(int i=0;i<n;i++){
		res += top(acum[i],l);
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		ll resto = acum[i]%l;
		if(resto==0) resto=l;
		if(v[i]==0) continue;
		if(i+1==n){
			if(resto<=v[i]) ans.push_back(i+1);
		}else{
			if(resto<=v[i] && resto+v[i+1]<=l) ans.push_back(i+1);
		}
	}
	cout<<res<<'\n';
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<(char)(i+1==ans.size()?10:32);

	return 0;
}

