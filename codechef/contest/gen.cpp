#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> w;

bool valid(vector<int> v){
	vector<int> z(n);
	for(int i=0;i<n;i++){
		int p=i;
		z[i]++;
		while(i!=v[p]){
			p = v[p];
			z[p]++;
		}
	}
	for(int i=0;i<n;i++){
		if(z[i]!=w[i]) return false;
	}
	return true;
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<v.size();i++) v[i]=i;
		w.resize(n);
		for(int i=0;i<v.size();i++) cin>>w[i];
		int ans=0;
		do{
			if(valid(v)) ans++;
		}while(next_permutation(v.begin(),v.end()));
		cout<<ans<<endl;
	}

	return 0;
}

