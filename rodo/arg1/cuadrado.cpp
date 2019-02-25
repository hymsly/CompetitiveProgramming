#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,k;
pair<ll,ll> A[105];

const ll INF = (5e18);


int f(pair<ll,ll> x,pair<ll,ll> y){
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(A[i].first>=x.first && A[i].first <= y.first && A[i].second>=x.second && A[i].second <= y.second) ans++;
	}
	return ans;
}

pair<ll,ll> esquina(pair<ll,ll> a,pair<ll,ll> b){
	return make_pair(min(a.first,b.first),min(a.second,b.second));
}
pair<ll,ll> esquina2(pair<ll,ll> a,pair<ll,ll> b){
	return make_pair(max(a.first,b.first),max(a.second,b.second));
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>A[i].first;
	}
	for(int i=1;i<=n;i++){
		cin>>A[i].second;
	}
	if(k==1){
		cout<<4<<endl;
		return 0;
	}
	ll ans = INF;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			pair<ll,ll> p = esquina(A[i],A[j]);
			ll lo=0,hi=(2e9);
			while(hi-lo>1){
				ll mi = (hi+lo)/2;
				pair<ll,ll> q = make_pair(p.first+mi,p.second+mi);
				if(f(p,q)>=k) hi=mi;
				else lo=mi;
			}
			ans = min(ans,(hi+2)*(hi+2));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			pair<ll,ll> p = esquina2(A[i],A[j]);
			ll lo=0,hi=(2e9);
			while(hi-lo>1){
				ll mi = (hi+lo)/2;
				pair<ll,ll> q = make_pair(p.first-mi,p.second-mi);
				if(f(q,p)>=k) hi=mi;
				else lo=mi;
			}
			ans = min(ans,(hi+2)*(hi+2));
		}
	}
	cout<<ans<<endl;

	return 0;
}

