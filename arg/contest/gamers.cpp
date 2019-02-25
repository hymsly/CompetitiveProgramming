#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (1<<9);

ll M[ N+2 ][ N+2 ];

void fill(int len,int x,int y,int xx,int yy,ll &val){//xx,yy punto inicial, x,y
	//cout<<"llenando: "<<x<<" "<<y<<"\ncon puntos iniciales "<<xx<<" "<<yy<<"\n con potencia "<<len<<" y valor="<<val<<endl;
	if(len==0) return;
	len--;
	int pot = (1<<len);
	pair<int,int> a[] = {{xx,yy},{xx+pot,yy},{xx,yy+pot},{xx+pot,yy+pot}};
	pair<int,int> f[] = {{xx+pot-1,yy+pot-1},{xx+pot+pot-1,yy+pot-1},{xx+pot-1,yy+pot+pot-1},{xx+pot+pot-1,yy+pot+pot-1}};
	pair<int,int> b[] = {{xx+pot-1,yy+pot-1},{xx+pot,yy+pot-1},{xx+pot-1,yy+pot},{xx+pot,yy+pot}};
	int index=val;
	for(int i=0;i<4;i++){
		if(x>=a[i].first && y>=a[i].second && x<=f[i].first && y<=f[i].second){
			if(len>0) fill(len,x,y,a[i].first,a[i].second,++val);
		}else{
			M[b[i].first][b[i].second]=index;
			if(len>0) fill(len,b[i].first,b[i].second,a[i].first,a[i].second,++val);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;cin>>n;
	int x,y;
	cin>>x>>y;
	ll val=1;
	fill(n,x,y,1,1,val);
	int len = (1<<n);
	for(int i=1;i<=len;i++){
		for(int j=1;j<=len;j++) cout<<M[i][j]<<(char)(j==len?10:32);
	}

	return 0;
}

