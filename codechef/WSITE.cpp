#include<bits/stdc++.h>
using namespace std;
vector<string> a;
bool ok=0;

bool is(string x,string y){
	if(y.size()<x.size()) return false;
	string yy = y.substr(0,x.size());
	if(x==yy) return true;
	else return false;
}

string f(string x){
	int lo=0,hi=x.size()+1;
	while((hi-lo)>1){
		int mi=(lo+hi)/2;
		string s=x.substr(0,mi);
		int pos = lower_bound(a.begin(),a.end(),s) - a.begin();
		if(pos==a.size()) hi=mi;
		else if(is(s,a[pos])) lo=mi;
		else hi=mi;
	}
	if(hi==x.size()+1) ok=1;
	return x.substr(0,hi);
}

int main(){
	//fast_io()
	int n;cin>>n;
	vector< string > b;
	char s;string t;
	for(int i=0;i<n;i++){
		cin>>s>>t;
		if(s=='+') a.push_back(t);
		else b.push_back(t);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	set<string> S;
	for(int i=0;i<b.size();i++){
		S.insert(f(b[i]));
	}
	if(ok){
		cout<<"-1\n";
		return 0;
	}
	cout<<S.size()<<'\n';
	set<string> :: iterator it;
	for(it=S.begin();it!=S.end();it++){
		cout<<(*it)<<'\n';
	}
	
	return 0;
}

