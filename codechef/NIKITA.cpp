#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	string s;
	while(t--){
		cin>>s;
		int cnt=0;
		int maxi=0;
		int mini=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='<') cnt++;
			else if(s[i]=='>') cnt--;
			maxi=max(maxi,cnt);
			mini=min(mini,cnt);
		}
		cout<<maxi-mini+1<<endl;
	}

	return 0;
}


