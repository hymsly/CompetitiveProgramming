#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> v(10);
	for(int i=0;i<10;i++) v[i] = i;
	int cnt = 1;
	do{
		if(cnt==1000000){
			for(int i=0;i<10;i++) cout<<v[i];
			cout<<endl;
			break;
		}
		cnt++;
	}while(next_permutation(v.begin(),v.end()));

	return 0;
}

