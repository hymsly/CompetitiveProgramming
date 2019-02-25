#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n,R;cin>>n>>R;
	int r;
	for(int i=0;i<n;i++){
		cin>>r;
		if(r>=R)cout<<"Good boi\n";
		else cout<<"Bad boi\n";
	}
}
