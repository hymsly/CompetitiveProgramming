#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v(4);

int caso;
int pot[4] = {1,3,9,27};

void solve(){
	for(int mask=0;mask<26;mask++){
		map<int,int> M;
		int cur = v[0];
		int zero = 1;
		for(int j=0;j<3;j++){
			int p = (mask/(pot[j]))%3;
			if( p == 0){
				zero++;
				M[cur]++;
				cur = v[j+1];
			}else if(p==1) cur+=v[j+1];
			else cur-=v[j+1];
		}
		M[cur]++;
		if(zero==1) continue;
		if(M.size()==1){
			//valido;
			cout<<"Case #"<<++caso<<": ";
			for(int i=0;i<4;i++){
				cout<<v[i]<<(char)(i==3?10:32);
				if(i==3) break;
				int p = (mask/(pot[i]))%3;
				if(p==0) cout<<"= ";
				else if(p==1) cout<<"+ ";
				else cout<<"- ";
			}
			return;
		}
	}
	
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;
	while(t--){
		for(int i=0;i<4;i++) cin>>v[i];
		solve();
	}

	return 0;
}

