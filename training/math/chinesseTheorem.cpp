#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll,ll> > tup;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N = (100);
const int B = (10);
const ll INF = LLONG_MAX;
const pair<ll,ll> BASE = mp(-1,-1);

int G[N+2][B+2];
int inicial[B+2];
int n;
int vis[N+2];

vector<int> bucle(int animal){
	memset(vis,-1,sizeof vis);
	vector<int> ans(1,inicial[animal]);
	while(vis[ans.back()]==-1){
		vis[ans.back()]=ans.size()-1;
		ans.pb(G[ans.back()][animal]);
	}
	vector<int> res;
	for(int i=vis[ans.back()];i<ans.size()-1;i++) res.pb(ans[i]);
	return res;
}

tup extGcd(ll a,ll b){
	if(b==0)return mp(a,mp(1,0));
	tup ret = extGcd(b,a%b);
	return mp(ret.fi,mp(ret.se.se,ret.se.fi - (a/b)*ret.se.se));
}

ll inv(ll a,ll b){
	tup t = extGcd(a,b);
	ll inver = ((t.se.fi%b) + b)%b;
	return inver;
}

pair<ll,ll> chino(pair<ll,ll> a,pair<ll,ll> b){//(x.first)*k + x.second
	if(a==BASE || b==BASE) return BASE;
	a.se %= a.fi; b.se %= b.fi;
	if(a.fi==1) return b;
	if(b.fi==1) return a;
	ll commun = __gcd(a.first,b.first);
	if(commun!=1){//verificar si son compatibles
		if(a.se%commun != b.se%commun) return BASE;
		a.fi /= commun;
		a.se %= a.fi;
	}
	pair<ll,ll> ans = mp(a.first*b.first,0LL);
	ll y = inv(a.fi,b.fi);
	ans.se += (a.se*((b.fi*y)%ans.fi))%ans.fi;
	ans.se += (b.se*((a.fi*y)%ans.fi))%ans.fi;
	return ans;
}
int cnt[N+2];

ll getTime(int posFinal){
	
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int b;
	cin>>n>>b;
	for(int i=1;i<=b;i++){
		cin>>inicial[i];
		for(int j=1;j<=n;j++) cin>>G[j][i];
	}
	for(int i=1;i<=b;i++){
		vector<int> cur = bucle(i);
		for(int j=0;j<cur.size();j++) cnt[cur[j]]++;
	}
	ll ans = INF;
	for(int i=1;i<=n;i++){
		if(cnt[i]==b){//posible fin
			ans = min(ans,getTime(i));		
		}
	}

	return 0;
}

