#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =(2e5);
string s;
int n,m;
vector<int> G[N+3];
string ans;
string D[N+3];

struct Node{
	int u;
	string val;
	Node(){}
	Node(int _u,string _val){
		u = _u;
		val = _val;
	}
};

bool operator <(const Node a,const Node b){
	return a.val<b.val;
}

void djistra(int src,int dst){
	set<Node> Q;
	D[src] = string(1,s[src]);
	Q.insert(Node(src,D[src]));
	set<Node> :: iterator it;
	while(!Q.empty()){
		it = Q.begin();
		Node a = (*it);
		Q.erase(it);
		for(int i=0;i<G[a.u].size();i++){
			int v = G[a.u][i];
			if(D[v]==""){
				D[v] = D[a.u] + string(1,s[v]);
				Q.insert(Node(v,D[v]));
			}else if(D[v] > D[a.u] + string(1,s[v])){
				D[v] = D[a.u] + string(1,s[v]);
				Q.insert(Node(v,D[v]));
			}
		}
	}
	if(D[dst]=="") cout<<"No way\n";
	else cout<<D[dst]<<'\n';
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    cin>>s;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
    }
    int src,dst;
    cin>>src>>dst;
    src--;
    dst--;
	djistra(src,dst);

    return 0;
}
