#include<bits/stdc++.h>
using namespace std;
const int N = (1e5);

int n,m;
int R[N+2];//1..m
int C[N+2];//1..n
int RR[N+2],CC[N+2];
//int D[N+2][N+2];
string a,b;

int query(int x,int y){
	int dif = abs(x-y)+2;
	if(x==1) return R[y];
	if(y==1) return C[x];
	if(y>x) return RR[dif];
	else return CC[dif];
}

void solve(){
	cin>>a>>b;
	m = a.size();
	n = b.size();
	for(int i=1;i<=m;i++) R[i] = (a[i-1]-'0');
	for(int i=1;i<=n;i++) C[i] = (b[i-1]-'0');
	R[0] = C[1];
	C[0] = R[1];
	for(int i=1;i<=m;i++){
		if(R[i]==1 && R[i-1]==1) R[i]=0;
		else R[i] = 1;
	}
	for(int i=1;i<=n;i++){
		if(C[i]==1 && C[i-1]==1) C[i]=0;
		else C[i] = 1;
	}
	RR[1] = C[2];
	CC[1] = R[2];
	for(int i=2;i<=m;i++){
		if(R[i]==1 && RR[i-1]==1) RR[i]=0;
		else RR[i] = 1;
	}
	for(int i=2;i<=n;i++){
		if(C[i]==1 && CC[i-1]==1) CC[i]=0;
		else CC[i] = 1;
	}
	int q;cin>>q;
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<query(x,y);
	}
	cout<<'\n';
	/*for(int i=1;i<=n;i++) D[i][1] = C[i];
	for(int i=1;i<=m;i++) D[1][i] = R[i];
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(D[i-1][j]==1 && D[i][j-1]==1) D[i][j] = 0;
			else D[i][j] = 1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<D[i][j];
		cout<<endl;
	}
	cout<<"-----------\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<query(i,j);
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) if(query(i,j)!=D[i][j]) cout<<i<<" "<<j<<endl;
	}*/
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}
