#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	//ios_base::sync_with_stdio(0);
	string s;
	while(cin>>s){
		int a = 0,b=0;
		bool oki=1;
		for(int i=0;i<5;i++){
			a += (s[2*i]=='1');
			if(s[2*i]=='1'){
				if(a-b>5-i){
					cout<<"TEAM-A "<<2*i+1<<endl;
					oki=0;
					break;
				}
			}else{
				if(b-a>4-i){
					cout<<"TEAM-B "<<2*i+1<<endl;
					oki=0;
					break;
				}
			}
			b += (s[2*i+1]=='1');
			if(s[2*i+1]=='1'){
				if(b-a>4-i){
					cout<<"TEAM-B "<<2*i+2<<endl;
					oki=0;
					break;
				}
			}else{
				if(a-b>4-i){
					cout<<"TEAM-A "<<2*i+2<<endl;
					oki=0;
					break;
				}
			}
		}
		if(!oki) continue;
		if(a>b){
			cout<<"TEAM-A 10"<<endl;
		}else if(a<b){
			cout<<"TEAM-B 10"<<endl;
		}else{
			bool ok=1;
			for(int i=5;i<10;i++){
				if(s[2*i] == s[2*i+1]) continue;
				if(s[2*i]=='1'){
					cout<<"TEAM-A "<<2*i+2<<endl;
					ok=0;
					break;
				}else{
					cout<<"TEAM-B "<<2*i+2<<endl;
					ok=0;
					break;
				}
			}
			if(ok) cout<<"TIE\n";
		}
	}

	return 0;
}

