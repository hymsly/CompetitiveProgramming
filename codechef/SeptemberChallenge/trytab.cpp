#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (5);

int memo[(1<<N)][(1<<N)][N][N];

void show(int x,int y){
	vector<int> v(y,0);
	for(int i=0;i<y;i++) if(x&(1<<i)) v[i]=1;
	reverse(v.begin(),v.end());
	for(int i=0;i<y;i++) cout<<v[i];
	cout<<'\n';
}

int dp(int maskx,int masky,int x,int y){
	if(x==0) return (masky&(1<<(y-1)));
	if(y==0) return (maskx&(1<<(x-1)));
	int &ans = memo[maskx][masky][x][y] = 0;
	int xx = dp(maskx,masky,x-1,y);
	int yy = dp(maskx,masky,x,y-1);
	if(xx==1 && yy==1) ans=0;
	else ans = 1;
	return ans;
}

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	memset(memo,-1,sizeof memo);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<"posicion "<<i<<" "<<j<<endl;
			cout<<"pierde en"<<endl;
			for(int mask1 = 0;mask1<(1<<i);mask1++){
				for(int mask2=0;mask2<(1<<j);mask2++){
					int ans = dp(mask1,mask2,i,j);
					if(ans == 0){
						cout<<"-----\n";
						show(mask1,i);
						show(mask2,j);	
					}
				}
			}
		}
	}

	return 0;
}

