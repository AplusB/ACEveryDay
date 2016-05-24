// Paste me into the FileEdit configuration dialog
// Paste me into the FileEdit configuration dialog
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <deque>
#include <stdio.h>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <complex>
#include <sstream>
#include <utility>
#include <climits>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;

const int MOD = (int) 1e9 + 7;

int g[55][55];
int main() {
	freopen("B-small-practice.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T, ca = 1;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ca++);
		int B; long long M;
		cin >> B >> M;
		memset(g, 0, sizeof(g));
		int node = 1;
		for (int i = 0; i < 60; i++) {
			if (M & (1LL << i)) {
				int pre = 1;
				for (int j = 1; j < i; j++) {
					g[pre][++node] = 1;
					g[node][node + 1] = 1;
					g[pre][node + 1] = 1;
					pre = node + 1;
					node++;
				}
				g[pre][B] = 1;
				if (i) {
					g[pre][++node] = 1;
					g[node][B] = 1;
				}
			}
		}
		if (node >= B) {
			puts("IMPOSSIBLE");
		} else {
			puts("POSSIBLE");
			for (int i = 2; i <= B; i++) if(g[1][i]){
				g[1][i] = 0;
				int pre = 1;
				for (int j = node + 1; j < B; j++) {
					g[pre][j] = 1;
					pre = j;
				}
				g[pre][i] = 1;
				break;
			}
			for (int i = 1; i <= B; i++) {
				for (int j = 1; j <= B; j++) {
					printf("%d", g[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}
