#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX;
#define mp make_pair
#define fi first
#define fst first
#define snd second
#define se second
int animal,zoo;

struct tup{
	ll gcd,x,y;
	tup(){}
	tup(ll _gcd,ll _x,ll _y){
		gcd=_gcd;x=_x;y=_y;
	}
};

tup extGcd(ll a,ll b){
	if(b==0)return tup(a,1,0);
	tup ret = extGcd(b,a%b);
	return tup(ret.gcd,ret.y,((ret.x - a/b*ret.y)));
}

ll inv(ll a,ll b){
	tup t = extGcd(a,b);
	ll inverse = (t.x%b+b)%b;
	return inverse;
}

int G[12][102];

ll fiBucle[12];
ll lenBucle[12];
ll dist[12][102];
ll inic[12];
ll vis[102];//cuantos son parte del bucle

void getData(int id,int pos){
	ll maxi = 0;
	for(int i=1;i<=zoo;i++){
		if(dist[id][i]!=-1)maxi = max(maxi,dist[id][i]);
		if(dist[id][i]>=dist[id][fiBucle[id]]) vis[i]++;
	}
	lenBucle[id] = maxi - dist[id][fiBucle[id]] + 1;
}

void dfs(int id,int pos){
	if(dist[id][G[id][pos]] != -1){
		fiBucle[id] = G[id][pos];
		return;
	}
	dist[id][G[id][pos]] = dist[id][pos] + 1;
	dfs(id,G[id][pos]);
}

ll posible[102];

ll sum(ll a,ll b,ll mod){
	a%=mod;
	b%=mod;
	ll rest1=a%4,rest2=b%4;
	ll val1=a/4,val2=b/4;
	ll val = (val1 + val2)%mod;
	ll ans = rest1+rest2;
	ans += val;
	ans %= mod;
	ans +=val;
	ans %= mod;
	ans += val;
	ans %= mod;
	ans += val;
	ans %= mod;
	return ans;
}

ll mult(ll a,ll b,ll mod){
	a%=mod;
	b%=mod;
	if(b==0) return 0;
	if(b==1) return a;
	ll val = mult(a,b/2,mod);
	if(b&1)return sum(a,sum(val,val,mod),mod);
	return sum(0,sum(val,val,mod),mod);
}


pair<ll,ll> extendedEuclid (ll a, ll b){ //a * x + b * y = gcd(a,b)
	ll x,y;
	if (b==0) return mp(1,0);
	pair<ll,ll> p=extendedEuclid(b,a%b);
	x=p.snd;
	y=p.fst-(a/b)*x;
	if(a*x+b*y==-__gcd(a,b)) x=-x, y=-y;
	return mp(x,y);
}
pair<pair<ll,ll>,pair<ll,ll> > diophantine(ll a,ll b, ll r) {
	//a*x+b*y=r where r is multiple of gcd(a,b);
	ll d=__gcd(a,b);
	a/=d; b/=d; r/=d;
	pair<ll,ll> p = extendedEuclid(a,b);
	p.fst*=r; p.snd*=r;
	assert(a*p.fst+b*p.snd==r);
	return mp(p,mp(-b,a)); // solutions: p+t*ans.snd
}

#define mod(a,m) (((a)%m+m)%m)
pair<ll,ll> sol(tuple<ll,ll,ll> c){ //requires inv, diophantine
    ll a=get<0>(c), x1=get<1>(c), m=get<2>(c), d=gcd(a,m);
    if(d==1) return mp(mod(x1*inv(a,m),m), m);
    else return x1%d ? mp(-1LL,-1LL) : sol(make_tuple(a/d,x1/d,m/d));
}
pair<ll,ll> crt(vector< tuple<ll,ll,ll> > cond) { // returns: (sol, lcm)
	ll x1=0,m1=1,x2,m2;
	for(auto t:cond){
		tie(x2,m2)=sol(t);
		if((x1-x2)%gcd(m1,m2))return mp(-1,-1);
		if(m1==m2)continue;
		ll k=diophantine(m2,-m1,x1-x2).fst.snd,l=m1*(m2/gcd(m1,m2));
		x1=mod((__int128)m1*k+x1,l);m1=l;
	}
	return sol(make_tuple(1,x1,m1));
} //cond[i]={ai,bi,mi} ai*xi=bi (mi); assumes lcm fits in ll

int value(int id,int time,int pos){
	if(time==0) return pos;
	return value(id,time-1,G[id][pos]);
}

bool valid(){
	for(int i=0;i<=zoo;i++){
		set<int> S;
		for(int j=1;j<=animal;j++){
			S.insert(value(j,i,inic[j]));
		}
		if(S.size()==1){
			cout<<(*S.begin())<<" "<<i<<'\n';
			return true;
		}
	}
	return false;
}

bool operator ==(const pair<ll,ll> &a,const pair<ll,ll> &b){
	return a.fi==b.fi&&a.se==b.se;
}

ll lcm(ll a,ll b){
	return (a/__gcd(a,b))*b;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>animal>>zoo;
	memset(dist,-1,sizeof dist);
	for(int i=1;i<=animal;i++){
		cin>>inic[i];
		for(int j=1;j<=zoo;j++)cin>>G[i][j];
	}
	if(valid())return 0;
	for(int i=1;i<=animal;i++){
		dist[i][inic[i]] = 0;
		dfs(i,inic[i]);
		getData(i,inic[i]);
	}
	ll val = 1;
	for(int i=1;i<=animal;i++){
		val = lcm(val,lenBucle[i]);
		//cout<<lenBucle[i]<<" "<<val<<endl;
	}
	vector<int> posiblesFinales;
	for(int i=1;i<=zoo;i++)if(vis[i]==animal)posiblesFinales.push_back(i);
	ll ans = INF;int posicion=-1;
	for(int i=0;i<posiblesFinales.size();i++){
		pair<ll,ll> res= mp(1,0);//multiplo de fi + resto se
		cout<<posiblesFinales[i]<<endl;
		for(int j=1;j<=animal;j++){
			pair<ll,ll> cur = mp(lenBucle[j],dist[j][posiblesFinales[i]]);
			if(cur.se==-1) continue;
			res = chino(res,cur);
			if(res.fi ==-1 && res.se==-1) break;
			cout<<cur.fi<<" "<<cur.se<<"------"<<res.fi<<" "<<res.se<<endl;
		}
		if(res.fi==-1&&res.se==-1) continue;
		if(res.second < ans){
			ans = res.second;
			posicion = posiblesFinales[i];
		}
	}
	if(posicion==-1)cout<<"*\n";
	else cout<<posicion<<" "<<ans<<'\n';

	return 0;
}

