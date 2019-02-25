#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld INF = LDBL_MAX;
const int N =(2e5);
const ld B = (1.0 + 5e-2);
const ld EPS = (1e-9);
ld A[30];
string s;
int n,m;
vector<int> G[N+3];
vector<int> GREV[N+3];

ld D[N+3];
int dep[N+3];
ld POT[N+3];

ld resto(ld x,ld y){
	ld ans = x/y;
	ans = floor(ans);
	return x-ans*y;
}
string ans;

bool dist(ld distAnt,int profAnt,ld distNew,int profnew){
	if(profAnt == profnew) return distNew<distAnt;
	if(profAnt > profnew){
		distAnt -= resto(distAnt,POT[profAnt - profnew]);
		distAnt /= POT[profAnt - profnew];
		if(abs(distNew - distAnt) < EPS) return true;
		return distNew < distAnt;
	}else{
		distNew -= resto(distNew,POT[profnew - profAnt]);
		distNew /= POT[profnew - profAnt];
		if(abs(distNew - distAnt) < EPS) return false;
		return distNew < distAnt;
	}
}
int dst;
bool vis[N+2];
ld dp(int x){
	if(x==dst){
		vis[x] = 1;
		dep[x] = 0;
		return 0.0L;
	}
	if(vis[x]) return D[x];
	vis[x] = 1;
	if(G[x].size()==0){
		dep[x] = N+2;
		return (D[x] = INF);
	}
	ld &ans = D[x] = dp(G[x][0])*B+A[s[G[x][0]]-'a'];
	int curDepth = dep[G[x][0]] + 1;
	int newnodo = G[x][0];
	for(int i=1;i<G[x].size();i++){
		ld tryDist = dp(G[x][i])*B + A[s[G[x][i]]-'a'];
		if(dist(ans,curDepth,tryDist,dep[G[x][i]]+1)){
			ans = tryDist;
			curDepth = dep[G[x][i]]+1;
			newnodo = G[x][i];
		}
	}
	dep[x] = curDepth;
	return ans;
}

void rec(ld dist,int prof,int nodo){
	//cout<<dist<<" "<<prof<<" "<<nodo<<endl;
	ans.push_back(s[nodo]);
	if(dist<EPS){
		return;
	}
	for(int i=0;i<G[nodo].size();i++){
		int p = G[nodo][i];
		ld newdist = dp(p);
		int newprof = dep[p];
		//cout<<newprof<<" "<<newdist<<endl;
		if(newprof+1==prof && abs(newdist*B+A[s[p]-'a']-dist) < EPS){
			rec(newdist,newprof,p);
			return;
		}
	}
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    for(int i=0;i<26;i++){
    	A[i] = ((ld)(i+1)*B)/27.0L;
	}
	POT[0] = 1.0L;
	for(int i=1;i<=N;i++) POT[i] = B*POT[i-1];
    //for(int i=0;i<=26;i++) printf("%.6f ",(double) A[i]);
    //cout<<endl;
    cin>>n>>m;
    cin>>s;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        GREV[b].push_back(a);
    }
    int src;cin>>src>>dst;
    src--;
    dst--;
    //djistra(src,dst);
    ld res = dp(src);
    if(!vis[dst]){
    	cout<<"No way\n";
    	return 0;
	}
    ans = "";
    rec(res,dep[src],src);
	cout<<ans<<'\n';

    return 0;
}

