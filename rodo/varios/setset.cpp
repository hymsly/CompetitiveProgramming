#include<bits/stdc++.h>

using namespace std;

set<int> f(set<int> s,int n){
	int sum = 0;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	reverse(v.begin(),v.end());
	set<int> ans;
	for(int i=0;i<n;i++){
		sum += v[i];
		if(s.find(sum)!=s.end()) ans.insert(sum);
	}
	return ans;
}

int main(){
	int n1,n2,n3;cin>>n1>>n2>>n3;
	set<int> S;
	int sum = 0;
	vector<int> v(n1);
	for(int i=0;i<n1;i++) cin>>v[i];
	reverse(v.begin(),v.end());
	for(int i=0;i<n1;i++){
		sum += v[i];
		S.insert(sum);
	}
	set<int> ans = f(f(S,n2),n3);
	if(ans.empty()) cout<<"0\n";
	else cout<<(*ans.rbegin())<<'\n';

	return 0;
}

