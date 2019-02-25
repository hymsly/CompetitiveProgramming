#include<bits/stdc++.h>

using namespace std;
const int N = (1e5);
int A[N+2];

int top(int x,int y){
	int ans = x/y;
	if(2*(x%y)>=y) ans++;
	return ans;
}
int cnt;
void solve(){
	int n,m;
	memset(A,0,sizeof A);
	cin>>n>>m;
	vector<int> aum;
	for(int i=1;i<=n;i++){
		int p = top(100*i,n);
		if(p>(100*i)/n) aum.push_back(i);
	}
	vector<int> v(m+1);
	v[0] = 0;
	int ans = 0;
	for(int i=1;i<=m;i++) cin>>v[i];
	for(int i=1;i<=m;i++) ans += top(100*v[i],n);
	int tot = n-accumulate(v.begin(),v.end(),0LL);
	vector<int> need(m+1);
	for(int i=0;i<=m;i++){
		int p = upper_bound(aum.begin(),aum.end(),v[i])-aum.begin();
		if(p==aum.size()) need[i]=-1;
		else need[i] = aum[p]-v[i];
	}
	cout<<ans<<endl;
	sort(need.begin(),need.end());
	for(int i=0;i<=m;i++){
		if(need[i]==-1) continue;
		if(need[i]<=tot){
			ans++;
			tot -= need[i];
		}else break;
	}
	cout<<"Case #"<<++cnt<<": "<<ans<<'\n';
}

int main(){
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

