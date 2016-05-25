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
	freopen("B-large-practice.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T, ca = 1;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ca++);
		int B; long long M;
		cin >> B >> M;
		memset(g, 0, sizeof(g));
        if(M > (1LL << B - 2)) {
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        if(M == (1LL << B - 2)) {
            M--;
            g[0][B - 1] = 1;
        }
        for(int i = 1; i < B - 1; i++) {
            for(int j = 0; j < i; j++) {
                g[j][i] = 1;
            }
        }
        for(int i = 1; i < B - 1; i++) {
            if(M & (1LL << (i - 1))) {
                g[i][B - 1] = 1;
            }
        }
        for(int i = 0; i < B; i++) {
            for(int j = 0; j < B; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
	}
	return 0;
}
