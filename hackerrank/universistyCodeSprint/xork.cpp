#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e5);

ll A[N+2];
int n;
ll k;
vector<int> base;
int pot = 30;

ll trie[N*30 + 5][2];
int nodos = 1;
ll many[N*60 + 5];

void addWord(vector<int> s){
	int u = 0; //empezamos en la raíz
	for(int i=0; i<pot; ++i){
		int c = s[i];
		if( trie[u][c] == 0) trie[u][c] = nodos++; //si no existe pref creamos nodo
		u = trie[u][c];
		many[u]++;
	}
}

ll query(vector<int> rep){
	int u = 0;
	ll ans = 0;
	for(int i=0;i<pot;i++){
		int c = rep[i],d = base[i];
		if(c==d){
			if(c==1) ans += many[trie[u][1]];
			if(trie[u][0]) u = trie[u][0];
			else break;
		}else{
			if(c==0) ans += many[trie[u][0]];
			if(trie[u][1]) u = trie[u][1];
			else break;
		}
	}
	return ans;
}

vector<int> f(ll x){
	vector<int> v(pot,0);
	int posi = 0;
	while(x){
		v[posi++] = x%2;
		x/=2;
	}
	reverse(v.rbegin(),v.rend());
	return v;
}

void clear(){
	memset(A,0,sizeof A);
	memset(trie,0,sizeof trie);
	memset(many,0,sizeof many);
	nodos = 1;
}

void solve(){
	cin>>n>>k;
	base = f(k);
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++) A[i]^=A[i-1];
	ll ans = 0;
	addWord(f(0LL));
	for(int i=1;i<=n;i++){
		ans += query(f(A[i]));
		addWord(f(A[i]));
	}
	cout<<ans<<'\n';
	clear();
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}

