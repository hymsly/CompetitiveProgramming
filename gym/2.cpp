#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	//fast_io()
	string s;cin>>s;
	vector<pair<char,int> > v;
	char c = s[0];
	int cnt = 1; 
	for(int i=1;i<s.size();i++){
		if(s[i] == c) cnt++;
		else{
			v.push_back(make_pair(c,cnt));
			c = s[i];
			cnt = 1;
		}	
	}
	v.push_back(make_pair(c,cnt));
	for(int i=0;i<v.size();i++){
		cout<<v[i].first<<v[i].second;
	}
	cout<<endl;
	
	return 0;
}

