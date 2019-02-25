#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int B = 29;
const ll MOD1 = (1e9 + 7);
const ll MOD2 = (1e9 + 9);
ll valorsum1,valormul1;
ll valorsum2,valormul2;
ll P1[20005];
ll P2[20005];
ll PR[50];
bool is_primo(ll x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

void init(){
	P1[0] = 1;
	for(int i=1;i<=20000;i++) P1[i] = (P1[i-1]*B)%MOD1;
	P2[0] = 1;
	for(int i=1;i<=20000;i++) P2[i] = (P2[i-1]*B)%MOD2;
	int i = 1;
	int j = 3;
	while(i<=26){
		if(is_primo(j)){
			PR[i++] = j;
		}
		j++;
	}
}

void getValor(string s){
	valorsum1 = 0;
	valormul1 = 1;
	for(int i=0;i<s.size();i++){
		valorsum1 += (PR[s[i]-'a'+1]);
		valorsum1 %= MOD1;
		valormul1 *= (PR[s[i]-'a'+1]);
		valormul1 %= MOD1;
	}
	valorsum2 = 0;
	valormul2 = 1;
	for(int i=0;i<s.size();i++){
		valorsum2 += (PR[s[i]-'a'+1]);
		valorsum2 %= MOD2;
		valormul2 *= (PR[s[i]-'a'+1]);
		valormul2 %= MOD2;
	}
}

map<pair<ll,ll>,int> M;

int ans[200005];

ll pot(ll x,ll y,ll modu){
	if(y==0) return 1;
	if(y==1) return x;
	ll val = 1;
	if(y&1) val = x;
	ll last = pot(x,y/2,modu);
	val *= last;
	val %= modu;
	val *= last;
	val %= modu;
	return val;
}

ll inv1(ll x){
	return pot(x,MOD1-2,MOD1);
}

ll inv2(ll x){
	return pot(x,MOD2-2,MOD2);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	init();
	int t;cin>>t;
	string a,b;
	while(t--){
		M.clear();
		memset(ans,0,sizeof ans);
		cin>>a>>b;
		getValor(a);
		ll val1 = 0;
		ll val2 = 0;
		ll actualsum1 = 0;
		ll actualmul1 = 1;
		ll actualsum2 = 0;
		ll actualmul2 = 1;
		for(int i=0;i<a.size();i++){
			int current = (b[i]-'a'+1);
			actualsum1 += (PR[current]);
			actualsum1 %= MOD1;
			actualmul1 *= (PR[current]);
			actualmul1 %= MOD1;
			actualsum2 += (PR[current]);
			actualsum2 %= MOD2;
			actualmul2 *= (PR[current]);
			actualmul2 %= MOD2;
			val1 += P1[a.size()-1-i]*(current);
			val1 %= MOD1;
			val2 += P2[a.size()-1-i]*(current);
			val2 %= MOD2;
		}
		for(int i=a.size();i<=b.size();i++){
			if(actualsum1 == valorsum1 && actualmul1 == valormul1 && actualsum2 == valorsum2 && actualmul2 == valormul2){				
				cout<<b.substr(i-a.size(),a.size())<<" "<<val1<<" "<<val2<<endl;
				pair<ll,ll> p = make_pair(val1,val2);
				if(M.count(p)){
					ans[M[p]]++;	
				}else{
					M[p] = i-a.size()-1;
					ans[i-a.size()+1]++;
				}
			}
			if(i==b.size()) break;
			int current = (b[i]-'a'+1);
			int last = (b[i-a.size()]-'a'+1);
			actualsum1 += (PR[current]);
			actualsum1 %= MOD1;
			actualmul1 *= (PR[current]);
			actualmul1 %= MOD1;
			actualsum2 += (PR[current]);
			actualsum2 %= MOD2;
			actualmul2 *= (PR[current]);
			actualmul2 %= MOD2;
			val1 += current;
			val1 %= MOD1;
			val2 += current;
			val2 %= MOD2;
			actualsum1 -= (PR[last]);
			actualsum1 %= MOD1;
			actualsum1 += MOD1;
			actualsum1 %= MOD1;
			actualmul1 *= inv1(PR[last]);
			actualmul1 %= MOD1;
			actualsum2 -= (PR[last]);
			actualsum2 %= MOD2;
			actualsum2 += MOD2;
			actualsum2 %= MOD2;
			actualmul2 *= inv2(PR[last]);
			actualmul2 %= MOD2;
			val1 -= (last)*P1[a.size()-1];
			val1 %= MOD1;
			val1 += MOD1;
			val1 %= MOD1;
			val1 *= B;
			val1 %= MOD1;
			val1 += current;
			val1 %= MOD1;
			val2 -= (last)*P2[a.size()-1];
			val2 %= MOD2;
			val2 += MOD2;
			val2 %= MOD2;
			val1 *= B;
			val1 %= MOD2;
			val2 += current;
			val2 %= MOD2;
		}
		vector<int> res;
		int maxi = 0;
		for(int i=0;i<b.size();i++){
			if(ans[i]==maxi){
				res.push_back(i);
			}else if(ans[i] > maxi){
				maxi = ans[i];
				res.clear();
				res.push_back(i);
			}
		}
		if(maxi==0) cout<<"-1\n";
		else{
			string respuesta = b.substr(res[0],a.size());
			for(int i=1;i<res.size();i++){
				string xx = b.substr(res[i],a.size());
				respuesta = min(respuesta,xx);
			}
			cout<<respuesta<<'\n';
		}
	}
	
	return 0;
}

