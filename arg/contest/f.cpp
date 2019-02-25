#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define REP(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N = (500);

ll M[N+5][N+5];

ll D[N+5][N+5];
int n;

ll act(){
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) ans+=D[i][j];
	}
	return ans;
}

vector<int> tengo;

void insertar(int x){//nodo x
	for(int i=0;i<tengo.size();i++){
		for(int j=0;j<tengo.size();j++){
			if(i==j) continue;
			int p = tengo[i],q = tengo[j];
			D[p][q] = min(D[p][q],M[p][x] + M[x][q]);
		}
	}
	for(int i=0;i<tengo.size();i++){
		for(int j=0;j<tengo.size();j++){
			//if(i==j) continue;
			int p = tengo[i],q = tengo[j];
			D[x][p] = min(M[x][p] , M[x][q] + D[q][p]);
			D[p][x] = min(M[p][x] , D[p][q] + M[q][x]);
		}
	}
	
}

void show(){
	cout<<"-------------\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<D[i][j]<<(char)(j==n?10:32);
	}
	for(int i=0;i<tengo.size();i++){
		cout<<tengo[i]<<(char)(i+1==tengo.size()?10:32);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>M[i][j];
		}	
	}
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	vector<ll> ans(n);
	for(int i=n-1;i>=0;i--){
		//inserto nodo:v[i]
		insertar(v[i]);
		show();
		ans[i] = act();
		tengo.push_back(v[i]);
	}
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<(char)(i+1==ans.size()?10:32);




	return 0;
}
