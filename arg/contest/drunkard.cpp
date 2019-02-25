#include<bits/stdc++.h>

using namespace std;
int m,n,x,y;
int POT[11];

int cntnodo;
int ini=1;

int M[2000][2];

void graf(){
	for(int i=1;i<=cntnodo-2;i++){
		M[i + 2*ini][0] = (i+1==cntnodo - 1?1:i + 2*ini +1);
	}
	int posi = 31 - __builtin_clz(n);
	vector<int> v;
	M[posi+1 + 2*ini ][1] = cntnodo + 2*ini - 1;
	//return;
	//cout<<"el que llega a casa es "<<posi+1<<endl;
	for(int i=1;i<=cntnodo - 2;i++){
		if(x & (1<<i)){
			//cout<<"en mi mascara "<<i<<" "<<x<<endl;
			M[i+2 + 2*ini][1] = posi + 2*ini +1 ;
		}
	}
	for(int i=1;i<=cntnodo-2;i++){
		if(M[i + ini][1] == -1) v.push_back(i);
	}
	if(v.size()==0) return;
	if(v.size()==1){
		M[v[0] + 2*ini][1] = cntnodo + ini;
	}else{
		for(int i=1;i<v.size();i++){
			M[v[i] + 2*ini][1] = v[i] + 2*ini;
		}
		M[v[0] + 2*ini][1] = cntnodo + 2*ini;
	}
	
}

int start(int x){
	memset(M,-1,sizeof M);
	int val=0;
	while(x%2==0){
		val++;
		x/=2;
	}
	ini = val;
	for(int i=1;i<=ini;i++){
		M[2*i-1][0] = 2*i;
		M[2*i-1][1] = 2*i+1;
		M[2*i][0] = 2*i;
		M[2*i][1] = 2*i;
	}
	return x;
}

void calc(int p,int q){
	if(q%2==0) q/=2;
	else p*=2;
	int pot=0;
	for(pot;pot<11;pot++){
		if(POT[pot]>q) break;
	}
	y = POT[pot];
	// y-x == q
	x = y - q;
	int newp=p*(y-x);
	int newq=q*(y);
	int gcd = __gcd(newp,newq);
	m = newp/gcd;
	n = newq/gcd;
	cntnodo = 31 - __builtin_clz(y) + 2;
}


int main(){
	freopen("drunkard.in","r",stdin);
	freopen("drunkard.out","w",stdout);
	int p,q;
	POT[0] = 1;
	for(int i=1;i<=10;i++) POT[i] = 2*POT[i-1];
	while(cin>>p>>q){
		if(p==0 && q==0) break;
		int mult = __gcd(p,q);
		p /= mult;
		q /= mult;
		q = start(q);
		calc(p,q);
		//cout<<m<<"/"<<n<<"    "<<x<<"/"<<y<<endl;
		cout<<cntnodo+ini<<endl;
		graf();
		//cout<<cntnodo-2<<'\n';
		for(int i=1;i<=cntnodo+ini-2;i++) cout<<M[i][0]<<" "<<M[i][1]<<'\n';
	}		


	return 0;
}
