#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> fact(ll x){
	vector<ll> ans;
	for(ll i=2;i*i<=x;i++){
		while(x%i==0){
			ans.push_back(i);
			x/=i;
		}
	}
	if(x>1) ans.push_back(x);
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll x;
	while(cin>>x){
		if(x==0) break;
		
		bool neg = (x<0?true:false);
		vector<ll> divi = fact(abs(x));
		cout<<x<<" = ";
		if(neg) cout<<"-1 x ";
		for(int i=0;i<divi.size();i++) cout<<divi[i]<<(i+1==divi.size()?"\n":" x ");
	}

	return 0;
}

