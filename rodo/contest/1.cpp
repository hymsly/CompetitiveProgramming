#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll l,d,s,c;

int main(){
	int t;cin>>t;
	while(t--){
		cin>>l>>d>>s>>c;
		ll val = s;
		int day=1;
		while(val < l){
			val = val*(c+1);
			day++;
		}
		if(day <= d) cout<<"ALIVE AND KICKING\n";
		else cout<<"DEAD AND ROTTING\n";
	}

	return 0;
}

