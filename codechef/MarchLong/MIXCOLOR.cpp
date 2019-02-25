#include<bits/stdc++.h>

using namespace std;

map<int,int> M;

int main(){
	int t;cin>>t;
	int n;
	while(t--){
		M.clear();
		cin>>n;
		int num;
		for(int i=0;i<n;i++){
			cin>>num;
			M[num]++;
		}
		map<int,int> :: iterator it;
		int ans = 0;
		for(it=M.begin();it!=M.end();it++){
			ans += (*it).second-1;
		}
		cout<<ans<<endl;
	}

	return 0;
}

