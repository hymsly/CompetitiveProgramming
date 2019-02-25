#include<bits/stdc++.h>

using namespace std;

int A[22];
int n;
void read(string s){
	stringstream ss(s);
	int num;
	memset(A,-1,sizeof A);
	n = 0;
	while(ss>>A[n++]){}
	n--;
}

int f(int mask){
	int ans = 0;
	for(int i=0;i<n;i++){
		if(mask & (1<<i)) ans+=A[i];
	}
	return ans;
}

int main(){
	int t;cin>>t;
	string s;
	getline(cin,s);
	while(t--){
		getline(cin,s);
		read(s);
		sort(A,A+n);
		set<int> S;
		for(int mask=1;mask<(1<<n)-1;mask++){
			S.insert(f(mask));
		}
		int val = f((1<<n)-1);
		if(val&1) cout<<"NO\n";
		else{
			if(S.find(val/2)!=S.end()) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}

	return 0;
}

