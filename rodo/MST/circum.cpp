#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld DINF = (1e100);
const ld EPS = (1e-9);

struct Point{
	ld x,y;
	Point(){}
	Point(ld _x,ld _y){
		x = _x;
		y = _y;
	}
	ld norm2(){
		return *this**this;
	}
	ld norm(){
		return sqrt(norm2());
	}
	bool operator ==(Point p){
		return abs(x-p.x)<EPS && abs(y-p.y)<EPS;
	}
	Point operator +(Point p){
		return Point(x+p.x,y+p.y);
	}
	Point operator -(Point p){
		return Point(x-p.x,y-p.y);
	}
	Point operator *(ld t){
		return Point(x*t,y*t);
	}
	Point operator /(ld t){
		return Point(x/t,y/t);
	}
	ld operator *(Point p){
		return x*p.x+y*p.y;
	}
	Point unit(){
		return *this/norm();
	}
	ld operator %(Point p){
		return x*p.y-y*p.x;
	}
	Point ort(){
		return Point(-y,x);
	}
	bool operator<(Point p)const{
		return x<p.x-EPS||(abs(x-p.x)<EPS&&y<p.y-EPS);
	}
	bool left(Point p,Point q){
		return (q-p)%(*this-p)>-EPS;
	}
};

struct linea{
	Point p,pq;
	linea(){}
	linea(Point p,Point q):p(p),pq(q-p){}
	bool operator/(linea l){
		return abs(pq.unit()%l.pq.unit())<EPS;
	}
	Point operator ^(linea l){
		if(*this/l) return Point(DINF,DINF);
		Point r = l.p + l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};

vector<Point> v;

struct radio{
	ld r;
	radio(ld _r){
		r = _r;
	}
	bool operator ==(radio p){
		return abs(r-p.r)<EPS;
	}
};
bool operator <(radio a,radio b){
	return a.r<b.r-EPS;
}

linea mediatriz(Point a,Point b){
	Point mid = (a+b)/2.0L;
	Point vec = (a-b).ort();
	return linea(mid,mid+vec);
}

Point centro(Point a,Point b,Point c){
	return mediatriz(a,b)^mediatriz(c,b);
}
int n;
bool areLinea(){
	bool ok=1;
	for(int i=2;i<n;i++){
		if(abs((v[i]-v[i-2])%(v[i-1]-v[i-2])) >= EPS) ok=0;
	}
	return ok;
}

int main() {
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y;
	if(n==2){
		cout<<"INF\n";
		return 0;
	}
	ld ans = 0.0L;
	if(n==4){//no es linea
		if(areLinea()){
			vector<int> idx(4);
			for(int i=0;i<4;i++) idx[i]=i;
			do{
				Point center = (v[idx[0]]+v[idx[1]])/2.0L;
				set<radio> S;
				for(int m=0;m<n;m++){
					S.insert(radio((v[m]-center).norm()));
				}
				if(S.size()>2){
					continue;
				}
				if(S.size()==2){
					ld radio1 = (*S.begin()).r;
					ld radio2 = (*S.rbegin()).r;
					ans = max(ans,(radio2-radio1)/2.0L);
				}else{
					cout<<"INF\n";
					return 0;
				}	
			}while(next_permutation(idx.begin(),idx.end()));
		}else{
			vector<int> idx(4);
			for(int i=0;i<4;i++) idx[i]=i;
			do{
				Point center = mediatriz(v[idx[0]],v[idx[1]])^mediatriz(v[idx[2]],v[idx[3]]);
				if(center == Point(DINF,DINF)) continue;
				set<radio> S;
				for(int m=0;m<n;m++){
					S.insert(radio((v[m]-center).norm()));
				}
				if(S.size()>2){
					continue;
				}
				if(S.size()==2){
					ld radio1 = (*S.begin()).r;
					ld radio2 = (*S.rbegin()).r;
					ans = max(ans,(radio2-radio1)/2.0L);
				}else{
					cout<<"INF\n";
					return 0;
				}
				
			}while(next_permutation(idx.begin(),idx.end()));
			sort(idx.begin(),idx.end());
			do{
				Point center = centro(v[idx[0]],v[idx[1]],v[idx[2]]);
				if(center == Point(DINF,DINF)) continue;
				set<radio> S;
				for(int m=0;m<n;m++){
					S.insert(radio((v[m]-center).norm()));
				}
				if(S.size()>2){
					continue;
				}
				if(S.size()==2){
					ld radio1 = (*S.begin()).r;
					ld radio2 = (*S.rbegin()).r;
					ans = max(ans,(radio2-radio1)/2.0L);
				}else{
					cout<<"INF\n";
					return 0;
				}
			}while(next_permutation(idx.begin(),idx.end()));
			
		}
	}
	if(n==3){
		if(areLinea()){
			vector<int> idx(3);
			for(int i=0;i<3;i++) idx[i]=i;
			do{
				Point center = (v[idx[0]]+v[idx[1]])/2.0L;
				set<radio> S;
				for(int m=0;m<n;m++){
					S.insert(radio((v[m]-center).norm()));
				}
				if(S.size()>2){
					continue;
				}
				if(S.size()==2){
					ld radio1 = (*S.begin()).r;
					ld radio2 = (*S.rbegin()).r;
					ans = max(ans,(radio2-radio1)/2.0L);
				}else{
					cout<<"INF\n";
					return 0;
				}	
			}while(next_permutation(idx.begin(),idx.end()));
		}
		else{
			cout<<"INF\n";
			return 0;	
		}
	}
	if(n>4){
		vector<int> idx(5);
		for(int i=0;i<5;i++) idx[i]=i;
		do{
			Point cent = centro(v[idx[0]],v[idx[1]],v[idx[2]]);
			if(cent==Point(DINF,DINF)) continue;
			set<radio> S;
			for(int m=0;m<n;m++){
				S.insert(radio((v[m]-cent).norm()));
			}
			if(S.size()>2){
				continue;
			}
			if(S.size()==2){
				ld radio1 = (*S.begin()).r;
				ld radio2 = (*S.rbegin()).r;
				ans = max(ans,(radio2-radio1)/2.0L);
			}else{
				cout<<"INF\n";
				return 0;
			}	
		}while(next_permutation(idx.begin(),idx.end()));
	}
	if(ans<EPS){
		cout<<"NO\n";
	}else printf("%.2f\n",(double)ans);
	
	return 0;
}
