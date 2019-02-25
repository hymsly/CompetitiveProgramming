#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f(string x){
	ll ans = 0;
	for(int i=0;i<x.size();i++){
		ans += (x[i]-'A' + 1);
	}
	return ans;
}

int main(){
	string val;
	ll ans = 0;
	ll pos = 1;
	while(cin>>val){
		ans += (pos++)*(f(val));
	}
	cout<<ans<<endl;

	return 0;
}

