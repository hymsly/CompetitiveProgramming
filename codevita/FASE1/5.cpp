#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (8388608);
int n;
string M[5][5];
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,-1,-1,0,1,1};
struct Node{
	int board;//[0-65536>
	int x,y;//[0-4>
	int direccion;//[0-8>
	ll value;
	Node(){}
	Node(int _board,int _x,int _y,int _direccion,ll _value){
		board = _board;
		x = _x;
		y = _y;
		direccion = _direccion;
		value = _value;
	}
	void show(){
		cout<<"tablero "<<board<<endl;
		cout<<"posicion "<<x<<" "<<y<<endl;
		cout<<"direccion"<<" "<<dx[direccion]<<" "<<dy[direccion]<<endl;
		cout<<"respuesta "<<value<<endl;
		cout<<"---------\n";
	}
	int posicion(){
		return board+x*65536+y*65536*4+direccion*65536*4*4;
	}
};
bool operator <(const Node &a,const Node &b){
	return a.value < b.value;
}
ll D[N+2];

ll ans = 0;

int pos(int x,int y){
	return 1<<(n*y+x);
}

bool valid(int direccion,int board,int x,int y){
	int xx = x+dx[direccion];
	int yy = y+dy[direccion];
	if(xx<0 || xx>=n)return false;
	if(yy<0 || yy>=n)return false;
	if(board & (1<<(n*yy+xx))) return false;
	return true;
}

void bfs(){
	if(n==1) return;
	priority_queue<Node> Q;
	for(int i=5;i<8;i++) Q.push(Node(1,0,0,i,ans)),D[Node(1,0,0,i,ans).posicion()]=ans;
	while(!Q.empty()){
		Node p = Q.top();
		//p.show();
		Q.pop();
		for(int i=0;i<8;i++){
			if(valid(i,p.board,p.x,p.y)){
				int xx = p.x+dx[i];
				int yy = p.y+dy[i];
				ll newvalue = D[p.posicion()];
				if(i!=p.direccion) newvalue = max(0LL,newvalue-1);
				if(M[xx][yy]=="1")newvalue++;
				else if(M[xx][yy]=="#")newvalue*=2;
				else if(M[xx][yy]=="*")newvalue=0;
				else if(M[xx][yy]=="-1") newvalue=max(0LL,newvalue-1);
				Node pp = Node(p.board+pos(xx,yy),xx,yy,i,newvalue);
				if(D[pp.posicion()]<newvalue){
					D[pp.posicion()] = newvalue;
					Q.push(pp);
				}
			}
		}
	}
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=n-1;i>=0;i--)for(int j=0;j<n;j++) cin>>M[i][j];
	//for(int i=0;i<n;i++) for(int j=0;j<n;j++) cout<<M[i][j]<<(char)(j+1==n?10:32);
	if(M[0][0]=="1")ans = 1;
	bfs();
	for(int i=0;i<8388608;i++) ans =max(ans,D[i]);
	cout<<ans;

	return 0;
}

