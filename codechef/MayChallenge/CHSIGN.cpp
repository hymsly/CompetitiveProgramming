#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = (1e5);
 
vector<ll> v;
vector<ll> can;
 
bool puede(int x){
	if(x==0){
		if(v[x] >= v[x+1]) return false;
	}else if(x==v.size()-1){
		if(v[x] >= v[x-1]) return false;
	}else{
		if(v[x] >= v[x-1]) return false;
		if(v[x] >= v[x+1]) return false;
	}
	return true;
}
 
ll memo[N+2][2];
 
ll dp(int pos,bool tome){//tome true si reste al anterior
	if(memo[pos][tome] != -1) return memo[pos][tome];
	if(pos==can.size()) return 0;
	ll &ans = memo[pos][tome] = 0;
	ans = dp(pos+1,0);
	if(tome){
		int p = can[pos-1];
		int q = can[pos];
		ll val = -(v[p]+v[q]);
		for(int i=p+1;i<q;i++) val+=v[i];
		if(val > 0){
			ans = max(ans,v[can[pos]] + dp(pos+1,1));
		}
	}else{
		ans = max(ans,v[can[pos]] + dp(pos+1,1));
	}
	return ans;
}
int n;
vector<int> neg;
void rec(int pos,bool tome,ll res){
	//cout<<pos<<" "<<tome<<" "<<res<<endl;
	if(tome) neg.push_back(can[pos-1]);
	if(res==0) return;
	//if(pos==can.size()) return;
	if(res == memo[pos+1][0]){
		rec(pos+1,0,res);
	}else{
		rec(pos+1,1,res-v[can[pos]]);
	}
	return;
}
 
void solve(){
	can.clear();
	neg.clear();
	cin>>n;
	for(int i=0;i<n;i++){
		memo[i][0]=-1;
		memo[i][1]=-1;
	}
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++){
		if(puede(i)){
			can.push_back(i);
		}
	}
	ll ans = dp(0,0);
	rec(0,0,ans);
	for(int i=0;i<neg.size();i++) v[neg[i]]=-v[neg[i]];
	for(int i=0;i<n;i++) cout<<v[i]<<(char)(i+1==n?10:32);
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--) solve();
 
	return 0;
}
