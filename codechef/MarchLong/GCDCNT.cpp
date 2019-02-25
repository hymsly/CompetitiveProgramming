#include<bits/stdc++.h>

using namespace std;

bool es(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	int cnt=0;
	for(int i=2;i<=1e5;i++){
		if(es(i)) cnt++;
	}
	cout<<cnt<<endl;

	return 0;
}

