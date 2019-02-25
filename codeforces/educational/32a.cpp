#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//ios_base::sync_with_stdio(0);
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	int ans = 0;
	for(int i=1;i<n-1;i++){
		if(v[i-1] > v[i] && v[i] < v[i+1]) ans++;
		if(v[i-1] < v[i] && v[i] > v[i+1]) ans++;
	}
	cout<<ans<<'\n';

	return 0;
}

