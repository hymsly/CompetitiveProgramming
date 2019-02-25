#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,n) for(ll i = 0; i < n; i++)
#define pb push_back
#define ms(a,valor,n) FOR(i,n) a[i] = valor;
#define snum(x) scanf("%lld",&x)
#define INF (ll)(1e15)
#define MAX 111
using namespace std;

typedef long long ll;

struct Data{
	ll m[3];
};

deque<Data> d;

bool todoCero(){
	FOR(i,d.size()){
		FOR(j,3){
			if(d[i].m[j] > 0) return false;
		}
	}
	return true;
}

ll caso = 1;
void doit(){
	ll N;
	snum(N);
	d.clear();
	FOR(i,N){
		
		Data x;
		snum(x.m[0]);
		snum(x.m[1]);
		snum(x.m[2]);	
		d.pb(x);
	}
	
	ll resp = 0;
	int ok[3] ={-1,-1,-1};
	while(!todoCero()){
		

		FOR(i,d.size()){
			FOR(j,3){
				if(ok[j] == i){

					d[i].m[j]--;
					break;
				}
				else if(ok[j] == -1 && d[i].m[j] > 0){
					ok[j] = i;
					d[i].m[j]--;
					break;
				}
				
				if(d[i].m[j] > 0) break;
			
			}
		}
		
		
		
		/*
		FOR(i,d.size()){
			FOR(j,3){
			
				debug(d[i].m[j]);
			}
		}
		cout << endl;*/
		
		FOR(j,3){
			if(ok[j] != -1 && d[ok[j]].m[j] == 0){
			ok[j] = -1;
		}
		}
		
		resp++;
		
	}
	
	printf("Case #%lld: %lld\n",caso,resp);
	caso++;
}

int main() {
   ll T;
   snum(T);
   while(T--){
	doit();
   }

    return 0;
}

