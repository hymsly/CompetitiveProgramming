#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		vector<int> v(4);
		for(int i=0;i<4;i++) cin>>v[i];
		sort(v.begin(),v.end());
		if(v[3]==v[0]) cout<<"YES\n";
		else if(v[1]>v[0]) cout<<"NO\n";
		else{
			if(v[2]==v[1]) cout<<"NO\n";
			else{
				if(v[3]>v[2]) cout<<"NO\n";
				else cout<<"YES\n";
			}
		}
	}

	return 0;
}

