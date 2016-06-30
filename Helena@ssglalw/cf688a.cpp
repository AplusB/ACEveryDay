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
#define REP(N) for(i=0; i<(N); i++)
#define REPE(N) for(i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 105;
int i, j;
int n, d;
char s[MAX_N];
char t[MAX_N];

int main()
{
	FREAD("688a.txt");
	RINT(n); RINT(d);
	REP(n){
		t[i] = '1';
	}
	t[n] = '\0';

	int cnt = 0;
	int ans = 0;
	while(d--){
		getchar();
		RSTR(s);
		if(!strcmp(s, t)) cnt = 0;
		else cnt++;
		ans = max(cnt, ans);
	}
	PINT(ans);
	return 0;
}
