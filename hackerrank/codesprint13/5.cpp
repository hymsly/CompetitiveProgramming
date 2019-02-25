#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (1e5);
const int M = (4e5);

int pa[N+2];
int cnt[N+2];

struct BIT{
	ll tree[M+1];
	BIT(){
		for(int i=0;i<=M;i++) tree[i] = 0;
	}
	void Clear(){
		for(int i=0;i<=4*N;i++) tree[i] = 0;
	}
	ll Query(int i){
		ll sum = 0;
		while(i > 0){
			sum += tree[i];
			i -= ( i & -i );
		}
		return sum;
	}
	ll Cantidad(int i){
		return Query(i)-Query(i-1);
	}
	void Update(int i,ll val){
		while(i <= M){
			tree[i] += val;
			i += (i & -i);
		}
	}
} FT;


int Find(int x){
	return (x==pa[x]?x:pa[x]=Find(pa[x]));
}
set<int> S;//almacenamos las respuestas

void Union(int x,int y){
	int xx = Find(x);
	int yy = Find(y);
	if(xx==yy) return;
	pa[xx] = yy;
	FT.Update(cnt[yy],-1);
	FT.Update(cnt[xx],-1);
	if(FT.Cantidad(cnt[yy])==0) S.erase(cnt[yy]);
	if(FT.Cantidad(cnt[xx])==0) S.erase(cnt[xx]);
	cnt[yy] += cnt[xx];
	S.insert(cnt[yy]);
	FT.Update(cnt[yy],1);
}
int n;

ll query(ll maxi){
	set<int> :: iterator it;
	ll ans = 0;
	int ok=0;
	if(maxi == 0) ok=1;
	for(it=S.begin();it!=S.end();it++){
		int p = (*it);
		if(p<maxi) continue;
		ll canti = (FT.Cantidad(p));
		ans += canti*FT.Query(p-maxi-ok);
		if(ok==1){
			ans += (canti)*(canti-1)/2;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int q;cin>>n>>q;
	for(int i=1;i<=n;i++) cnt[i]=1;
	for(int i=1;i<=n;i++) pa[i]=i;
	FT.Clear();
	FT.Update(1,n);
	S.insert(1);
	int t;
	while(q--){
		cin>>t;
		if(t==1){
			int a,b;cin>>a>>b;
			Union(a,b);
		}else{
			int x;
			cin>>x;
			cout<<query(x)<<'\n';
		}
	}

	return 0;
}

