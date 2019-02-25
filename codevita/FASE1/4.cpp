#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 40000;

bool vis[N+2];

struct data{
	ll inicial;
	ll monto;
	bool credit;//true suma, false resta
	bool existe;
	data(){
		monto = -1;
		inicial = 0;
		existe = false;
	}
} D[N+2];

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ld A;cin>>A;
	int n;cin>>n;
	int id;
	string s;
	for(int i=0;i<n-2;i++){
		cin>>id;
		cin>>D[id].monto;
		cin>>s;
		if(s=="credit") D[id].credit = true;
		else D[id].credit = false;
		cin>>D[id+1].inicial;
		D[id].inicial=D[id+1].inicial+(D[id].credit?-1:1)*D[id].monto;
		D[id].existe = true;
	}
	ld obtuve;cin>>obtuve;
	ll need = (ll)round((obtuve*36500.0L)/A);
	for(int i=2;i<=n+1;i++) need-=D[i].inicial;
	//me falta un 'need'
	int valor = -1;
	for(int i=1;i<=n;i++)if(!D[i].existe)valor=i;
	D[valor].inicial = need;
	D[valor].monto = abs(D[valor].inicial - D[valor+1].inicial);
	if(D[valor+1].inicial>D[valor].inicial)D[valor].credit = true;
	else D[valor].credit = false;
	D[valor-1].monto = abs(D[valor].inicial - D[valor-1].inicial);
	if(D[valor].inicial>D[valor-1].inicial)D[valor-1].credit = true;
	else D[valor-1].credit = false;
	cout<<valor-1<<" "<<D[valor-1].monto<<" "<<(D[valor-1].credit?"credit":"debit")<<" "<<D[valor].inicial<<'\n';
	cout<<valor<<" "<<D[valor].monto<<" "<<(D[valor].credit?"credit":"debit")<<" "<<D[valor+1].inicial<<'\n';

	return 0;
}

