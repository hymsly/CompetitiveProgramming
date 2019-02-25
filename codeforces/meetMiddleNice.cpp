#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1e18);

void getval(int i,ll val,vector<ll> &v,vector<ll> &cont){
	//cout<<i<<" "<<val<<endl;
	if(i==v.size()){
		cont.push_back(val);
		return;
	}
	if(val<=INF/v[i])getval(i,val*v[i],v,cont);
	getval(i+1,val,v,cont);
}
vector<ll> valuesA,valuesB;
ll get(ll x){
	ll ans = 0;
    for(int i = 0, j = valuesA.size()-1; i < valuesB.size(); i++) {
        if(valuesB[i] > x) break;
        while(j >= 0 && valuesB[i] > x / valuesA[j]) j--;
        ans += j+1ll;
    }
    return ans;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	int p = n/2,r = n-p;
	vector<ll> a(r),b(p);
	for(int i=0;i<n/2;i++){
		cin>>a[i]>>b[i];
	}
	if(r>p) cin>>a[r-1];
	//for(int i=0;i<a.size();i++) cout<<a[i]<<(char)(i+1==a.size()?10:32);
	//for(int i=0;i<b.size();i++) cout<<b[i]<<(char)(i+1==b.size()?10:32);
	getval(0,1LL,a,valuesA);
	getval(0,1LL,b,valuesB);
	sort(valuesA.begin(),valuesA.end());
	sort(valuesB.begin(),valuesB.end());
	//for(int i=0;i<valuesA.size();i++) cout<<valuesA[i]<<(char)(i+1==valuesA.size()?10:32);
	//for(int i=0;i<valuesB.size();i++) cout<<valuesB[i]<<(char)(i+1==valuesB.size()?10:32);
	ll k;cin>>k;
	ll lo=0,hi=INF+1;
	while(hi-lo>1){
		ll mi = (hi+lo)/2;
		if(get(mi)<k) lo=mi;
		else hi=mi;
	}
	cout<<hi<<'\n';
	
	return 0;
}

