#include <bits/stdc++.h>

typedef long long lld;
typedef unsigned long long llu;
using namespace std;
const int MAXLEN = 100000;

struct state {
	int len, link;
	map<char,int> next;
};

state st[MAXLEN*2 + 2];//se crean a lo sumo 2*|s| nodos
int sz, last;

void sa_init(){ //inicializa el automata
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;
}

void sa_extend(char c){//agrega una letra al automata
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

string lcs (string t) {
	int v = 0,  l = 0, best = 0,  bestpos = 0;
	for (int i=0; i<(int)t.length(); ++i) {
		while (v && ! st[v].next.count(t[i])) {
			v = st[v].link;
			l = st[v].len;
		}
		if (st[v].next.count(t[i])) {
			v = st[v].next[t[i]];
			++l;
		}
		if (l > best)
			best = l,  bestpos = i;
	}
	return t.substr (bestpos-best+1, best);
}


int main(){
	string s;cin>>s;
	sa_init();
	for(int i=0;i<s.size();i++) sa_extend(s[i]);
    //pattern matching
    string t;cin>>t;
    string pattern = lcs(t);
    cout<<pattern.size()<<'\n';
    //number of diferents substring https://www.spoj.com/problems/SUBST1/
    /*DINAMIC PROGRAMMING
	dp(p) = 1+ SUM(dp(p.link))
	la respuesta esta en dp(s[0])
	*/
	
	//primera/ultima aparicion de P ,pattern
	/*
	dp(p) = max(dist a un aceptador);//primero
	dp(p) = min(dist a un aceptador);//ultimo
	*/
    
    return 0;
}
