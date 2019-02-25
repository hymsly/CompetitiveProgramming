#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> pr;
vector<int> semi;
bool ok[205];
bool pri(int x){
	for(int i=2;i*i<=x;i++) if(x%i==0) return false;
	return true;
}

void init(){
	for(int i=2;i<=200;i++) if(pri(i)) pr.push_back(i);
	int len = pr.size();
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			if(pr[i]*pr[j]>200) break;
			semi.push_back(pr[i]*pr[j]);
		}
	}
	sort(semi.begin(),semi.end());
	len = semi.size();
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			if(semi[i]+semi[j]>200) break;
			ok[semi[i]+semi[j]]=1;
		}
	}
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	init();
	int t;cin>>t;
	int x;
	while(t--){
		cin>>x;
		cout<<(ok[x]?"YES\n":"NO\n");
	}

	return 0;
}

