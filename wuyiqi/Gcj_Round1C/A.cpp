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

int main() {
	freopen("A-large-practice.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T, ca = 1;
	scanf("%d", &T);
	while (T--) {
		int n, x;
		scanf("%d", &n);
		priority_queue<pair<int, int> > Q;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			sum += x;
			Q.push(make_pair(x, i));
		}
		printf("Case #%d:", ca++);
		while (!Q.empty()) {
			pair<int, int> fr = Q.top(); Q.pop();
			if (fr.first > 1) {
				Q.push(make_pair(fr.first - 1, fr.second));
			}
			sum--;
			printf(" %c", fr.second + 'A');
			if (Q.top().first > sum / 2) {
				fr = Q.top(); Q.pop();
				if (fr.first > 1) {
					Q.push(make_pair(fr.first - 1, fr.second));
				}
				sum--;
				printf("%c", fr.second + 'A');
			}
		}
		puts("");
	}
	return 0;
}
