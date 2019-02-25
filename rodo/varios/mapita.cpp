#include<bits/stdc++.h>

using namespace std;

int main(){
	map<int,int> M;
	int num;
	vector<int> v;
	while(cin>>num){
		if(!M.count(num)){
			v.push_back(num);
		}
		M[num]++;
	}
	for(int i=0;i<v.size();i++) cout<<v[i]<<" "<<M[v[i]]<<'\n';

	return 0;
}

