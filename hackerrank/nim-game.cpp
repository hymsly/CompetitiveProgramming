#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> v(n);
    int val=0;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++) val^=v[i];
    int newval=0;
    map<int,long long> M;
    long long ans=0;
    M[0]++;
    for(int i=0;i<n;i++){
        newval^=v[i];
        int debe = newval^val;
		if(M.count(debe)) ans+=M[debe];
        M[newval]++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}

