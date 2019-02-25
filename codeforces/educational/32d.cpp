#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x;
	if(y==2) return (x*(x-1))/2;
	if(y==3) return (x*(x-1)*(x-2))/6;
	if(y==4) return (x*(x-1)*(x-2)*(x-3))/24;
}

ll F(ll k){
	if(k==0) return 1;
	vector<int> v(k);
	for(int i=0;i<k;i++)v[i]=i;
	ll ans = 0;
	do{
		bool ok=1;
		for(int i=0;i<k;i++){
			if(v[i]==i) ok=0;
		}
		if(ok) ans++;
	}while(next_permutation(v.begin(),v.end()));
	return ans;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	ll ans = 0;
	for(int i=n-k;i<=n;i++){
		ans += C(n,n-i)*F(n-i);
	}
	cout<<ans<<endl;

	return 0;
}

