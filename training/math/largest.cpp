#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> pr;

void fact(ll x){
	pr.clear();
	for(ll i=2;i*i<=x;i++){
		bool ok=0;
		while(x%i==0){
			ok=1;
			x/=i;
		}		
		if(ok) pr.push_back(i);
	}
	if(x>1) pr.push_back(x);
	sort(pr.rbegin(),pr.rend());
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll x;
	while(cin>>x){
		if(x==0) break;
		fact(abs(x));
		if(pr.size()<2) cout<<"-1\n";
		else{
			cout<<pr[0]<<'\n';
		}
	}

	return 0;
}

