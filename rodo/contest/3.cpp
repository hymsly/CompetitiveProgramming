#include<bits/stdc++.h>

using namespace std;


int main(){
	int t;cin>>t;
	map<int,int> S;
	stack<int> Q;
	map<int,int> :: iterator it;
	int type;
	while(t--){
		cin>>type;
		if(type==1){
			int val;
			cin>>val;
			Q.push(val);
			S[val]++;
		}else if(type==2){
			int p = Q.top();
			Q.pop();
			S[p]--;
			if(S[p]==0) S.erase(p);
		}else{
			it = S.end();
			it--;
			cout<<(*it).first<<'\n';
		}
		//for(it=S.begin();it!=S.end();it++) cout<<(*it).first<<" "<<(*it).second<<endl;
	}

	return 0;
}

