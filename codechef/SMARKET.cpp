#include <cstdio>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 111111;
const int BLOCK = 333;
const int A = 1111111;

int a[N], ans[N];
int answer[N];
deque<pair<int,int> > D;

struct node {
	int L, R, i, k;
	inline pair<int, int> toPair() const {
		return make_pair(L/BLOCK, ((L/BLOCK) & 1) ? -R : +R);
	}
}q[N];

bool operator <(const node &a,const node &b){
	return a.toPair()<b.toPair();
}

void add1(int position) {
	if(D.size()){
		if(D[0].second != a[position] ) D.push_front(make_pair(1,a[position]));
		else D[0].first++;
	}
	else D.push_front(make_pair(1,a[position]));
	answer[D[0].first-1]++;
}

void remove1(int position) {
	if(D[0].first==1){
		D.pop_front();
		answer[0]--;
	}
	else{
		answer[D[0].first-1]--;
		D[0].first--;
	}
}
void add2(int position) {
	if(D.size()){
		if(D[D.size()-1].second != a[position] ) D.push_back(make_pair(1,a[position]));
		else D[D.size()-1].first++;
	}else{
		D.push_back(make_pair(1,a[position]));
	}
	answer[D[D.size()-1].first-1]++;
}

void remove2(int position) {
	if(D[D.size()-1].first==1){
		D.pop_back();
		answer[0]--;
	}
	else{
		answer[D[D.size()-1].first-1]--;
		D[D.size()-1].first--;
	}
}


int main() {
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		D.clear();
		memset(answer,0,sizeof(answer));
		memset(a,0,sizeof(a));
		scanf("%d", &n);
		scanf("%d", &m);
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
	
		for(int i=0; i<m; i++) {
			scanf("%d%d%d", &q[i].L, &q[i].R , &q[i].k);
			q[i].L--; q[i].R--;q[i].k--;
			q[i].i = i;
		}
		sort(q, q + m);
		int currentL = 0, currentR = 0;
		for(int i=0; i<m; i++) {
			int L = q[i].L, R = q[i].R;
			while(currentR <= R) {
				add2(currentR);
				currentR++;
			}
			while(currentR > R+1) {
				remove2(currentR-1);
				currentR--;
			}
			while(currentL < L) {
				remove1(currentL);
				currentL++;
			}
			while(currentL > L) {
				add1(currentL-1);
				currentL--;
			}
			ans[q[i].i] = answer[q[i].k];
		}
	
		for(int i=0; i<m; i++)
			printf("%d\n", ans[i]);
	}
}
