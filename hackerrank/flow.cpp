//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#define _CRT_SECURE_NO_DEPRECATE
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<complex>
#include<set>
#include<algorithm>
 
using namespace std;
 
typedef unsigned long long      ui64;
typedef long long               i64;
typedef    vector<int>             VI;
typedef	vector<bool>            VB;
typedef	vector<VI>              VVI;
typedef	vector<string>          VS;
typedef	pair<int,int>           PII;
typedef map<string,int>         MSI;
typedef set<int>                SI;
typedef set<string>             SS;
typedef complex<double>         CD;
typedef vector< CD >            VCD;
typedef map<int,int>            MII;
typedef	pair<double,double>     PDD;
 
#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
 
#ifdef _DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif
 
const double PI = acos(-1.0);
 
typedef int FLOW;
typedef int COST;
const COST INF = 1000000000;
const FLOW FLOW_INF = 1000000000;
const int MAXN = 10000;
struct Edge {
	int b, c, u, f, back;
};
 
class MCMF {
private:
	int s, t, n;
	vector<Edge> g[MAXN];
public:
	MCMF(int _s, int _t, int _n) {
		s = _s;
		t = _t;
		n = _n;
	}
	void addEdge(int a, int b, int c, int u) {
		Edge e1 = {b,c,u,0,SZ(g[b])};
		Edge e2 = {a,-c,0,0,SZ(g[a])};
		g[a].PB(e1);
		g[b].PB(e2);
	}
	pair<FLOW,COST> minCostMaxFlow() {
		FLOW flow = 0;
		COST cost = 0;
		int *state = new int[n];
		int *from = new int[n];
		int *from_edge = new int[n];
		int *d = new int[n];
		int *q = new int[n];
		int qh, qt;
		qh = 0, qt = 0;
		while(true) {
			//find path
			FOR(i,0,n) state[i] = 2, d[i] = INF;
			memset(from,-1,sizeof(from));
 
			state[s] = 1;
			//deque<int> q;
			//q.push_back(s);
			q[qh++] = s;
			d[s] = 0;
			//while(!q.empty()) {
			while(qh!=qt) {
				//int v = q.front();
				//q.pop_front();
				int v = q[qt++];
				qt %= n;
				state[v] = 0;
				FOR(i,0,SZ(g[v])) if(g[v][i].f < g[v][i].u && d[g[v][i].b] > d[v] + g[v][i].c) {
					int to = g[v][i].b;
					d[to] = d[v] + g[v][i].c;
					from[to] = v;
					from_edge[to] = i;
					if(state[to]==1)
						continue;
					if(state[to]==0) {
						//q.push_front(to);
						qt--;if(qt==-1) qt = n-1;q[qt] = to;
 
						state[to] = 1;
					}
					else {
						//never touched before
						state[to] = 1;
						//q.push_back(to);
						q[qh++] = to;
						qh %= n;
					}
				}
			}
			if(d[t]==INF)
				break;
			int it = t;
			FLOW addflow = FLOW_INF;
			while(it!=s) {
				addflow = min(addflow, g[from[it]][from_edge[it]].u - g[from[it]][from_edge[it]].f);
				it = from[it];
			}
			it = t;
			while(it!=s) {
				g[from[it]][from_edge[it]].f += addflow;
				g[it][g[from[it]][from_edge[it]].back].f -= addflow;
				cost += g[from[it]][from_edge[it]].c * addflow;
 
				it = from[it];
			}
			flow += addflow;
		}
		return MP(flow, cost);
	}
};
 
int main() {
	int n, c1, c2;
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d",&n);
		VI cnt(n,0);
		FOR(i,0,n) {
			int tt;
			scanf("%d",&tt);
			tt--;
			cnt[tt]++;
		}
		c1 = n;
		c2 = c1+1;
		MCMF t(c1,c2,n+2);
		FOR(i,0,n) {
			t.addEdge(c1,i,0,cnt[i]);
			t.addEdge(i,c2,0,1);
		}
		int e;
		scanf("%d",&e);
		FOR(i,0,e) {
			int a, b;
			scanf("%d%d",&a,&b);
			a--;b--;
			t.addEdge(a,b,1,1000);
			t.addEdge(b,a,1,1000);
		}
		pair<FLOW,COST> res = t.minCostMaxFlow();
		printf("%d\n",res.Y);
	}
	return 0;
}
 
