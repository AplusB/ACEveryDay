#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>
#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 105;
//不要把i,j设成全局量

char M[MAX_N][MAX_N];
int r, c;
int dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};
bool vis[MAX_N][MAX_N];

bool out(int x, int y){
	if(x<0 || y<0 || x>=r || y>=c) return true;
	return false;
}

void dfs(int x, int y){
	vis[x][y] = 1;
	REP(4){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(out(nx, ny)) continue;
		if(vis[nx][ny]) continue;
		if(M[nx][ny] == 'B') dfs(nx, ny);
	}
}

int main()
{
	FREAD("690d1.txt");
	CLEAR(vis, 0);
	RINT(r); RINT(c);
	REP(r){
		getchar();
		RSTR(M[i]);
	}
	int cnt = 0;
	REP(r){
		for(int j=0; j<c; j++){
			if(M[i][j] == 'B' && !vis[i][j]){
				dfs(i, j);
				cnt++;
			}
		}
	}
	PINT(cnt);
	return 0;
}
