/*
━━━━━┒ギリギリ♂ eye！
┓┏┓┏┓┃キリキリ♂ mind！
┛┗┛┗┛┃＼○／
┓┏┓┏┓┃ /
┛┗┛┗┛┃ノ)
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┛┗┛┗┛┃
┓┏┓┏┓┃
┃┃┃┃┃┃
┻┻┻┻┻┻
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
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
#define Rlf(a) scanf("%llf", &a);
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
#define Full(a) memset((a), 0x7f7f, sizeof(a))
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
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

typedef struct Node1 {
	char s;
	int pre;
	Node1() { pre = -1; }
}Node1;
typedef struct Node2 {
	int status[11];
	int n, son;
}Node2;

Node1 path[666666];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int fac[11];

void init() {
	fac[0] = fac[1] = 1;
	For(i, 2, 11) fac[i] = fac[i-1] * i;
}

int ecantor(int* s, int n = 9) {
	int num = 0;
	Rep(i, n) {
		int tmp = 0;
		For(j, i+1, n) if(s[j] < s[i]) tmp++;
		num += fac[n-1-i] * tmp;
	}
	return num;
}

void bfs() {
	queue<Node2> q;
	Node2 a, b;
	int t = 0;
	Rep(i, 9) a.status[i] = i + 1;
	a.n = 8; a.son = 0;
	path[a.son].pre = 0;
	q.push(a);
	while(!q.empty()) {
		a = q.front(); q.pop();
		Rep(i, 4) {
			b = a;
			int xx = a.n % 3 + dx[i];
			int yy = a.n / 3 + dy[i];
			if(!(xx >= 0 && xx < 3 && yy >= 0 && yy < 3)) continue;
			b.n = yy * 3 + xx;
			swap(b.status[b.n], b.status[a.n]);
			b.son = ecantor(b.status);
			if(path[b.son].pre == -1) {
				path[b.son].pre = a.son;
				if(i == 0) path[b.son].s = 'l';
				if(i == 1) path[b.son].s = 'r';
				if(i == 2) path[b.son].s = 'u';
				if(i == 3) path[b.son].s = 'd';
				q.push(b);
			}
		}
	}
}

int main() {
	// FRead();
	init();
	bfs();
	int s, ss[11];
	int T;
	Rint(T);
	W(T) {
		Rep(i, 9) {
			scanf("%d", &ss[i]);
			if(ss[i] == 0) ss[i] = 9;
		}
		s = ecantor(ss);
		if(path[s].pre == -1) {
			printf("No Solution!\n");
			continue;
		}
		int ret = 0;
		while(s != 0) {
			ret++;
			s = path[s].pre;
		}
		printf("%d\n", ret);
	}
	return 0;
}
