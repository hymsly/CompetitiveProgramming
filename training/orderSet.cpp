#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll,null_type,greater<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll read(int n){
	ordered_set X;
	ll num;
	ll ans = 0;
	vector< pair<ll,ll> > v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		//X.insert(v[i].second);
		ans += (X.order_of_key(v[i].second));
		X.insert(v[i].second);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll x,y;cin>>x>>y;
	ll n,m;
	cin>>n>>m;
	ll ans = (n+1)*(m+1);
	ans += read(n);
	ans += read(m);
	cout<<ans<<'\n';

	return 0;
}

