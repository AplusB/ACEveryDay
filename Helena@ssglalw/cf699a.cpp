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
const int MAX_N = 200005;

int n;
int x[MAX_N];

int main()
{
	FREAD("699a.txt");
	string dir;
	RINT(n);
	cin >> dir;
	REP(n){
		RINT(x[i]);
	}
	if(n == 1){
		printf("-1\n");
		return 0;
	}
	int ans = 0x7fffffff;
	REP(n-1){
		if(dir[i] == 'R' && dir[i+1] == 'L'){
			ans = min(ans, (x[i+1]-x[i])/2);
		}
	}
	if(ans == 0x7fffffff) ans = -1;
	PINT(ans);
	return 0;
}
