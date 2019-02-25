#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<ll> v;

ll f(ll x){
	cout<<x<<endl;
	int cantmin = lower_bound(v.begin(),v.end(),x) - v.begin();
	int cantmax = upper_bound(v.begin(),v.end(),x) - v.begin();
	cout<<cantmin<<" "<<cantmax<<endl;
	ll ans=0;
	int cnt=0;
	for(int i=cantmin-1;i>=0;i--){
		cnt++;
		if(cnt==m || i==0) ans+=(2*(x-v[i])),cnt=0;
	}
	for(int i=cantmax;i<n;i++){
		cnt++;
		if(cnt==m || i+1==n) ans+=(2*(v[i]-x)),cnt=0;
	}
	return ans;
}

int main(){
	//ios_base::sync_with_stdio(0);
	scanf("%d%d",&n,&m);
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	int lo=0,hi=n-1;
	while((hi-lo)>2){
		ll mi1 = (2*lo + hi)/3;
		ll mi2 = (lo + 2*hi)/3;
		if(f(v[mi1]) > f(v[mi2])) lo = mi1;
		else hi=mi2;
	}
	ll ans = (1e18);
	for(ll i=lo;i<=hi;i++) ans = min(ans,f(v[i]));
	cout<<ans<<'\n';

	return 0;
}
