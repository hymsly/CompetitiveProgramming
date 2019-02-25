#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;

map<int,int> M;
vector<int> par;

int binary(int x){
    if(x<par[0]) return -1;
    if(x>M[par[par.size()-1]]) return -1;
    int lo=0,hi=par.size();
    while(hi-lo>1){
        int mi=(hi+lo)/2;
        if(x>=par[mi]) lo=mi;
        else hi=mi;
    }
    return lo;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;cin>>t;
    int n;
    vector<int> v;
    while(t--){
        M.clear();
        v.clear();
        par.clear();
        cin>>n;
        v.resize(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int q;cin>>q;
		vector<pii> pares(q);
		for(int i=0;i<q;i++) cin>>pares[i].first>>pares[i].second;
		sort(pares.begin(),pares.end());
        par.push_back(pares[0].first);
        M[pares[0].first]=pares[0].second;
        int last1=pares[0].first,last2=pares[0].second;
        for(int i=1;i<q;i++){
        	if(pares[i].first<=last2+1){
        		if(pares[i].second>last2){
					M[last1]=pares[i].second;
					last2=pares[i].second;
				}
			}else{
				M[pares[i].first] = pares[i].second;
				last1=pares[i].first;
				par.push_back(last1);
				last2=pares[i].second;
			}
		}
		/*for(int i=0;i<par.size();i++){
			cout<<par[i]<<" "<<M[par[i]]<<endl;
		}*/
        int ans=0;
        for(int i=0;i<n;i++){
            int pos=binary(v[i]);
            if(pos==-1) continue;
            if(M[par[pos]]>=v[i] && par[pos]<=v[i]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

