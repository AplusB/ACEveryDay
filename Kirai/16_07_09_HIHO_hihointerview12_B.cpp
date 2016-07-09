#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define fr first
#define sc second
#define cl clear
#define BUG puts("here!!!")
#define W(a) while(a--)
#define pb(a) push_back(a)
#define Rint(a) scanf("%d", &a)
#define Rll(a) scanf("%I64d", &a)
#define Rs(a) scanf("%s", a)
#define Cin(a) cin >> a
#define FRead() freopen("in", "r", stdin)
#define FWrite() freopen("out", "w", stdout)
#define Rep(i, len) for(int i = 0; i < (len); i++)
#define For(i, a, len) for(int i = (a); i < (len); i++)
#define Cls(a) memset((a), 0, sizeof(a))
#define Clr(a, x) memset((a), (x), sizeof(a))
#define Full(a) memset((a), 0x7f7f7f, sizeof(a))
#define lrt rt << 1
#define rrt rt << 1 | 1
#define pi 3.14159265359
#define RT return
#define lowbit(x) x & (-x)
#define onenum(x) __builtin_popcount(x)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<LL, LL> pll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

const int maxn = 100010;
typedef struct Node {
	string d;
	int idx;
	Node() { idx = -1; }
	Node(string dd, int ii) : d(dd), idx(ii) {}
	friend bool operator<(Node a, Node b) { return a.idx > b.idx; }
}Node;

string mail, user;
bool vis[maxn];
map<string, int> id;
map<string, set<string> > wt;
priority_queue<Node> belong[100010];

int n, m, cnt;
int pre[maxn];

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x); y = find(y);
	if(x < y) pre[y] = x;
	else pre[x] = y;
}

int main() { 
	// FRead();
	cnt = 1;id.cl(); wt.cl(); Cls(vis);
	Rint(n);
	Rep(i, n*10) {
		pre[i] = i;
		while(!belong[i].empty()) belong[i].pop();
	}
	Rep(i, n) {
		cin >> user;
		cin >> m;
		id[user] = cnt++;
		Rep(j, m) {
			cin >> mail;
			if(id.find(mail) == id.end()) id[mail] = cnt++;
			wt[mail].insert(user);
			unite(id[user], id[mail]);
		}
	}
	map<string, set<string> >::iterator it;
	set<string>::iterator each, t;
	for(it = wt.begin(); it != wt.end(); it++) {
		for(each = it->second.begin(); each != it->second.end(); each++) {
			if(!vis[id[*each]]) {
				vis[id[*each]] = 1;
				belong[find(id[*each])].push(Node(*each, id[*each]));
			}
		}
	}
	Rep(i, cnt) {
		if(!belong[i].empty()) {
			while(!belong[i].empty()) {
				cout << belong[i].top().d << " ";
				belong[i].pop();
			}
			cout << endl;
		}
	}
	RT 0;
}
