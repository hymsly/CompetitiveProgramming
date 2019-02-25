#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = (4e6);

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	while(1){
		int n = v.size();
		ll val = v[n-1] + v[n-2];
		if(val > INF) break;
		v.push_back(val);
	}
	ll ans = 0;
	for(int i=0;i<v.size();i++){
		if(v[i]&1) continue;
		ans += v[i];
	}
	cout<<ans<<endl;


	return 0;
}

