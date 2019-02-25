#include<bits/stdc++.h>

using namespace std;

int n,a;
int A[102];
bool vis[102];
int ans[102];

void solve(){
	memset(A,0,sizeof A);
	memset(vis,0,sizeof vis);
	memset(ans,0,sizeof ans);
	cin>>n>>a;
	for(int i=0;i<n;i++) cin>>A[i];
	//for(int i=0;i<n;i++) cout<<A[i]<<(char)(i+1==n?10:32);
	int res=0;
	for(int i=1;i<=n;i++){
		int maxi = 0;
		int resact = res;
		for(int j=0;j<n;j++){
			int pos = (res+j)%n;
			if(vis[pos]) continue;
			if(A[pos]>maxi){
				maxi = A[pos];
				resact = pos;
			}
		}
		//cout<<res<<endl;
		res = resact;
		ans[res] = i;
		vis[res] = 1;
	}
	//cout<<"------";
	cout<<ans[a]<<'\n';
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

