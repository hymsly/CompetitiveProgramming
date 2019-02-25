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
state st[N+5];
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

bool substring(string s){
	int i = 0, pos=0;	
	while(i<s.size()){
		state cur = st[pos];
		if(cur.next.find(s[i]) == cur.next.end()) return false;
		pos = cur.next[s[i]];
		i++;
	}
	return true;
}

int main(){
	sa_init();
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		sa_extend(s[i]);
	}
	int q;cin>>q;
	while(q--){
		cin>>s;
		if(substring(s)) cout<<"Y\n";
		else cout<<"N\n";
	}
}
