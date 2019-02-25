#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb(x) push_back(x)

typedef ll tp; // type of polynomial
template<class T=tp>
struct poly {  // poly<> : 1 variable, poly<poly<>>: 2 variables, etc.
	vector<T> c;
	T& operator[](ll k){return c[k];}
	poly(vector<T>& c):c(c){}
	poly(ll k):c(k){}
	poly(){}
	poly operator+(poly<T> o){
		int m=c.size(),n=o.c.size();
		poly res(max(m,n));
		fore(i,0,m)res[i]=res[i]+c[i];
		fore(i,0,n)res[i]=res[i]+o.c[i];
		return res;
	}
	poly operator*(tp k){
		poly res(c.size());
		fore(i,0,c.size())res[i]=c[i]*k;
		return res;
	}
	poly operator*(poly o){
		int m=c.size(),n=o.c.size();
		poly res(m+n-1);
		fore(i,0,m)fore(j,0,n)res[i+j]=res[i+j]+c[i]*o.c[j];
		return res;
	}
	poly operator-(poly<T> o){return *this+(o*-1);}
	T operator()(tp v){
		T sum(0);
		for(int i=c.size()-1;i>=0;--i)sum=sum*v+c[i];
		return sum;
	}
	bool isConstant(){
		for(int i=1;i<c.size();i++){
			if(c[i]!=0) return false;
		}
		return true;
	}
};
// example: p(x,y)=2*x^2+3*x*y-y+4
// poly<poly<>> p={{4,-1},{0,3},{2}}
// printf("%d\n",p(2)(3)) // 27 (p(2,3))
set<tp> roots(poly<> p){ // only for integer polynomials
	set<tp> r;
	while(!p.c.empty()&&!p.c.back())p.c.pop_back();
	if(!p(0))r.insert(0);
	if(p.c.empty())return r;
	tp a0=0,an=abs(p[p.c.size()-1]);
	for(int k=0;!a0;a0=abs(p[k++]));
	vector<tp> ps,qs;
	fore(i,1,sqrt(a0)+1)if(a0%i==0)ps.pb(i),ps.pb(a0/i);
	fore(i,1,sqrt(an)+1)if(an%i==0)qs.pb(i),qs.pb(an/i);
	for(auto pt:ps)for(auto qt:qs)if(pt%qt==0){
		tp x=pt/qt;
		if(!p(x))r.insert(x);
		if(!p(-x))r.insert(-x);
	}
	return r;
}

vector<string> sum(string x){
	x+="+";
	string base="";
	vector<string> ans;
	for(int i=0;i<x.size();i++){
		if(x[i]=='+'){
			ans.push_back(base);
			base="";
		}else{
			base.push_back(x[i]);
		}
	}
	return ans;
}

vector<tp> iden;
vector<tp> vacio;

int main(){
	//ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	/*vector<tp> v(5);
	v[0] = 60;
	v[1] = 44;
	v[2] = 45;
	v[3] = -15;
	v[4] = 1;
	poly<> p(v);
	set<tp> solve = roots(p);
	set<tp> :: iterator it;
	for(it=solve.begin();it!=solve.end();it++){
		cout<<(*it)<<endl;
	}*/
	string base;
	iden.pb(1);
	vacio.pb(0);
	while(cin>>base){
		if(base=="=") break;
		int maxi = 1;
		int pos;
		for(int i=0;i<base.size();i++){
			if(base[i]=='=') pos=i;
			if(base[i]>='0' && base[i]<='9') maxi = max(maxi,base[i]-'0');
		}
		string term1 = base.substr(0,pos);
		string term2 = base.substr(pos+1,base.size());
		//cout<<term1<<" "<<term2<<endl;
		vector<string> sumas1 = sum(term1);
		vector<string> sumas2 = sum(term2);
		/*for(int i=0;i<sumas1.size();i++){
			cout<<sumas1[i]<<(char)(i+1==sumas1.size()?10:32);
		}
		for(int i=0;i<sumas2.size();i++){
			cout<<sumas2[i]<<(char)(i+1==sumas2.size()?10:32);
		}*/
		poly<> comp1(vacio);
		for(int i=0;i<sumas1.size();i++){
			poly<> cur(iden);
			sumas1[i]+="*";
			vector<tp> mult;
			for(int j=0;j<sumas1[i].size();j++){
				if(sumas1[i][j]=='*'){
					reverse(mult.begin(),mult.end());
					poly<> multiplicando(mult);
					cur=cur*multiplicando;
					mult.clear();
				}else mult.pb(sumas1[i][j]-'0');
			}
			comp1 = cur+comp1;
		}
		
		poly<> comp2(vacio);
		for(int i=0;i<sumas2.size();i++){
			poly<> cur(iden);
			sumas2[i]+="*";
			vector<tp> mult;
			for(int j=0;j<sumas2[i].size();j++){
				if(sumas2[i][j]=='*'){
					reverse(mult.begin(),mult.end());
					poly<> multiplicando(mult);
					cur=cur*multiplicando;
					mult.clear();
				}else mult.pb(sumas2[i][j]-'0');
			}
			comp2 = cur+comp2;
		}
		
		comp1 = comp2 - comp1;
		//for(int i=0;i<comp1.c.size();i++) cout<<comp1.c[i]<<(char)(i+1==comp1.c.size()?10:32);
		if(comp1.isConstant()){
			if(comp1.c[0]!=0){
				cout<<"*"<<'\n';
			}else{
				cout<<maxi+1<<"+\n";
			}
		}else{
			set<tp> res = roots(comp1);
			set<tp> :: iterator it;
			vector<tp> respu;
			for(it=res.begin();it!=res.end();it++){
				tp p = (*it);
				if(p<=maxi) continue;
				respu.pb(p);
			}
			if(respu.size()==0) cout<<"*\n";
			else{
				for(int i=0;i<respu.size();i++) cout<<respu[i]<<(char)(i+1==respu.size()?10:32);
			}
		}
	}

	return 0;
}

