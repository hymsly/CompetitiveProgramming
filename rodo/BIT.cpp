#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (1e5);

ll bit1[N+2],bit2[N+2];

void update(ll bit[], int idx, ll val){
    while(idx <= N+1){
    	bit[idx] += val;
    	idx += (idx & -idx);
	}
}

ll query(ll bit[], int idx){
    ll ret = 0;
	while(idx){
		ret += bit[idx];
		idx -= (idx & -idx);
	}
    return ret;
}

int main(){
    int T,N,Q;
	cin>>T;    
    while(T--){
		cin>>N>>Q;
        memset(bit1,0,sizeof bit1);
        memset(bit2,0,sizeof bit2);
        int op,l,r;ll v;
        for(int i = 0;i < Q;++i){
			cin>>op>>l>>r;
            if(op == 0){
				cin>>v;
                update(bit1,l,v); update(bit1,r + 1,-v);
                update(bit2,l,-v * (l - 1)); update(bit2,r + 1,v * r);
            }else{
            	ll ans = query(bit1,r) * r + query(bit2,r) - query(bit1,l - 1) * (l - 1) - query(bit2,l - 1);
				cout<<ans<<'\n';
            }
        }
    }
    
    return 0;
}
