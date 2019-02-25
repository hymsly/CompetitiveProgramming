#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int caso;
int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int x,y;
	while(cin>>x>>y){
		if(x==0 && y==0) break;
		int ans = (x/y + (x%y>0))-1;
		if(ans<=26) cout<<"Case "<<++caso<<": "<<ans<<'\n';
		else cout<<"Case "<<++caso<<": impossible"<<'\n';
	}

	return 0;
}

