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
#define FREAD() freopen("in.txt", "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
typedef __int64 ll;
#define sz(a) ll((a).size())
using namespace std;
const int MAX_N = 105;

struct Node
{
	int data;
	Node* next;
	Node():data(0), next(NULL){}
	Node(int d):data(d), next(NULL){}
};
struct LinkList
{
	Node* head;
	Node* tail;
	Node* _hot;//上一个被访问的节点
	LinkList():head(new Node()), tail(NULL), _hot(NULL){}
	Node* remove(Node* node){
		if(_hot == NULL) return NULL;//删除头节点
		_hot->next = node->next;
		//printf("connect %d to %d\n", _hot->data, node->next->data);
		return node;
	}
	void insert(Node* node){
		if(node == NULL) return ;
		node->next = head;
		head = node;
	}
	void adjust(){
		if(_hot == NULL) return ;
		insert(remove(_hot->next));
	}
	int search(int x){
		Node* cur = head;
		int cnt = 1;
		_hot = NULL;
		while(cur->data != x){
			cnt++;
			_hot = cur;
			cur = cur->next;
		}
		adjust();
		return cnt;
	}
	void iterate(){
		Node* cur = head;
		while(cur != NULL){
			printf("%d ", cur->data);
			cur = cur->next;
		}
		pn();
	}
};

int n, m, k;
int p[MAX_N];

int main()
{
	FREAD();
	RINT(n); RINT(m); RINT(k);
	LinkList l;
	l.head = new Node();
	RINT((l.head)->data);
	l.tail = l.head;
	//printf("%d %d\n", l.head->data, l.tail->data);
	REP(k-1){
		int p;
		RINT(p);
		Node* cur = new Node(p);
		l.tail->next = cur;
		l.tail = cur;
		//printf("%d\n", l.tail->data);
	}
	int ans = 0;
	REP(n){
		for(int j=0; j<m; j++){
			int item;
			RINT(item);
			//printf("look for %d\n", item);
			int inc = l.search(item);
			ans += inc;
			//printf("%d\n", inc);
		//l.iterate();
		}
	}
	PINT(ans);
	return 0;
}
