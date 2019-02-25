#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (600);

int cnt[N+2];


int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	int n,m,k;
	while(t--){
		memset(cnt,0,sizeof cnt);
		cin>>n>>m>>k;
		int a,b;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			cnt[a]++;cnt[b]++;
		}
		bool ok=1;
		for(int i=1;i<=n;i++){
			if(cnt[i]>=2*k+1) ok=0;
		}
		if(ok){
			for(int i=1;i<=m;i++) cout<<i<<(char)(i==m?10:32);
		}else{
			for(int i=1;i<=m;i++) cout<<0<<(char)(i==m?10:32);
		}
	}

	return 0;
}

