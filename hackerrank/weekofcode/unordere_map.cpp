#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M[27];

ll dp(int pos){
	if(pos==27) return 0;
	for(int i=pos+1;i<=26;i++){
		
	}
}

void solve() {
    for(int i=1;i<=26;i++) cin>>M[i];
    for(int i=1;i<=26;i++){
        if(M[i]>0){
            M[i]--;
            break;
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
    int t;cin>>t;
    while(t--) solve();

    return 0;
}
