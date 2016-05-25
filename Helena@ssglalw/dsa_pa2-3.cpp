#include <cstdio>
using namespace std;
const int MAX_N = 1000005;
const int CAP = 100;//初始容量

struct Node
{
	int data;
	Node *next, *pre;
	Node():data(0), next(NULL), pre(NULL){}
	Node(int d):data(d), next(NULL), pre(NULL){}
};

struct List
{
	Node* head;
	int _size;
	List():_size(0){
		head = new Node();
	}
	void push_back(int x){
		Node* cur = new Node(x);
		cur->next = head->next;
		cur->pre = head;
		if(head->next) head->next->pre = cur;//头插
		head->next = cur;
	}
	int size(){
		return _size;
	}
};

int max(int x, int y){
	return x >= y ? x : y;
}

List G[MAX_N];
// int vis[MAX_N];
// int t[MAX_N];
 int d[MAX_N];
// int cnt;
int n, m;

int dp(int x){
	if(d[x] > 1) return d[x];
	int ans = 1;

	for(Node* cur = G[x].head->next; cur != NULL; cur = cur->next){
		int tmp = dp(cur->data);
		ans = max(tmp+1, ans);
	}
	return d[x] = ans;
}

int main()
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
	//freopen("pa2-3.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	// for(int i=1; i<=n; i++){
	// 	ver[i].id = i;
	// }
	for(int i=0; i<m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		//ver[v].indeg++;
	}

	// for(int i=1; i<=n; i++){
	// 	for(int j=0; j<G[i].size(); j++){
	// 		printf("%d ", G[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(int i=1; i<=n; i++){
		d[i] = 1;
	}
	int maxx = 1;
	for(int i=1; i<=n; i++){
		maxx = max(maxx, dp(i));
		//printf("%d %d\n", i, dp(i));
	}
	printf("%d\n", maxx);

	return 0;
}
