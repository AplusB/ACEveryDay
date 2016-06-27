#include <cstdio>
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
const int MAX_K = 0x7fffffff;
const int MIN_K = 0;

int a[MAX_N];
int n;
int i;
map<int, bool> left, right;//iostream里有和left, right冲突的命名!

struct Node
{
	int k;
	Node *l, *r, *p;
	Node():k(-1), l(NULL), r(NULL), p(NULL){}
	Node(int kk, Node* pp):k(kk), l(NULL), r(NULL), p(pp){}
	~Node(){
		l = r = p = NULL;
	}
};

struct Splay
{
	Node* root;
	Node* _hot;
	Splay():root(NULL), _hot(NULL){}
	Splay(int k):root(new Node(k, NULL)), _hot(root){}

	void release(Node* cur){//释放子树cur的空间
		if(cur == NULL) return ;//空树
		release(cur->l);
		cur->l = NULL;
		release(cur->r);
		cur->r = NULL; //不用加吧，cur马上就销毁了啊
		//printf("deleted %d\n", cur->k);

		delete cur;
		return ;
	}
	~Splay(){
		release(root);
		root = NULL;
	}
	void zig(Node* cur){
		if(cur == NULL) return ;
		Node* v = cur->l;
		if(v == NULL) return ;
		Node* g = cur->p;

		v->p = g;
		if(g != NULL)
			//祖先g与v连接
			(cur == g->l) ? g->l = v : g->r = v;
		
		//v与cur孩子过继
		cur->l = v->r;
		if(cur->l != NULL) cur->l->p = cur;

		//v与cur角色转换
		cur->p = v;
		v->r = cur;
		if(cur == root) root = v;
		//printf("%d zigged\n", cur->k);
	}
	void zag(Node* cur){
		if(cur == NULL) return ;
		Node* v = cur->r;
		if(v == NULL) return ;
		Node* g = cur->p;
		//printf("g=%d cur=%d v=%d\n", g->k, cur->k, v->k);
		
		v->p = g;
		if(g != NULL)
			(cur == g->l) ? g->l = v : g->r = v;

		cur->r = v->l;
		if(cur->r != NULL) cur->r->p = cur;

		cur->p = v;
		v->l = cur;
		if(cur == root) root = v;
		//printf("%d zagged\n", cur->k);
	}
	void splay(Node* x, Node* f){// make x become f's child
		if(x == NULL) return ;
		while(x->p != f){//逐步双层伸展
			Node* p = x->p;
			if(p == NULL) return ;
			if(p->p == f)
				(x == p->l) ? zig(p) : zag(p);
			else{
				Node* g = p->p;
				if(g == NULL) return ;
				if(g->l == p){
					if(p->l == x){
						zig(g); zig(p);
					}else{
						zag(p); zig(g);
					}
				}else{
					if(p->l == x){
						zig(p); zag(g);
					}else{
						zag(g); zag(p);
					}
				}
			}	
		}
	}
	Node* search(Node* cur, int k){//在cur子树中查找关键码k
		if(cur == NULL) return _hot;//查找失败还伸展吗？暂不伸展，待决定插入后再将新插入的节点伸展
		if(cur->k == k){//查找成功
			//printf("has %d\n", cur->k);
			splay(cur, NULL);//将目标节点伸展至根
			return cur;
		}
		_hot = cur;//需要深入子树查找
		return (k < cur->k) ? search(cur->l, k) : search(cur->r, k);
	}
	Node* insert(Node* cur, int k){//将关键码k插入cur子树
		if(cur == NULL){//找到目标插入位置
			cur = new Node(k, _hot);
			//printf("%d %d\n", _hot->k, k);
			(k < _hot->k) ? _hot->l=cur : _hot->r=cur;
			_hot = cur;
			//printf("create %d\n", cur->k);
			splay(cur, NULL);//将目标节点伸展至树根
			return cur;
		}
		assert(cur);
		_hot = cur;//进入子树
		//printf("enter %d\n", cur->k);
		return (k < cur->k) ? insert(cur->l, k) : insert(cur->r, k);//assert:关键码互异
	}
	Node* prev(int k){//寻找关键码k的中序前驱
		splay(search(root, k), NULL);//将k伸展至树根
		Node* cur = root->l;//根节点的左子树
		//assert(cur);
		if(!cur) return NULL;
		while(cur->r != NULL) cur = cur->r;//前驱必然为左子树的最右节点
		return cur;
	}
	Node* succ(int k){//寻找关键码k的中序后继, assert:k一定存在
		splay(search(root, k), NULL);
		Node* cur = root->r;
		//assert(cur);
		if(!cur) return NULL;
		while(cur->l != NULL) cur = cur->l;
		return cur;
	}
	void deleteK(int k){
		Node* p = prev(k);
		Node* s = succ(k);
		splay(p, NULL);
		splay(s, p);
		Node* q = s->l;
		s->l = NULL;//解除父子关系
		release(q);//释放子树空间，这里只有一个节点k
	}
	void deleteInterval(int a, int b){
		Node* pa = search(root, a);//pa为最后一个被访问的节点，必不空
		assert(pa);
		if(pa->k != a) pa = insert(pa, a);//查找失败，插入
		//printf("pa->k = a = %d\n", pa->k);

		Node* pb = search(root, b);
		assert(pb);
		//printf("pb->k = b = %d\n", pb->k);
		if(pb->k != b) pb = insert(pb, b);
		
		Node* p = prev(a);
		assert(p);
		Node* s = succ(b);//assert: p, s not null
		assert(s);
		//printf("prev %d succ %d\n", p->k, s->k);
		splay(p, NULL);
		//printf("%d splayed\n", p->k);
		splay(s, p);
		//printf("%d splayed\n", s->k);
		Node* q = s->l;
		_hot = s;
		release(q);//释放子树空间
		s->l = NULL;
	}
};

int main()
{
	FREAD("675d.txt");
	RINT(n);
	REP(n) RINT(a[i]);
	Splay mySplay(a[0]);
	for(i=1; i<n; i++){
		int ans = 0;
		Node* q = mySplay.insert(mySplay.root, a[i]);
		Node* p = mySplay.prev(a[i]);
		if(p && right.count(p->k) == 0){
			right[p->k] = 1;//前驱没有右孩子
			ans = p->k;
		}else{
			Node* s = mySplay.succ(a[i]);
			if(s && left.count(s->k) == 0){
				left[s->k] = 1;
				ans = s->k;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
