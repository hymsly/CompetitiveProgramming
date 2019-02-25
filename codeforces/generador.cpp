#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int N = (1e5);
	cout<<N<<" "<<10<<'\n';
	for(int i=0;i<10;i++){
		for(int j=0;j<N;j++) cout<<(i+j)%N+1<<(char)(j+1==N?10:32);
	}


	return 0;
}

