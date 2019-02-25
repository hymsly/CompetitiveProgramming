#include<bits/stdc++.h>

using namespace std;

bool can(vector<int> &v){
	set<int> sum,res;
	for(int i=0;i<8;i++){
		int p = v[i]+i , q = v[i]-i;
		if(sum.find(p) != sum.end()) return false;
		else sum.insert(p);
		if(res.find(q) != res.end()) return false;
		else res.insert(q);
	}
	return true;
}

int main(){
	int t;cin>>t;
	vector<int> v(8);
	for(int i=0;i<8;i++) v[i]=i;
	int a,b;
	while(t--){
		cin>>a>>b;
		sort(v.begin(),v.end());
		vector< vector<int> > ans;
		do{
			if(v[b-1]!=a-1) continue;
			if(can(v)) ans.push_back(v);
		}while(next_permutation(v.begin(),v.end()));
		
		cout<<"SOLN       COLUMN\n";
		cout<<" #      1 2 3 4 5 6 7 8\n\n";
		for(int i=0;i<ans.size();i++){
			if(i<9)cout<<" "<<(i+1)<<"      ";
			else cout<<(i+1)<<"      ";
			for(int j=0;j<8;j++) cout<<ans[i][j]+1<<(char)(j+1==8?10:32);
		}
		if(t) cout<<'\n';
	}

	return 0;
}

