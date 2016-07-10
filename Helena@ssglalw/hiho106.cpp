#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(i=0; i<(N); i++)
#define REPE(N) for(i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 100005;
#define size(t) (t==NULL ? 0 : t->s)

struct Node
{
	int k, s;
	Node *left, *right;
	Node():s(0),left(NULL), right(NULL){}
	Node(int kk):k(kk), s(1), left(NULL), right(NULL){}
}nodes[MAX_N];
Node* nodeTop;

void update(Node* t){
	if(!t) return ;
	t->s = size(t->left) + size(t->right) + 1;
}
void zig(Node* &t){
	Node* k = t->left;
	t->left = k->right;
	k->right = t;
	update(t);
	update(k);
	t = k;
}
void zag(Node* &t){
	Node* k = t->right;
	t->right = k->left;
	k->left = t;
	update(t);
	update(k);
	t = k;
}
void insert(Node* &t, Node* k){
	if(!t) t = k;//找到目标位置
	else{
		if(k->k < t->k){
			insert(t->left, k);//assert: t->left在insert后必不空
			if(size(t->left->left) > size(t->right))
				zig(t);
		}else{
			insert(t->right, k);
			if(size(t->right->right) > size(t->left))
				zag(t);
		}
	}
	update(t);
}

int n;
char c;
int k;
int cnt;
Node* root;

Node* newNode(int k){//栈式分配
	nodeTop->k = k;
	nodeTop->s = 1;
	return nodeTop++;
}

int main()
{
	FREAD("hiho106.txt");
	root = NULL;
	nodeTop = &nodes[0];
	Node* cur;
	RINT(n);
	while(n--){
		getchar();
		c = getchar();
		RINT(k);
		switch(c){
			case 'I':
				cur = newNode(k);
				insert(root, cur);
				break;
			case 'Q':
				Node* cur = root;
				while(1){
					if(k == size(cur->left)+1) break;
					if(k < size(cur->left)+1) cur = cur->left;
					else{
						k -= size(cur->left)+1;
						cur = cur->right;
					}
				}
				PINT(cur->k);
				pn();
		}
	}
	return 0;
}
