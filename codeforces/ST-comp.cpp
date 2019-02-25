#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
ll N=1;
int len=0;
vector<pair<ll,ll> > v;
map<ll,ll> M;
ll G[300010];

ll T[1048576];

ll res[100020];

ll query(int p){
	p+=N;
	ll ans = 0;
	while(p){
		ans += T[p];
		p>>=1;
	}
	return ans;
}

void update(int p,int q){//[p,q>
	p+=N;
	q+=N;
	while(p<q){
		if(p&1) T[p++]++;
		if(q&1) T[--q]++;
		p>>=1;
		q>>=1;
	}
}

void getans(){
	for(int i=0;i<len;i++){
		ll lo=G[i],hi=G[i+1];
		//cout<<"actualizando.."<<query(i)<<" "<<(hi-lo)<<'\n';
		res[query(i)]+=(hi-lo);
	}
}

void buildST(){
	for(int i=0;i<n;i++){
		update(M[v[i].first],M[v[i].second+1]);
	}
}

void compress(){
	set<ll> S;
	for(int i=0;i<n;i++) S.insert(v[i].first),S.insert(v[i].second),S.insert(v[i].second+1);
	set<ll> :: iterator it;
	for(it=S.begin();it!=S.end();it++){
		ll p = (*it);
		M[p] = len;
		G[len++]=p;
	}
	//for(int i=0;i<len;i++) cout<<G[i]<<(char)(i+1==len?10:32);
}

void read(){
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;	
	}
}

int main(){
	read();
	compress();
	while(N<len) N<<=1;
	buildST();
	getans();
	for(int i=1;i<=n;i++) cout<<res[i]<<(char)(i==n?10:32);

	return 0;
}

