#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	int x,n;
	string s;
	while(cin>>x>>n){
		cin>>s;
		ll ans = 0;
		for(int i=0;i<n;i++){
			if(s[i]=='2') continue;
			if(s[i]=='1') ans+=(i+1);
			else ans-=(i+1);
		}
		if(ans!=0) cout<<"FATAL\n";
	}
		
	
	return 0;
}

