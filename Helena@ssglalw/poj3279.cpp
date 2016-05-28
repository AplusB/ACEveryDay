#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 16;
const int MAX_M = 16;
const int INF = 0x7fffffff;
int a[MAX_N][MAX_M];//原图
int b[MAX_N][MAX_M];//此位置共翻转了几次
int c[MAX_N][MAX_M];//最优解
int n, m;
int dx[] = {0, 0, 0, 1, -1}, dy[] = {1, -1, 0, 0, 0};

bool out(int x, int y){
	if(x < 0 || x >=n || y < 0 || y >= m) return true;
	return false;
}

int get_color(int x, int y){
	int color = a[x][y];
	for(int i=0; i<5; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(out(nx, ny)) continue;
		color += b[nx][ny];//主动+被动
	}
	return color % 2;
}

int flip(int s){
	for(int i=1; i<=m; i++){
		b[0][i-1] = (s>>(m-i)) & 1;
		//printf("%d ", b[0][i-1]);
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){//(i-1, j)想变，必须让(i, j)翻转
			if(get_color(i-1, j)){
				b[i][j] = 1;
				//printf("%d, %d\n", i, j);
			}
		}
	}
	for(int i=0; i<m; i++){
		if(get_color(n-1, i)){
			//printf("%d no\n", i);
			return INF;
		}
		
	}
	int times = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			times += b[i][j];
		}
	}
	return times;
}

int main()
{
	freopen("3279.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int ans = INF;
	for(int i=0; i< (1<<m); i++){//信号量集
		memset(b, 0, sizeof(b));//翻转方案
		int t = flip(i);
		if(t < ans){
			ans = t;
			memcpy(c, b, sizeof(b));
		}
	}
	if(ans == INF) printf("IMPOSSIBLE\n");
	else{
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				printf("%d ", c[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
