#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(vector<ll> x){
    if(x.size()<1) return 0;
    //for(int i=0;i<x.size();i++) cout<<x[i]<<(char)(i==x.size()-1?10:32);
    ll val=x[x.size()-1];
    if(val==0) return x.size()-1;
    if(val&1) return 0;
    val/=2;
    int pos = lower_bound(x.begin(),x.end(),val) - x.begin();
    int maxi=0;
    if(x[pos]==val){
        vector<ll> y;
        vector<ll> z;
        for(int i=0;i<=pos;i++) y.push_back(x[i]);
        for(int i=pos+1;i<x.size();i++) z.push_back(x[i]-val);    
        maxi=max(maxi,max(1 + f(y) , 1 + f(z) ) );
    }
    return maxi;
}

int main() {
    int t;cin>>t;
    int n;
    while(t--){
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<ll> acum(n);
        for(int i=0;i<n;i++){
            if(i) acum[i]=acum[i-1]+v[i];
            else acum[i]=v[i];
        }
        cout<<f(acum)<<endl;
    }
    
    return 0;
}

