#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	int n,p;
	while(t--){
		cin>>n>>p;
		if(p==1){
			cout<<n<<" ";
			for(int i=0;i<n;i++) cout<<"a";
			cout<<'\n';
		}else if(p==2){
			if(n<=6){
				int l = n/2 + (n%2);
				cout<<l<<" ";
				for(int i=0;i<l;i++) cout<<"a";
				for(int i=l;i<n;i++) cout<<"b";
				cout<<'\n';
			}else if(n==7){
				cout<<"3 aaababb\n";
			}else if(n==8){
				cout<<"3 aaababbb\n";
			}else{
				cout<<"4 aaaabbab";
				n-=8;
				string s = "aabbab";
				for(int i=0;i<n/6;i++) cout<<s;
				for(int i=0;i<n%6;i++) cout<<s[i];
				cout<<'\n';
			}
		}else{
			cout<<"1 ";
			for(int i=0;i<n/3;i++){
				cout<<"abc";
			}
			if(n%3==1) cout<<"a";
			else if(n%3==2) cout<<"ab";
			cout<<'\n';
		}
	}

	return 0;
}

