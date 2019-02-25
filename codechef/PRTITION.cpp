#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int M[1000005];
ll n,x;
void clear(){
	for(int i=1;i<=n;i++) M[i]=0;
}

void rec(int pos){
	if(pos==2){
		M[1] = 1;
		for(int i=3;i<=n-1;i++){
			if(M[i]==1 && M[i+1]==0){
				M[i] = 0;
				M[i+1] = 1;
				break;
			}
		}
	}else if(pos==1){
		for(int i=2;i<=n-1;i++){
			if(M[i]==1 && M[i+1]==0){
				M[i] = 0;
				M[i+1] = 1;
				break;
			}
		}
	}else{
		M[1] = 1;
		M[pos-1] = 1;
	}
}

void f(ll val,int pos){
	if(val==0) return;
	if(val<0){
		cout<<"tmr"<<endl;
		return;
	}
	if(M[pos] == 2){
		if(val==pos) rec(pos);
		else f(val,pos-1);
	}else{
		if(val==pos){
			M[pos] = 1;
		}else if(val>pos){
			M[pos] = 1;
			f(val-pos,pos-1);
		}else{
			f(val,val);
		}
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>x>>n;
		clear();
		if(n<=3){
			cout<<"impossible\n";
			continue;
		}
		M[x] = 2;
		ll val = (n*(n+1))/2 - x;
		if(val&1){
			cout<<"impossible\n";
		}else{
			f(val/2,n-1);
			for(int i=1;i<=n;i++) cout<<M[i];
			cout<<'\n';
		}
	}

	return 0;
}

