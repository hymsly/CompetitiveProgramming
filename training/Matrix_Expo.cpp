#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll MOD=(1e9 + 7);
const int K = 4;//numero de recursiones
 
struct Matriz{
    ll M[K][K];
    Matriz(){
        for(int i=0;i<K;i++) for(int j=0;j<K;j++) M[i][j] = 0LL;
    }
    void iden(){
    	for(int i=0;i<K;i++) for(int j=0;j<K;j++) if(i==j) M[i][j] = 1;
	}
};
 
Matriz mult(Matriz a,Matriz b){
    Matriz ans;
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            a.M[i][j] %= MOD;
            a.M[i][j] += MOD;
            a.M[i][j] %= MOD;
            b.M[i][j] %= MOD;
            b.M[i][j] += MOD;
            b.M[i][j] %= MOD;
        }
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            for(int k=0;k<K;k++){
                ans.M[i][j] += a.M[i][k]*b.M[k][j];
                ans.M[i][j] %= MOD;
                ans.M[i][j] += MOD;
                ans.M[i][j] %= MOD;
            }
        }
    }
    return ans;
}
 
Matriz pot(Matriz a,ll b){
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            a.M[i][j] %= MOD;
            a.M[i][j] += MOD;
            a.M[i][j] %= MOD;
        }
    }
    Matriz ans;ans.iden();
    if(b==0) return ans;
    if(b==1) return a;
    if(b%2==1) ans = a;
    Matriz val = pot(a,b/2);
    ans = mult(ans,val);
    ans = mult(ans,val);
    return ans;
}
 
 
int main(){
    //a(n) = a(n-1) + 5a(n-2) + a(n-3) - a(n-4)
    /*
    	|0 0 0 -1|      |1 |   |
    	|1 0 0 1 |  *   |5 | = |
    	|0 1 0 5 |      |11|   |
    	|0 0 1 1 |      |36|   |
	*/
	ll n;cin>>n;
    if(n==1) cout<<"1\n"; 
    else if(n==2) cout<<"5\n";
    else if(n==3) cout<<"11\n";
    else if(n==4) cout<<"36\n";
    else{
        Matriz ans;
        ans.M[0][0] = 0LL;
        ans.M[0][1] = 0LL;
        ans.M[0][2] = 0LL;
        ans.M[0][3] = (MOD-1)*1LL;
        ans.M[1][0] = 1LL;
        ans.M[1][1] = 0LL;
        ans.M[1][2] = 0LL;
        ans.M[1][3] = 1LL;
        ans.M[2][0] = 0LL;
        ans.M[2][1] = 1LL;
        ans.M[2][2] = 0LL;
        ans.M[2][3] = 5LL;
        ans.M[3][0] = 0LL;
        ans.M[3][1] = 0LL;
        ans.M[3][2] = 1LL;
        ans.M[3][3] = 1LL;
        ans = pot(ans,n-4);
        /*for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<ans.M[i][j]<<" ";
            }
            cout<<endl;
        }*/
        vector<ll> a(4);
        a[0] = 1LL;
        a[1] = 5LL;
        a[2] = 11LL;
        a[3] = 36LL;
        ll res = 0;
        for(int i=0;i<4;i++){
            res += a[i]*ans.M[i][3];
            res %= MOD;
            res += MOD;
            res %= MOD;
        }
        cout<<res<<endl;
    }
}
