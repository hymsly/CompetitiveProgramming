#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(int p){
	string ans = "a";
	for(int i=0;i<p;i++) ans.push_back('b');
	ans.push_back('a');
	return ans;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	int p,n;
	while(t--){
		cin>>n>>p;
		if(p<=2) cout<<"impossible\n";
		else{
			if(n%p>0) cout<<"impossible\n";
			else{
				string s = f(p-2);
				int t = n/p;
				for(int i=0;i<t;i++) cout<<s;
				cout<<'\n';
			}
		}
	}

	return 0;
}

