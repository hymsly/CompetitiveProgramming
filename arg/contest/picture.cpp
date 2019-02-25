#include<bits/stdc++.h>

using namespace std;
const int N = (3000);


map<char,int> L[N+2];
map<char,int> R[N+2];

bool vis1[N+2];
bool vis2[N+2];

int main(){
	int n;cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='?') continue;
			L[i][s[j]]++;
			R[j][s[j]]++;
		}
	}
	stack< pair<pair<char,int>,char> > S;
	for(int i=0;i<2*n;i++){
		bool ok=0;
		int posible=0;
		for(int j=0;j<n;j++){
			if(vis1[j]) continue;
			//L
			if(L[j].size()==1){
				//tomo este
				vis1[j]=1;
				L[j].clear();
				ok=1;
				break;
			}
		}
		if(ok) continue;
		for(int j=0;j<n;j++){
			if(vis2[j]) continue;
			//R
			if(R[j].size()==1){
				vis2[j]=1;
				ok=1;
				break;
			}
		}
		if(ok) continue;
		for(int j=0;j<n;j++){
			if(vis1[j]) continue;
			if(L[j].size()==0){
				//tomo este
				vis1[j]=1;
				S.push({{'h',j+1},'a'});
				ok=1;
				break;
			}
		}
		if(ok) continue;
		for(int j=0;j<n;j++){
			if(vis2[j]) continue;
			//R
			if(R[j].size()==0){
				vis2[j]=1;
				S.push({{'v',j+1},'a'});
				ok=1;
				break;
			}
		}
	}


	return 0;
}

