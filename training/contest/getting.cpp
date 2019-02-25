#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (2e5);
int n,m;ll t;

ll A[N+2];
ll B[N+2];

bool check(int x){
	ll d = B[x];
	if(d>t) return false;
	//cout<<"revisando "<<x<<" usando d="<<d<<endl;
	int cnt = 0;
	ll gaste = 0;
	ll cur = t;
	for(int i=1;i<=n;i++){
		if(A[i]<=d){
			if(A[i]>cur) break;
			cnt++;
			cur -= A[i];
			gaste += A[i];
			if(cnt%m==0) cur-=gaste,gaste=0;
		}
	}
	return cnt>=x;
}

void solve(){
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++) cin>>A[i],B[i]=A[i];
	sort(B+1,B+n+1);
	int lo=0,hi=n+1;
	while(hi-lo>1){
		int mi = (hi+lo)/2;
		if(check(mi)) lo=mi;
		else hi = mi;
	}
	//for(int i=0;i<=n;i++) cout<<i<<" "<<check(i)<<endl;
	ll d = B[lo];
	if(d>t || lo==0)d=t;
	cout<<lo<<" "<<d<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

