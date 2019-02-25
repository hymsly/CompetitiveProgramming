#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (100);
int n;
map<string,int> city;
map< pair<int,int> , int > nodo;//[time,cityId]
pair<int,int> decode[N*N+5];

vector<int> timer[N+2];

vector<int> G[N*N+5];

int memo[2405][N+2];

int dp(int curTime,int src,int dst){
	if(src==dst) return curTime;
	if(memo[curTime][src] != -1) return memo[curTime][src];
	int &ans = memo[curTime][src] = 2401;
	int p = upper_bound(timer[src].begin(),timer[src].end(),curTime) - timer[src].begin();
	if(p != timer[src].size()) ans = min (ans , dp(timer[src][p],src,dst));
	int nodoSearch = nodo[make_pair(curTime,src)];
	for(int i=0;i<G[nodoSearch].size();i++){
		pair<int,int> destino = decode[G[nodoSearch][i]];
		ans = min(ans,dp(destino.first,destino.second,dst));
	}
	return ans;
}

void show(int x){
	if(x<10) cout<<"000"<<x;
	else if(x<100) cout<<"00"<<x;
	else if(x<1000) cout<<"0"<<x;
	else cout<<x;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	while(cin>>n){
		if(n==0) break;
		city.clear();
		nodo.clear();
		memset(memo,-1,sizeof memo);
		for(int i=1;i<=N;i++) timer[i].clear();
		for(int i=1;i<=N*N;i++) G[i].clear();
		string s;
		for(int i=1;i<=n;i++){
			cin>>s;
			city[s] = i;
		}
		int m;
		cin>>m;
		vector< vector<pair<int,int> > > v;
		int cntNodo = 1;
		while(m--){
			int a;cin>>a;
			vector< pair<int,int> > cur(a);
			string str;
			for(int i=0;i<a;i++){
				cin>>cur[i].first;
				cin>>str;
				cur[i].second = city[str];
				timer[cur[i].second].push_back(cur[i].first);
				if(!nodo.count(cur[i])) nodo[cur[i]]=cntNodo++;
			}
			v.push_back(cur);
		}
		for(int i=1;i<=N;i++) sort(timer[i].begin(),timer[i].end());
		for(int i=0;i<v.size();i++){
			vector< pair<int,int> > &cur = v[i];
			for(int j=1;j<cur.size();j++){
				//union cur[j-1] && cur[j]
				G[nodo[cur[j-1]]].push_back(nodo[cur[j]]);
			}
		}
		map< pair<int,int> , int > :: iterator it;
		for(it=nodo.begin();it!=nodo.end();it++){
			decode[(*it).second] = (*it).first;
		}
		int timeIni;cin>>timeIni;
		string src,dst;cin>>src>>dst;
		int p = lower_bound(timer[city[src]].begin(),timer[city[src]].end(),timeIni) - timer[city[src]].begin();
		if(p==timer[city[src]].size()){
			cout<<"No connection\n";
			continue;
		}
		timeIni = timer[city[src]][p];
		int minimunTime = dp(timeIni,city[src],city[dst]);
		if(minimunTime == 2401){
			cout<<"No connection\n";
		}else{
			int maximunIni = timeIni;
			for(int i=p+1;i<timer[city[src]].size();i++){
				if(dp(timer[city[src]][i],city[src],city[dst]) == minimunTime){
					maximunIni = timer[city[src]][i];
				}
			}
			show(maximunIni);
			cout<<" ";
			show(minimunTime);
			cout<<'\n';
		}
	}

	return 0;
}

