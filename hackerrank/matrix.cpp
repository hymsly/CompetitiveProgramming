#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1e10);
int n,m;

ll M[502][502];
ll acum[502][502];
ll memo[502][502][502];
ll dp(int pos,int x,int y){
    if(pos==n+1){
        return 0;
    }
    if(memo[pos][x][y] != -INF) return memo[pos][x][y];
    ll &ans = memo[pos][x][y] = -INF;
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            if((i>=x && i<=y) || (j>=x && j<=y)) ans = max(ans,dp(pos+1,i,j) + acum[pos][j] - acum[pos][i-1] );
        }
    }
    return ans;
}

void clear(){
    for(int i=0;i<=500;i++){
        for(int j=0;j<=500;j++){
            for(int k=0;k<=500;k++) memo[i][j][k] = -INF;
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>M[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) acum[i][j] = acum[i][j-1] + M[i][j]; 
    }
    clear();
    ll ans = -INF;
    for(int i=1;i<=n;i++){
    	ans = max(ans,dp(0,i,i));
	}
    cout<<ans<<'\n';
    return 0;
}

