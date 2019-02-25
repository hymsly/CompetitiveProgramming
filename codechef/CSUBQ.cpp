#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int M[500005];
int L,R;
int query(int l,int r){
	int ans = 0;
	for(int i=l;i<=r;i++){
		for(int j=i;j<=r;j++){
			int maxi = 0;
			for(int k=i;k<=j;k++) maxi = max(maxi,M[k]);
			if(maxi>=L && maxi<=R) ans++;
		}
	}
	return ans;
}

int main(){
	//ios_base::sync_with_stdio(0);
	int n,q;
	cin>>n>>q>>L>>R;
	int t,x,y;
	while(q--){
		cin>>t>>x>>y;
		if(t==1){
			M[x] = y;
		}else{
			cout<<query(x,y)<<'\n';
		}
	}

	return 0;
}

