#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Mat{
	int M[5][5];
	Mat(){
		memset(M,0,sizeof M);
	}
	bool isValid(ll suma){
		for(int i=0;i<5;i++){
			M[i][0] = suma;
			for(int j=1;j<=4;j++){
				M[i][0]-=M[i][j];
			}
		}
		ll val = 0;
		for(int i=0;i<5;i++) val+=M[i][0];
		if(val!=suma) return false;
		ll val1=0,val2=0;
		for(int i=0;i<5;i++){
			val1+=M[i][i];
			val2+=M[i][4-i];
		}
		if(val1!=suma || val2!=suma) return false;
		return true;
	}
	Mat(vector<ll> masks){
		int pos=0;
		for(int i=1;i<=4;i++){
			ll val = masks[i-1];
			for(int j=0;j<5;j++){
				M[j][i] = val%3;
				val/=3;
			}
		}
	}
};

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll maxi = 3125;
	vector<ll> posible;
	vector<ll> G[21];
	for(ll mask=0;mask<maxi;mask++){
		int val=0;
		ll cur = mask;
		for(int i=0;i<5;i++){
			val+=(cur%4);
			cur/=4;
		}
		G[val].push_back(mask);
	}
	ll ans = 0;
	for(int i=0;i<=20;i++){
		int len = G[i].size();
		cout<<i<<" "<<len<<'\n';
		ans+=(len*len*len*len);
		continue;
		for(int a1=0;a1<len;a1++){
			for(int a2=0;a2<len;a2++){
				for(int a3=0;a3<len;a3++){
					for(int a4=0;a4<len;a4++){
						vector<ll> cons;
						cons.push_back(G[i][a1]);
						cons.push_back(G[i][a2]);
						cons.push_back(G[i][a3]);
						cons.push_back(G[i][a4]);
						Mat cur = Mat(cons);
						if(cur.isValid(len)) ans++;
					}	
				}
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}

