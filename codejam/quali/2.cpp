#include<bits/stdc++.h>

using namespace std;

int caso;

vector<int> merge(vector<int> a,vector<int> b){
	int i=0,j=0;
	vector<int> v;
	for(int k=0;k<a.size()+b.size();k++){
		if(k&1) v.push_back(a[i++]);
		else v.push_back(b[j++]);
	}
	return v;
}

void show(vector<int> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<(char)(i+1==v.size()?10:32);
}

void solve(){
	int n;cin>>n;
	vector<int> a,b;
	for(int i=0;i<n;i++){
		int num;cin>>num;
		if(i&1) a.push_back(num);
		else b.push_back(num);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	vector<int> v = merge(a,b);
	int ans = -1;
	for(int i=0;i<n-1;i++){
		if(v[i]>v[i+1]){
			ans = i;
			break;
		}
	}
	cout<<"Case #"<<++caso<<": ";
	if(ans==-1) cout<<"OK\n";
	else cout<<ans<<'\n';
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

