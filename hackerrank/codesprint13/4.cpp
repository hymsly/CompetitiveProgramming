#include<bits/stdc++.h>

using namespace std;
const int N = (1e6);



int main(){
	int n;cin>>n;
	string s;cin>>s;
	int ab=0,ce=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==')'){
			if(ab>0) ab--;
			else ce++;
		}
		else{
			ab++;
		}
	}
	if(ab==0 && ce==0) cout<<"0\n";
	else if(ab==0 || ce==0) cout<<"1\n";
	else cout<<"2\n";

	return 0;
}

