#include<bits/stdc++.h>

using namespace std;
const int N = (1e5);

int f,s,t,mini,maxi;

struct group{
	int a,b,c;
	group(){
		a=0;
		b=0;
		c=0;
	}
	group(int _a,int _b,int _c){
		a=_a;
		b=_b;
		c=_c;
	}
	void show(){
		cout<<"----grupo----\n";
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	bool possible(){
		if(a > f) return false;
		if(b > s) return false;
		if(c > t) return false;
		if(a+b+c > maxi) return false;
		return true;
	}
	bool cumple(){
		if(a+b+c<mini) return false;
		return true;
	}
	int cnt(){
		return a+b+c;
	}
};

int pa[N+2];
group M[N+2];

int Find(int x){
	return (pa[x]==x?x:pa[x]=Find(pa[x]));
}

void Union(int x,int y){
	int xx = Find(x);
	int yy = Find(y);
	if(xx==yy) return;
	group pos = group(M[xx].a + M[yy].a,M[xx].b + M[yy].b,M[xx].c + M[yy].c);
	//pos.show();
	if(pos.possible()){
		pa[xx] = yy;
		M[yy] = pos;
	}else return;
}

string name[N+2];
map<string,int> mapita;
int main(){
	int n,m;cin>>n>>m;
	cin>>mini>>maxi>>f>>s>>t;
	string str;int grade;
	for(int i=1;i<=n;i++){
		pa[i] = i;
		cin>>str>>grade;
		name[i] = str;
		mapita[str] = i;
		if(grade==1) M[i] = group(1,0,0);
		else if(grade==2) M[i] = group(0,1,0);
		else M[i] = group(0,0,1);
	}
	/*for(int i=1;i<=n;i++){
		M[i].show();
	}*/
	string str1,str2;
	while(m--){
		cin>>str1>>str2;
		Union(mapita[str1],mapita[str2]);
	}
	int cnt = 0;
	set<int> res;
	for(int i=1;i<=n;i++){
		int p = Find(i);
		//M[p].show();
		if(M[p].cumple()){
			int cantidad = M[p].cnt();
			if(cantidad == cnt){
				res.insert(p);
			}else if(cantidad > cnt){
				res.clear();
				res.insert(p);
				cnt = cantidad;
			}
		}
	}
	vector<string> respuesta;
	for(int i=1;i<=n;i++){
		int p = Find(i);
		if(res.find(p) != res.end()){
			respuesta.push_back(name[i]);
		}
	}
	sort(respuesta.begin(),respuesta.end());
	if(respuesta.size()==0){
		cout<<"no groups\n";
	}else{
		for(int i=0;i<respuesta.size();i++) cout<<respuesta[i]<<'\n';
	}

	return 0;
}

