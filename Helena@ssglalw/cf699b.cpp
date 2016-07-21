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
const int MAX_N = 1005;

int n, m;
char G[MAX_N][MAX_N];
int cntx[MAX_N], cnty[MAX_N];
int cnt;

int main()
{
	//FREAD("699b.txt");
	RINT(n); RINT(m);
	REP(n){
		RSTR(G[i]);
	}
	cnt = 0;
	REP(n){
		for(int j=0; j<m; j++){
			if(G[i][j] == '*'){
				cntx[i]++;
				cnty[j]++;
				cnt++;
			}
		}
	}
	int sx, sy;
	sx = MAX_N;
	REP(n){
		for(int j=0; j<m; j++){
			if(G[i][j] != '*' && cntx[i] + cnty[j] == cnt){
				sx = i; sy = j;
			}else if(G[i][j] == '*' && cntx[i] + cnty[j] == cnt+1){
				sx = i; sy = j;
			}
		}
	}
	if(sx == MAX_N) printf("NO\n");
	else printf("YES\n%d %d\n", sx+1, sy+1);
	return 0;
}
