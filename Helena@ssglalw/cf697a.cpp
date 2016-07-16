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

int t, s, x;

int main()
{
	bool ans = 0;
	RINT(t); RINT(s); RINT(x);
	x -= t;
	if(x == 1) ans = 0;
	else if(x>=0 && x%s == 0 || x-1>=0 && (x-1)%s == 0) ans = 1;
	else ans = 0;
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}
