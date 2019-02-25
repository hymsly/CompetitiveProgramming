#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,x,s,a,b;
	cin>>n>>x>>s;
	while(s--){
		cin>>a>>b;
		if(a==x) x=b;
		else if(b==x) x=a;
	}
	cout<<x<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

