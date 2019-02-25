#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (2e9);
struct TreapNode{
    ll key, priority;
    TreapNode *left, *right;
};
 
TreapNode *rightRotate(TreapNode *y){
    TreapNode *x = y->left,  *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}
 
TreapNode *leftRotate(TreapNode *x){
    TreapNode *y = x->right, *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}
 
/* Utility function to add a new key */
TreapNode* newNode(ll key)
{
    TreapNode* temp = new TreapNode;
    temp->key = key;
    temp->priority = rand()%INF;
    temp->left = temp->right = NULL;
    return temp;
}

bool ok= true;

TreapNode* insert(TreapNode* root, ll key, ll last){
    if (!root){
    	if(__gcd(last,key)==1) ok=false; 
	    return newNode(key);
	}
    if (key < root->key){
        root->left = insert(root->left, key,root->key);
        if (root->left->priority > root->priority) root = rightRotate(root);
    }else{
        root->right = insert(root->right, key,root->key);
        if (root->right->priority > root->priority) root = leftRotate(root);
    }
    return root;
}
 
void inorder(TreapNode* root){
    if (root){
        inorder(root->left);
        cout << "key: "<< root->key << " | priority: %d "
            << root->priority;
        if (root->left)
            cout << " | left child: " << root->left->key;
        if (root->right)
            cout << " | right child: " << root->right->key;
        cout << endl;
        inorder(root->right);
    }
}

bool check(TreapNode* root){
	if(root){
		TreapNode* izq = root->left;
		TreapNode* der = root->right;
		ll val = root->key;
		bool ans = true;
		if(izq){
			ans &= (__gcd(val,izq->key)==1?false:true);
			ans &= check(izq);
		}
		if(der){
			ans &= (__gcd(val,der->key)==1?false:true);
			ans &= check(der);
		}
		return ans;
	}
	return true;
}

 
int main(){
    srand(time(NULL));
    int n;cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<8000;i++){
    	random_shuffle ( v.begin(), v.end());
    	//for(int i=0;i<v.size();i++) cout<<v[i]<<(char)(i+1==v.size()?10:32);
    	ok = true;
    	struct TreapNode *root = NULL;
		for(int j=0;j<n;j++) root = insert(root,v[j],0);
		if(ok){
			//inorder(root);
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";

    return 0;
}
