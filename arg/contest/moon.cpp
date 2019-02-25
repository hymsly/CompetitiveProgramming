#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;cin>>n;
	vector< vector<int> > ans;
	if(n%2==1){//facil
		while(n>1){
			int myans[] = {3,n,n-1,1};
			vector<int> cur(myans,myans + sizeof(myans) / sizeof(int));
			ans.push_back(cur);
			ans.push_back(cur);
			for(int i=2;i<=n-2;i+=2){
				int mynewnas[] = {4,n,i,n-1,i+1};
				vector<int> cur2(mynewnas,mynewnas + sizeof(mynewnas) / sizeof(int));
				ans.push_back(cur2);	
				ans.push_back(cur2);
			}
			n-=2;
		}
	}else{
		while(n>4){
			int myans[] = {3,n,n-1,1};
			vector<int> cur(myans,myans + sizeof(myans) / sizeof(int));
			ans.push_back(cur);
			ans.push_back(cur);
			for(int i=2;i<=n-2;i+=2){
				int mynewnas[] = {4,n,i,n-1,i+1};
				vector<int> cur2(mynewnas,mynewnas + sizeof(mynewnas) / sizeof(int));
				ans.push_back(cur2);	
				ans.push_back(cur2);
			}
			n-=2;
		}		
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<(char)(j+1==ans[i].size()?10:32);
	}

	return 0;
}

