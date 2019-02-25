#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=(1e6);
set<int> S;
const int INF=(1e3);
int d[2*N+5];
vector<int> a;
bool vis[2*N+5];

void bfs(){
	queue<int> Q;
	for(int i=0;i<sz(a);i++){
		Q.push(a[i]);
		vis[a[i] + N]=1;
		d[a[i] + N]=1;
	}
	while(!Q.empty()){
		int p = Q.front();
		Q.pop();
		for(int i=0;i<sz(a);i++){
			int pp = p + a[i];
			if(vis[pp + N]) continue;
			Q.push(pp);
			d[pp + N] = d[p + N] + 1;
			vis[pp + N] = 1;
			if(pp == 0) return;
		}
	}
	
}

int main(){
	fast_io()
	int n,k;cin>>n>>k;
	bool ok=0;
	int num;
	int mini=INF;
	int maxi=0;
	for(int i=0;i<k;i++){
		cin>>num;
		mini=min(mini,num);
		maxi=max(maxi,num);
		S.insert(n-num);
		if(num==n) ok=1;
	}	
	if(ok) cout<<"1"<<endl;
	else if(n>maxi || n<mini) cout<<"-1"<<endl;
	else{
		set<int> :: iterator it;
		for(it=S.begin();it!=S.end();it++){
			a.pb((*it));
		}
		bfs();
		cout<<d[N]<<endl;
	}
	
	return 0;
}

