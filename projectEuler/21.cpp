#include<bits/stdc++.h>

using namespace std;

int d[10002];

int f(int x){
	int ans = 0;
	for(int i=1;i<x;i++){
		if(x%i==0) ans += i;
	}
	return ans;
}

int main(){
	for(int i=1;i<=10000;i++){
		d[i] = f(i);
	}
	int ans = 0;
	for(int i=1;i<=10000;i++){
		if(d[i] == i) continue;
		if(d[d[i]]==i) ans += i;
	}
	cout<<ans<<endl;

	return 0;
}

