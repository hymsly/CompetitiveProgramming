#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main(){
	int t;cin>>t;
	int n;
	while(t--){
		cin>>n;
		v.resize(n);
		for(int i=0;i<n;i++) cin>>v[i];
		bool ok1=1,ok2=1;
		int num;
		for(int i=0;i<n;i++){
			cin>>num;
			if(num < v[i]) ok1=0;
			if(num < v[n-i-1]) ok2=0;
		}
		if(ok1 && ok2){
			cout<<"both\n";
		}else if(ok1){
			cout<<"front\n";
		}else if(ok2){
			cout<<"back\n";
		}else{
			cout<<"none\n";
		}
	}

	return 0;
}

