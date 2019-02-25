#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
ll d;

map<ll,int> M;

int main(){
	cin>>n>>d;
	ll num;
	for(int i=0;i<n;i++){
		cin>>num;
		M[num-d*(i)]++;
	}
	int ans = n;
	map<ll,int> :: iterator it;
	for(it=M.begin();it!=M.end();it++){
		ans = min(ans,n-(*it).second);
	}
	cout<<ans<<'\n';

	return 0;
}

