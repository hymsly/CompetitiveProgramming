#include<bits/stdc++.h>

using namespace std;

int M[30000];

vector<int> ab;

int f(int x){
	int ans = 0;
	for(int i=1;i<x;i++){
		if(x%i==0){
			ans += i;
		}
	}
	return ans;
}

bool F[60005];

int main(){
	for(int i=1;i<30000;i++){
		if(f(i) > i) ab.push_back(i);
	}
	int n = ab.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			F[ab[i] + ab[j]] = 1;
		}
	}
	long long ans = 0;
	for(int i=1;i<=30000;i++){
		if(!F[i]) ans+=i;
	}
	cout<<ans<<endl;

	return 0;
}

