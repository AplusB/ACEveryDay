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

typedef struct Node {
	Node *next[26];
	int cnt;
	Node() {
		cnt = 0;
		for(int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
	}
}Node;

void insert(Node *p, char *str) {
	for(int i = 0; str[i]; i++) {
		int t = str[i] - 'a';
		if(p->next[t] == NULL) {
			p->next[t] = new Node();
		}
		p = p->next[t];
	}
	p->cnt++;
}

int len, cnt;

void dfs(Node *p, char *str, int cur, int flag) {
	if(flag > 1) return;
	if(cur == len && flag == 1) {
		cnt++;
		return;
	}
	for(int i = 0; i < 26; i++) {
		if(p->next[i]) {
			if('a' + i == str[cur]) {
				dfs(p->next[i], str, cur+1, flag);
			}
			else {
				if(flag > 1) continue;
				dfs(p->next[i], str, cur, flag+1);
			}
		}
	}
}

void del(Node *root) {
	for(int i = 0; i < 26; i++) {
		if(root->next[i] != NULL) {
			del(root->next[i]);
		}
	}
	delete root;
}

const int maxn = 100010;
int n, m;
char tmp[maxn];

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		Node *root = new Node();
		for(int i = 0; i < n; i++) {
			scanf("%s", tmp);
			insert(root, tmp);
		}
		for(int i = 0; i < m; i++) {
			scanf("%s", tmp);
			len = strlen(tmp);
			cnt = 0;
			dfs(root, tmp, 0, 0);
			printf("%d\n", cnt);
		}
	}
	return 0;
}
