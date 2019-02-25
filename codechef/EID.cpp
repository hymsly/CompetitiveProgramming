#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		int ans = 10000000;
		for(int i=1;i<n;i++){
			ans = min(ans,v[i]-v[i-1]);
		}
		cout<<ans<<'\n';
	}

	return 0;
}

