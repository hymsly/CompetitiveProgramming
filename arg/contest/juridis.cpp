#include<bits/stdc++.h>

using namespace std;

vector< pair<int,int> > v;
vector< int > px;
vector< int > py;

void clear(){
	v.clear();
	px.clear();
	py.clear();
}
int n;

void solve(){
	clear();
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
		px.push_back(a);
		py.push_back(b);
	}
	sort(px.begin(),px.end());
	sort(py.begin(),py.end());
	sort(v.begin(),v.end());
	
	
	
}


int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

