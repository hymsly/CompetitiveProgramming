#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int,int> M;
map<int,int> N;

map<int,int> ansM;
map<int,int> ansN;

int func[10000004];

void criba(){
	for(ll i=2;i*i<=(10000000);i++){
		if(!func[i]){
			for(ll j=i*i;j<=(10000000);j+=i) func[j]=i;
		}
	}
	for(int i=2;i<=10000000;i++) if(!func[i]) func[i]=i;
}

void f(ll x){
	while(x>1){
		int val = func[x];
		while(x%val==0){
			M[val]++;
			x/=val;
		}
	}
	/*for(ll i=2;(i*i)<=x;i++){
		while(x%i==0){
			M[i]++;
			x/=i;
		}
	}
	if(x>1) M[x]++;*/
}

void ff(ll x){
	while(x>1){
		int val = func[x];
		while(x%val==0){
			N[val]++;
			x/=val;
		}
	}
	/*for(ll i=2;(i*i)<=x;i++){
		while(x%i==0){
			N[i]++;
			x/=i;
		}
	}
	if(x>1) N[x]++;*/
}

void procesar(){
	map<int,int> :: iterator it;
	for(it=M.begin();it!=M.end();it++){
		int primo=(*it).first;
		if(N.find(primo)!=N.end()){
			if( N[primo]<M[primo]){
				ansM[primo]=M[primo]-N[primo];
			}
		}
		else ansM[primo]=M[primo];
	}
	for(it=N.begin();it!=N.end();it++){
		int primo=(*it).first;
		if(M.find(primo)!=M.end()){
			if( N[primo] > M[primo]){
				ansN[primo]=N[primo]-M[primo];
			}
		}
		else ansN[primo]=N[primo];
	}
}

int tam(map<int,int> X){
	map<int,int> :: iterator it;
	int ans=0;
	for(it=X.begin();it!=X.end();it++){
		ans+=(*it).second;
	}
	return ans;
}

void mostrar(){
	cout<<max(1,tam(ansM))<<" "<<max(1,tam(ansN))<<endl;
	map<int,int> :: iterator it;
	if(ansM.size()==0) cout<<"1";
	for(it=ansM.begin();it!=ansM.end();it++){
		int primo=(*it).first;
		int cnt=(*it).second;
		for(int i=0;i<cnt;i++){
			cout<<primo<<" ";
		}
	}
	cout<<'\n';
	if(ansN.size()==0) cout<<"1";
	for(it=ansN.begin();it!=ansN.end();it++){
		int primo=(*it).first;
		int cnt=(*it).second;
		for(int i=0;i<cnt;i++){
			cout<<primo<<" ";
		}
	}
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	criba();	
	int n,m;cin>>n>>m;
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		f(num);
	}
	for(int i=0;i<m;i++){
		cin>>num;
		ff(num);
	}
	procesar();
	mostrar();
	return 0;
}
