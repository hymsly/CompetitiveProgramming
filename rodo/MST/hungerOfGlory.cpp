#include <bits/stdc++.h>
using namespace std;
#define Vector Point
typedef long long ll;
typedef long double ld;
const ld EPS = (1e-9);
struct Point{
	ld x,y;
	Point(){}
	Point(ld _x,ld _y){
		x = _x;
		y = _y;
	}
	Point ort(){return Point(-y,x);}
	bool operator ==(Point p){
		return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;
	}
	ld norm2(){return x*x+y*y;}
	ld norm(){return sqrt(x*x+y*y);}
};
bool operator <(const Point &a,const Point &b){
	if(abs(a.x-b.x)<EPS) return a.y<b.y;
	return a.x<b.x;
}
Point operator +(const Point &a,const Point &b){
	return Point(a.x+b.x,a.y+b.y);
}
Point operator -(const Point &a,const Point &b){
	return Point(a.x-b.x,a.y-b.y);
}

Point operator /(const Point &a,ld t){
	return Point(a.x/t,a.y/t);
}
Point operator *(const Point &a,ld t){
	return Point(a.x*t,a.y*t);
}
ld cross(const Point &a,const Point &b){
	return a.x*b.y-a.y*b.x;
}
ld dot(const Point &a,const Point &b){
	return (a.x*b.x+a.y*b.y);
}
ld area(const Point &a,const Point &b,const Point &c){
	return cross(b-a,c-a);
}

vector<Point> v;

Point circumcenter(const Point &a,const Point &b,const Point &c){
	return ((a+b+(a-b).ort()*dot(c-b,a-c))/cross(a-b,a-c))/2;
}

vector<Point> chull(vector<Point> &Poly){
	sort(Poly.begin(),Poly.end());
	int np = Poly.size(),k=0;
	Point H[2*np];
	for(int i=0;i<np;i++){
		while(k>=2 && area(H[k-2],H[k-1],Poly[i])<=0)--k;
		H[k++] = Poly[i];
	}
	for(int i=np-2,t=k;i>=0;i--){
		while(k>t && area(H[k-2],H[k-1],Poly[i])<=0)--k;
		H[k++] = Poly[i];
	}
	if(k==0) return vector<Point>();
	return vector<Point> (H,H+k-1);
}

int main() {
	int n;cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i].x>>v[i].y;
	for(int i=0;i<n;i++) v[i]=v[i];
	sort(v.begin(),v.end());
	vector<Point> afuera = chull(v);
	for(int i=0;i<afuera.size();i++) cout<<afuera[i].x<<" "<<afuera[i].y<<endl;
	if(afuera.size()==2){
		//es una linea
		if(n==2){
			cout<<"INF\n";
		}else if(n>4){
			cout<<"NO\n";
		}else if(n==3){
			
		}else{
			
		}
		return 0;
	}
	
	if(n==4){
		//no es linea 
	}
	
	
	
	int len = afuera.size();
	for(int i=0;i<len;i++) afuera.push_back(afuera[i]);
	ld ans = 0.0L;
	bool encontre = false;
	for(int i=0;i<afuera.size();i++){
		for(int j=i+1;j<afuera.size();j++){
			for(int k=j+1;k<j+10&&k<afuera.size();k++){
				if(afuera[j]==afuera[i]) continue;
				if(afuera[k]==afuera[i]) continue;
				if(afuera[k]==afuera[j]) continue;
				Point cent = circumcenter(afuera[i],afuera[j],afuera[k]);
				set<ld> S;
				cout<<cent.x<<" "<<cent.y<<endl;
				for(int m=0;m<n;m++){
					S.insert((v[m]-cent).norm());
					cout<<(v[m]-cent).norm()<<endl;
				}
				if(S.size()>2){
					continue;
				}
				if(S.size()==2){
					encontre = true;
					ld p1 = (*S.begin());
					ld p2 = (*S.rbegin());
					ans = max(ans,(p2-p1)/2.0L);
				}else{
					cout<<"INF\n";
					return 0;
				}	
			}
		}
	}
	if(!encontre){
		cout<<"NO\n";
	}else printf("%.2f\n",(double)ans);
	
	return 0;
}
