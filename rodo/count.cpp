#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (2e5);
int arr[N+2];
int temp[N+2];

ll merge(int left, int mid, int right){
	int i=left, j=mid, k=left;
	ll inv_count = 0;
	while ((i <= mid - 1) && (j <= right)){
    	if (arr[i] <= arr[j]){
			temp[k++] = arr[i++];
    	}
    	else{
    		temp[k++] = arr[j++];
			inv_count += (mid - i);
    	}
	}
	while (i <= mid - 1) temp[k++] = arr[i++];
	while (j <= right) temp[k++] = arr[j++];
	for (i=left; i <= right; i++) arr[i] = temp[i];
	return inv_count;
}
 
ll mergeSort(int left, int right){
	int mid;
	ll inv_count = 0;
	if (right > left){
    	mid = (right + left)/2;
    	inv_count += mergeSort(left, mid);
    	inv_count += mergeSort(mid+1, right);
		inv_count += merge(left, mid+1, right);
	}
	return inv_count;
}

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i];
		for(int i=0;i<n;i++) temp[i] = arr[i];
		cout<<mergeSort(0,n-1)<<'\n';
	}
	return 0;
}
