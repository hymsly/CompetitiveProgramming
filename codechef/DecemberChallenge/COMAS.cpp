#include<bits/stdc++.h>

using namespace std;

vector<int> v;
int a,b;
int n;
int cnt;
bool vis[105];
void ask(){
	cout<<"? "<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<v[4]<<endl;
	cin>>a>>b;
}

void solve(){	
	memset(vis,0,sizeof vis);
	cin>>n;
	cnt = 0;
	while(cnt<=n-5){
		v.clear();
		int  pos = 1;
		while(v.size()<5){
			if(!vis[pos]) v.push_back(pos);
			pos++;
		}
		ask();
		vis[a] = 1;
		vis[b] = 1;
		cnt+=2;
	}
	//me queda 3 o 4
	v.clear();
	for(int i=1;i<=n,i++) if(!vis[i])v.push_back(i);
	while()
}

int main(){
	int t;cin>>t;
	while(t--) solve();
}
