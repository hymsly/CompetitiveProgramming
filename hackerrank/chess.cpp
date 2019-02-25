#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
pii k1,k2;

int dx[]={-1,-1,-1,0,0,0,1,1,1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};

bool vis[8][8];

void fill(pii x,pii a,pii b){
	pii z;
	vis[x.first][x.second] = 1;
	for(int i=0;i<9;i++){
		if(dx[i]==0 && dy[i]==0) continue;
		z = x;
		while(1){
			z.first += dx[i];
			z.second += dy[i];
			if(z.first < 0 || z.first > 7 || z.second < 0 || z.second > 7) break;
			vis[z.first][z.second] = 1;
			if(z==a || z==b) break;
		}
	}
}

bool posible(vector <pii> v){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			pii p = make_pair(k1.first+dx[i],k1.second+dy[i]);
			pii q = make_pair(k2.first+dx[i],k2.second+dy[i]);
			memset(vis,0,sizeof vis);
			for(int i=0;i<v.size();i++){
				if(v[i]==p || v[i]==q) continue;
				fill(v[i],p,q);
			}
			if(vis[p.first][p.second]==0 || vis[q.first][q.second]==0) return false;
		}
	}
	return true;
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>k1.first>>k1.second;
		cin>>k2.first>>k2.second;
		vector< pii > v;
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				pii p = make_pair(i,j);
				if(p==k1 || p==k2) continue;
				v.push_back(p);
			}
		}
		bool ok = 0;
		vector< pii > ans;
		for(int i=0;i<v.size()&&!ok;i++){
			for(int j=i+1;j<v.size()&&!ok;j++){
				vector <pii> can;
				can.push_back(v[i]);
				can.push_back(v[j]);
				if(posible(can)){
					ok = 1;
					ans = can;
					break;
				}
			}
		}
		for(int i=0;i<v.size()&&!ok;i++){
			for(int j=i+1;j<v.size()&&!ok;j++){
				for(int k=j+1;k<v.size()&&!ok;k++){
					vector <pii> can;
					can.push_back(v[i]);
					can.push_back(v[j]);
					can.push_back(v[k]);
					if(posible(can)){
						ok = 1;
						ans = can;
						break;
					}
				}
			}
		}
		for(int i=0;i<v.size()&&!ok;i++){
			for(int j=i+1;j<v.size()&&!ok;j++){
				for(int k=j+1;k<v.size()&&!ok;k++){
					for(int l=k+1;l<v.size()&&!ok;l++){
						vector <pii> can;
						can.push_back(v[i]);
						can.push_back(v[j]);
						can.push_back(v[k]);
						can.push_back(v[l]);
						if(posible(can)){
							ok = 1;
							ans = can;
							break;
						}
					}
				}
			}
		}
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++) cout<<"Q "<<ans[i].first<<" "<<ans[i].second<<'\n';
	}

	return 0;
}

