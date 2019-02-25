#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull func(ull x){
	return (x*(x+1)/2);
}

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	ull a,b;
	while(t--){
		cin>>a>>b;
		ull val = a+b;
		ull piso = func(val);
		cout<<piso+a+1<<endl;
	}

	return 0;
}


