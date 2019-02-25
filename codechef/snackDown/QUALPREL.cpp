#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (1e9+1);

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.rbegin(),v.rend());
	int ans = 0;
	int last = INF;
	int pos=0;
	//for(int i=0;i<n;i++) cout<<v[i]<<(char)(i+1==n?10:32);
	while((ans<k || v[pos]==last) && pos<n){
		ans++;
		last = v[pos++];
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

