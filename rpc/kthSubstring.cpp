#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;
const int N = (1e5);

struct state {int len,link;map<char,int> next;}; //clear next!!
state st[2*N+5];
ll memo[2*N+5];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

ll dp(int x){
	if(memo[x] != -1) return memo[x];
	ll &ans = memo[x] = 1;
	for(map<char,int>::iterator it=st[x].next.begin();it!=st[x].next.end();it++) ans += dp((*it).second);
	return ans;
}

string ans = "";

map<char,char> decode;

string alpha;

void kth(ll x,int pos,char y){
	//cout<<x<<" "<<pos<<" "<<y<<endl;
	if(pos)ans.push_back(alpha[y-'a']);
	if(x==0) return;
	state cur = st[pos];
	ll act = 0,last = 0;
	for(map<char,int>::iterator it=cur.next.begin();it!=cur.next.end();it++){
		last = act;
		act += memo[(*it).second];
		if(act>=x){
			kth(x-last-1,(*it).second,(*it).first);
			break;
		}
	}
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
	string s;
	while(cin>>s>>alpha){
		memset(memo,-1,sizeof memo);
		decode.clear();
		for(int i=0;i<26;i++){
			decode[alpha[i]] = char(i+'a');
		}
		sa_init();
		for(int i=0;i<s.size();i++){
			sa_extend(decode[s[i]]);
		}
		ll tot = dp(0) - 1;
		int q;cin>>q;
		ll k;
		while(q--){
			cin>>k;
			if(k>tot) cout<<"*\n0\n";
			else{
				ans="";
				kth(k,0,'*');
				cout<<ans<<'\n';
				int numberOfOcurrences = kmp(s,ans);
				cout<<numberOfOcurrences<<'\n';
			}
		}
		for(int i=0;i<sz;i++) st[i].next.clear();
	}
}
