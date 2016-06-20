#include <cstdio>
#include <cstdlib>
#define FREAD(filename) freopen((filename), "r", stdin)
using namespace std;
const int MAX_N = 100005;
const int INF = 0x7fffffff;
struct Node
{
	int k, w;
	int rank;
	Node *l, *r, *p;
	Node():l(NULL), r(NULL), p(NULL){}
	Node(int kk):k(kk), w(rand()), l(NULL), r(NULL), p(NULL){}
	Node(int kk, Node* pp):k(kk), w(rand()), l(NULL), r(NULL), p(pp){}
};
struct Treap
{
	Node* root;
	Node* _hot;
	Treap():root(NULL), _hot(root){}
	Treap(int k):root(new Node(k)){_hot = root;}
	void rotate(Node* cur){
		
	}
	void insert(Node* cur, int k){//往cur子树中插入关键码为k的节点
		if(cur == NULL){
			cur = new Node(k, _hot);//作为_hot的孩子插入
			k < _hot->k ? _hot->l = cur : _hot->r = cur;
			//printf("%d inserted as %d's %s child\n", k, _hot->k, cur == _hot->l ? "left" : "right");
			_hot = cur;
			rotate(cur);
			return ;
		}
		_hot = cur;
		if(cur->k < k) insert(cur->r, k);//assert:关键码互异
		else insert(cur->l, k);
	}
	Node* getMax(Node* cur){//cur子树中的最大值
		while(cur->r != NULL) cur = cur->r;
		return cur;
	}
	Node* succ(Node* cur){
		if(cur->l != NULL) return getMax(cur->l);
		Node* p = cur->p;
		while(p != NULL && cur == p->l){//沿右侧链上行
			cur = p;
			p = p->p;
		}//当开始拐向左侧时，此p为直接前驱
		return p;
	}
	int search(Node* cur, int k){//在cur子树中不超过k的最后一个元素
		if(cur == NULL){//到达底层外部节点，即查找失败
			//printf("try %d\n", _hot->k);
			return _hot->k < k ? _hot->k : succ(_hot)->k;//返回其直接前驱
		}
		_hot = cur;
		if(k == cur->k) return k;//三分支
		else if(k < cur->k) return search(cur->l, k);
		else return search(cur->r, k);
	}
};

int main()
{
	int n, k;
	char c;
	FREAD("hiho103.txt");
	scanf("%d", &n);
	getchar();//回车
	scanf("%c %d", &c, &k);
	if(c != 'I') return 1;
	n--;//第一个节点为根
	Treap T = Treap(k);
	while(n--){
		getchar();
		scanf("%c %d", &c, &k);
		switch(c){
			case 'I':
				T.insert(T.root, k);//从根开始查找
				break;
			case 'Q':
				printf("%d\n", T.search(T.root, k));
				break;
		}
	}
	return 0;
}
