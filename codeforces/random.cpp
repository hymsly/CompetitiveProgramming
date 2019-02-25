#include<bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)

#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define sz(v) ((int)v.size())
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int rainA[] = {3,4,4,5,5,5,6};
int rainB[] = {3,4,4,4,5};
int needA[] = {3,4,4,4,5,5,5,6};
int needB[] = {3,3,4,4,4,5,5};

int main(){
	//fast_io()
	int pos1,pos2,pos3,pos4;
	cout<<"lluvia en A - cnt necesitada en A - represa1 - escasez1 - lluvia en B - cnt necesitada en B - represa2 - escasez2"<<endl;
	srand(time(NULL));
	int almacen1=0,almacen2=0;
	for(int i=0;i<200;i++){
		int e1 = 0 ,e2 = 0;
		pos1 = rand() % 7;
		pos2 = rand() % 5;
		pos3 = rand() % 8;
		pos4 = rand() % 7;
		int rain1 = rainA[pos1];
		int rain2 = rainB[pos2];
		int need1 = needA[pos3];
		int need2 = needB[pos4];
		if(rain1>=need1){
			almacen1 += (rain1-need1);
			almacen1 = min(6,almacen1);
		}else{
			if(almacen1>=(need1-rain1)){
				almacen1-=(need1-rain1);
			}else{
				e1 = need1 - rain1 - almacen1;
				almacen1 = 0;
			}
		}
		
		if(rain2>=need2){
			almacen2 += (rain2-need2);
			almacen2 = min(4,almacen2);
		}else{
			if(almacen2>=need2-rain2){
				almacen2-=(need2-rain2);
			}else{
				if(almacen1>=3){
					almacen1 = 3;
					almacen2 += (almacen1 - 3);
				}
				if(almacen2>=need2-rain2){
					almacen2-=(need2-rain2);
				}else{
					e2 = need2 - rain2 - almacen2;
					almacen2 = 0;
				}
			}
		}
		
		cout<<"     "<<rain1<<"                "<<need1<<"                 "<<almacen1<<"         "<<e1<<"           "<<rain2<<"                 "<<need2<<"                "<<almacen2<<"         "<<e2<<endl;
	}

	
	return 0;
}

