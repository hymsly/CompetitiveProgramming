#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//ios_base::sync_with_stdio(0);
	int n;cin>>n;
	string s;cin>>s;
	int a=0,b=0,c=0,d=0;;
	for(int i=0;i<n;i++){
		if(s[i]=='R') a++;
		if(s[i]=='L') b++;
		if(s[i]=='U') c++;
		if(s[i]=='D') d++;
	}
	cout<<2*min(a,b)+2*min(c,d)<<'\n';

	return 0;
}

