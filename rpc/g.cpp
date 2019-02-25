#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = (1e5); 
ll SA[N+5],tempSA[N+5];
ll RA[N+5],tempRA[N+5];
ll c[N+5];
ll LCP[N+5],PLCP[N+5],Phi[N+5];
string str;
ll n;
string alpha;
string decode;

void counting_sort(ll k){
    ll maxi=max(300LL,n);
	memset(c,0,sizeof c);
    for(ll i=0; i<n; i++){
        ll a=i+k<n?RA[i+k]:0;
        c[a]++;
    }
    for(ll i=0,sum=0; i<maxi; i++){
        ll x=c[i];
        c[i]=sum;
        sum+=x;
    }
 
    for(ll i=0; i<n; i++){
        ll a=SA[i]+k<n?RA[SA[i]+k]:0;
        ll b=c[a];
        c[a]++;
        tempSA[b]=SA[i];
    }
 
    for(ll i=0; i<n; i++)
        SA[i]=tempSA[i];
}
 
void build_Suffix_Array(){
    for(ll i=0; i<n; i++){
        RA[i]=str[i];
        SA[i]=i;
    }
 
    for(ll k=1; k<n; k*=2){
        counting_sort(k);
        counting_sort(0);
        ll r=0;
        tempRA[SA[0]]=r=0;
        for(ll i=1; i<n; i++){
            if(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])
                tempRA[SA[i]]=r;
            else
                tempRA[SA[i]]=++r;
        }
        for(ll i=0; i<n; i++){
            RA[i]=tempRA[i];
        }
        if(RA[SA[n-1]]==n-1) break;
    }
}
 
void build_LCP(){
    Phi[SA[0]]=-1;
    for(ll i=1; i<n; i++)
        Phi[SA[i]]=SA[i-1];
    for(ll i=0,L=0; i<n; i++){
        if(Phi[i]==-1){
            PLCP[i]=0;
            continue;
        }
        while(str[i+L]==str[Phi[i]+L]) L++;
        PLCP[i]=L;
        L=max(L-1,0LL);
    }
 
    for(ll i=0; i<n; i++)
        LCP[i]=PLCP[SA[i]];
}
 
vector<ll> kmppre(string& t){ // r[i]: longest border of t[0,i)
	vector<ll> r(t.size()+1);r[0]=-1;
	ll j=-1;
	for(ll i=0;i<t.size();i++){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
ll kmp(string& s, string& t){ // find t in s
	ll j=0;vector<ll> b=kmppre(t);
	ll ans = 0;
	for(ll i=0;i<s.size();i++){
		while(j>=0&&s[i]!=t[j])j=b[j];
		if(++j==t.size())ans++,j=b[j];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	string s;
	while(cin>>s){
		cin>>alpha;
		decode.clear();
		for(ll i=0;i<26;i++) decode.push_back('a');
		for(ll i=0;i<26;i++){
			decode[alpha[i]-'a'] = char(i+'a');
		}
		str="";
		for(ll i=0;i<s.size();i++) str.push_back(decode[s[i]-'a']);
	    string str1=str;
	    str+="$";
	    n=str.size();
	    build_Suffix_Array();
	    build_LCP();
	    ll string_len=str1.size();
	    ll q;
		cin>>q;
	    while(q--){
	        ll k;
			cin>>k;
	        ll ans=0;
	        ll pos=0,len=0;
	        for(ll i=1;i<n;i++){
	            ll temp=string_len-SA[i]-LCP[i];
	            if(ans+temp<k) ans+=temp;
	            else{
	                pos=SA[i];
	                len=ans+temp-k;
	                len=LCP[i]+temp-len;
	                break;
	            }
	        }
	        string resp;
			if(len==0) cout<<"*\n0\n";
	        else{
				resp = str1.substr(pos,len);
				string answer = "";
	        	for(ll i=0;i<resp.size();i++) answer.push_back(alpha[resp[i]-'a']);
				cout<<answer<<'\n';
				cout<<kmp(s,answer)<<'\n';
			}
	    }
	}
 
    return 0;
}
