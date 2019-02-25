#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int M[14] = {1,2,5,6,7,8,10,12,13,14,17,18,21,22};

bool is(int x){
	for(int i=0;i<14;i++){
		if(M[i]==x) return true;
	}
	return false;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int cnt = 1;
	int n;
	while(cin>>n){
		vector<string> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		if(is(cnt++)){
			cout<<n<<endl;
			for(int i=0;i<n;i++) cout<<v[i]<<endl;
		}
	}

	return 0;
}

