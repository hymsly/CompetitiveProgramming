#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;cin>>n;
	vector<ll> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n-2;i++){
		ll p = b[i]-a[i];
		if(p<0){
			cout<<"NIE\n";
			return;
		}
		a[i]+=p;
		a[i+1]+=2*p;
		a[i+2]+=3*p;
	}
	for(int i=0;i<n;i++) if(a[i]!=b[i]) {
		cout<<"NIE\n";return;
	}
	cout<<"TAK\n";
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

