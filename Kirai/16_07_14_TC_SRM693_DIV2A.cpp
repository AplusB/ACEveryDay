#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <string>
#include <set>

using namespace std;

class TriangleEasy {
public:
	int find(int n, vector <int> x, vector <int> y) {
		const int maxn = 10010;
		bool G[maxn][maxn];
		int ret = 10;
		memset(G, 0, sizeof(G));
		for(int i = 0; i < x.size(); i++) {
			G[x[i]][y[i]] = G[y[i]][x[i]] = 1;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					if(i == j || j == k || i == k) continue;
					if(G[i][j] == 1 && G[j][k] == 1 && G[k][i] == 1) ret = min(ret, 0);
					else if(G[i][j] == 1 && G[j][k] == 1 && G[k][i] != 1) ret = min(ret, 1);
					else if(G[i][j] == 1 && G[j][k] != 1 && G[k][i] != 1) ret = min(ret, 2);
					else ret = min(ret, 3);
				}
			}
		}
		return ret;
	}
};
