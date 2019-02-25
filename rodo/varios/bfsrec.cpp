#include<bits/stdc++.h>

using namespace std;

int dx[]={1,1,1,-1,-1,-1,0,0},dy[]={0,1,-1,1,0,-1,1,-1};

string dir[]={"L","LU","LD","RU","R","RD","U","D"};
int M[9][9];
bool vis[9][9];

void rec(int x,int y,int val){
	if(val==0) return;
	for(int i=0;i<8;i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx<1 ||yy<1 ||xx>8 || yy>8) continue;
		if(M[xx][yy]==val-1){
			rec(xx,yy,val-1);
			cout<<dir[i]<<'\n';
			return;
		}
	}
}

pair<int,int> get(string x){
	pair<int,int> ans;
	ans.first = x[0]-'a'+1;
	ans.second = '9'-x[1];
	return ans;
}

void bfs(int x,int y){
	M[x][y] = 0;
	vis[x][y] = 1;
	queue<pair<int,int> > Q;
	Q.push(make_pair(x,y));
	while(!Q.empty()){
		pair<int,int> p = Q.front();
		Q.pop();
		pair<int,int> q;
		for(int i=0;i<8;i++){
			q.first = p.first +dx[i];
			q.second = p.second +dy[i];
			if(q.second < 1 || q.first < 1 || q.second > 8 || q.first >8) continue;
			if(vis[q.first][q.second]) continue;
			M[q.first][q.second] = M[p.first][p.second] + 1;
			vis[q.first][q.second] = 1;
			Q.push(q);
		}
	}
}

int main(){
	string a,b;cin>>a>>b;
	pair<int,int> p,q;
	p=get(a);
	q=get(b);
	bfs(p.first,p.second);
	cout<<M[q.first][q.second]<<'\n';
	rec(q.first,q.second,M[q.first][q.second]);

	return 0;
}

