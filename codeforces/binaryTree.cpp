#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1e6);
int n,m;
vector<ll> C[N+2];

struct hijos{
	vector<ll> der,izq,acumDer,acumIzq;
};
hijos memo[N+2];

void pre(){
	for(int i=n;i>=1;i--){
		memo[i].der.push_back(0);
		memo[i].izq.push_back(0);
		if(2*i <= n){
			for(int j=0;j<memo[2*i].izq.size();j++) memo[i].izq.push_back(memo[2*i].izq[j]+C[i][0]);
			for(int j=1;j<memo[2*i].der.size();j++) memo[i].izq.push_back(memo[2*i].der[j]+C[i][0]);
		}
		if(2*i+1 <= n){
			for(int j=0;j<memo[2*i+1].der.size();j++) memo[i].der.push_back(memo[2*i+1].der[j]+C[i][1]);
			for(int j=1;j<memo[2*i+1].izq.size();j++) memo[i].der.push_back(memo[2*i+1].izq[j]+C[i][1]);
		}
		sort(memo[i].der.begin(),memo[i].der.end());
		sort(memo[i].izq.begin(),memo[i].izq.end());
	}
}


void acumular(){
	for(int i=1;i<=n;i++){
		int tam = memo[i].der.size();
		memo[i].acumDer.resize(tam);
		for(int j=0;j<tam;j++){
			if(j==0) memo[i].acumDer[j] = memo[i].der[j];
			else memo[i].acumDer[j] = memo[i].der[j] + memo[i].acumDer[j-1];
		}
	
		tam = memo[i].izq.size();
		memo[i].acumIzq.resize(tam);
		for(int j=0;j<tam;j++){
			if(j==0) memo[i].acumIzq[j] = memo[i].izq[j];
			else memo[i].acumIzq[j] = memo[i].izq[j] + memo[i].acumIzq[j-1];
		}
		
	}
}

ll f(int nodo,bool ok,ll x){
	if(ok){
		int lo=0,hi=memo[nodo].izq.size();
		while((hi-lo)>1){
			int mi = (lo+hi)/2;
			if(memo[nodo].izq[mi] <= x) lo=mi;
			else hi=mi;
		}
		return (x*(hi) - memo[nodo].acumIzq[lo]);
	}else{
		
		int lo=0,hi=memo[nodo].der.size();
		while((hi-lo)>1){
			int mi = (lo+hi)/2;
			if(memo[nodo].der[mi] <= x) lo=mi;
			else hi=mi;
		}
		return (x*(hi) - memo[nodo].acumDer[lo]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m;
	int num;
	for(int i=1;i<n;i++){
		cin>>num;
		C[(i+1)/2].push_back(num);
	}
	pre();
	acumular();
	int nodo;
	ll L;
	while(m--){
		ll ans = 0;
		cin>>nodo>>L;
		ans += f(nodo,0,L);
		ans += f(nodo,1,L);
		ans -= L;
		while(nodo>1){
			int dir = (nodo%2);
			nodo /= 2;
			L -= C[nodo][dir];
			if(L < 0) break;
			ans += f(nodo,dir,L);
		}
		cout<<ans<<'\n';
	}

	return 0;
}

