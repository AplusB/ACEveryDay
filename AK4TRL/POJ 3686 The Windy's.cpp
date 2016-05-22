#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 55
#define inf 0x7ffffff
int w[MAXN][2555];
int lx[MAXN], ly[2555];
int linky[2555];
int visx[MAXN], visy[2555];
int slack[2555];
int nx, ny;
int n, m;
bool find(int x){
	visx[x] = 1;
	for (int y = 1; y <= ny; y++){
		if (visy[y]) continue;
		int t = lx[x] + ly[y] - w[x][y];
		if (t == 0){
			visy[y] = 1;
			if (linky[y] == -1 || find(linky[y])){
				linky[y] = x;
				return true;//找到增广路
			}
		}
		else if (slack[y] > t)
			slack[y] = t;
	}
	return false;
}

int KM(){
	memset(linky, -1, sizeof(linky));
	memset(ly, 0, sizeof(ly));
	for (int i = 1; i <= nx; i++){
		lx[i] = -inf;
		for (int j = 1; j <= ny; j++)
		if (w[i][j] >lx[i])
			lx[i] = w[i][j];
	}
	for (int x = 1; x <= nx; x++){
		for (int i = 1; i <= ny; i++)
			slack[i] = inf;
		while (1){
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (find(x)) break;
			int d = inf;
			for (int i = 1; i <= ny; i++)
			if (!visy[i] && d>slack[i])
				d = slack[i];
			for (int i = 1; i <= nx; i++)
			if (visx[i])
				lx[i] -= d;
			for (int i = 1; i <= ny; i++)
			if (visy[i])
				ly[i] += d;
			else
				slack[i] -= d;
		}
	}
	int ans = 0;
	for (int i = 1; i <= ny; i++)
	if (linky[i] >-1)
		ans += w[linky[i]][i];
	return -ans;
}

void init(){
	scanf("%d%d", &n, &m);
	nx = n;
	ny = n*m;
	int cost;
	for (int i = 1; i <= n; i++){
		int cnt = 1;
		for (int j = 1; j <= m; j++){
			scanf("%d", &cost);
			for (int k = 1; k <= n; k++)
				w[i][cnt++] = -cost*k;
		}
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		init();
		double ans = 1.0*KM() / n;
		printf("%.6f\n", ans);
	}

	return 0;
}
