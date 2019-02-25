#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> up,down;

bool ok(){
	for(int i=1;i<up.size();i++){
		if(up[i] >= up[i-1]) return false;
	}
	for(int i=1;i<down.size();i++){
		if(down[i] <= down[i-1]) return false;
	}
	return true;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	int n,r;
	while(t--){
		down.clear();
		up.clear();
		cin>>n>>r;
		int num;
		for(int i=0;i<n;i++){
			cin>>num;
			if(num>=r) up.push_back(num);
			if(num<=r) down.push_back(num);
		}
		if(ok()) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}

