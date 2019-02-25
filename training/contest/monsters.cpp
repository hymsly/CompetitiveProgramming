#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;

struct hero{
	int u,idx;ll hp;
	hero(){}
};

ll A[102],B[102],C[102];
vector< hero > v;

bool isvalid(hero x,int pos){
	int posicion = x.u;
	int valor = x.hp;
	if(posicion>=pos){
		for(int i=posicion;i>=pos;i--){
			valor += C[i];
			if(valor<0) return false;			
		}
	}else{
		for(int i=posicion;i<=pos;i++){
			valor += C[i];
			if(valor<0) return false;
		}
	}
	return true;
}

void clear(int pos1,int pos2){
	if(pos1>pos2) swap(pos1,pos2);
	for(int i=pos1;i<=pos2;i++) B[i]=0;
}

vector<int> getidx(int pos){
	vector< hero> cur;
	for(int i=0;i<v.size();i++) cur.push_back(v[i]);
	vector<int> ans;
	while(cur.size()){
		for(int i=1;i<=n;i++) C[i] = B[i];
		int idx = -1;
		int posicion = -1;
		for(int i=0;i<cur.size();i++){
			if(isvalid(cur[i],pos)){
				idx = cur[i].idx;
				posicion = i;
				break;
			}
		}
		if(idx==-1) return ans;
		clear(cur[posicion].u,pos);
		vector<hero> newcur;
		for(int i=0;i<cur.size();i++) if(i!=posicion)newcur.push_back(cur[i]);
		cur = newcur;
		ans.push_back(idx);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	v.resize(m);
	for(int i=0;i<m;i++) cin>>v[i].u>>v[i].hp,v[i].idx = i+1;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) B[j] = A[j];
		vector<int> idx = getidx(i);
		if(idx.size()==m){
			cout<<i<<'\n';
			for(int j=0;j<m;j++) cout<<idx[j]<<(char)(j+1==m?10:32);
			return 0;
		}
	}
	cout<<-1<<'\n';

	return 0;
}

