#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll d(vector<ll> x,vector<ll> y){
	ll ans=0;
	for(int i=0;i<x.size();i++){
		ans+=sqr(x[i]-y[i]);
	}
	return ans;
}

int main(){
	//fast_io()
	int n;cin>>n;
	vector<ll> a(n),b(n),c(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++) cin>>c[i];
	ll val1 = d(a,b);
	ll val2 = d(a,c);
	if(val1<=val2) cout<<"Yan"<<endl;
	else cout<<"MaratonIME"<<endl;
	
	return 0;
}

