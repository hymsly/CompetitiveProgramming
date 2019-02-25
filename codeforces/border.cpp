#include<bits/stdc++.h>

using namespace std;

int n,k;

set<int> S;

int main(){
	cin>>n>>k;
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		S.insert(__gcd(k,num));
	}
	vector<int> v;
	set<int> :: iterator it;
	for(it=S.begin();it!=S.end();it++) v.push_back(*it);
	int val = v[0];
	for(int i=1;i<v.size();i++) val=__gcd(val,v[i]);
	cout<<k/val<<'\n';
	for(int i=0;i<k/val;i++) cout<<val*i<<(char)(i+1==k/val?10:32);

	return 0;
}

