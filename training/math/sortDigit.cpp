#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll x){
	vector<int> v;
	while(x){
		v.push_back(x%10);
		x/=10;
	}
	sort(v.rbegin(),v.rend());
	ll up = 0;
	for(int i=0;i<v.size();i++){
		up*=10;
		up+=v[i];
	}
	ll low = 0;
	sort(v.begin(),v.end());
	int pos = 0;
	for(int i=0;i<v.size();i++){
		if(v[i]>0){
			pos=i;
			break;
		}
	}
	swap(v[0],v[pos]);
	for(int i=0;i<v.size();i++){
		low*=10;
		low+=v[i];
	}
	ll dif = up-low;
	cout<<up<<" - "<<low<<" = "<<dif<<" = "<<9<<" * "<<dif/9<<'\n';
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll x;
	while(cin>>x){
		solve(x);
	}

	return 0;
}

