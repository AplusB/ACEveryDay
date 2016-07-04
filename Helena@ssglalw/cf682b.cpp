#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
#include <assert.h>

#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(i=0; i<(N); i++)
#define REPE(N) for(i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
int i, j;
const int MAX_N = 100005;
int a[MAX_N];
int n;

int main()
{
	RINT(n);
	REPE(n) RINT(a[i]);
	sort(a+1, a+1+n);
	int cur = 1;
	REPE(n){
		while(i<=n && a[i]<cur) i++;
		if(i > n) break;
		a[i] = cur;//把a[i]变成i来填补这个空位
		cur++;
	}
	PINT(cur); pn();
	return 0;
}
