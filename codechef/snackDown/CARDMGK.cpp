#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e5);
const int INF = (1e9+1);

int A[2*N+5];

void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>A[i],A[i+n]=A[i];
	int mini = INF+1;
	int pos = 0;
	bool shuffle=0;
	for(int i=1;i<=n;i++){
		if(A[i]<mini) mini = A[i],pos=i,shuffle=0;
		else if(A[i]==mini){
			if(shuffle) pos=i,shuffle=0;
		}
		else shuffle=1;
	}
	bool ok=1;
	for(int i=1;i<n;i++){
		if(A[pos+i-1]>A[pos+i]) ok=0;
	}
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

