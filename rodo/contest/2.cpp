#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
	int t;cin>>t;
	ll a,b;
	while(t--){
		cin>>a>>b;
		int ans = 0;
		if(a < b) swap(a,b);
		int dep1=31-__builtin_clz(a),dep2=31-__builtin_clz(b);
		while(dep1 > dep2){
			ans++;
			a/=2;
			dep1--;
		}
		while(a != b){
			ans+=2;
			a/=2;
			b/=2;
		}
		cout<<ans<<'\n';
	}

	return 0;
}

