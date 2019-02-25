#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool used[505];

int main(){
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	int n;
	while(t--){
		memset(used,0,sizeof(used));
		cin>>n;
		vector<int> v(n);
		v[0]=1;
		if(n>1) v[1]=2,used[2]=1,used[3]=1;
		used[1]=1;
		for(int i=2;i<n;i++){
			for(int j=1;j<=500;j++){
				if(!used[j]){
					v[i]=j;
					used[j]=1;
					for(int k=0;k<i;k++) used[j+v[k]]=1;
					break;
				}
			}
		}
		for(int i=0;i<n;i++) cout<<v[i]<<(char)(i+1==n?10:32);
	}

	return 0;
}


