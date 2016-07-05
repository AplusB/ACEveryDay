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
int n;
int a, b;
char name[15];

int main()
{
	FREAD("681a.txt");
	bool flag = 0;
	RINT(n);
	while(n--){
		getchar();
		RSTR(name);
		RINT(b); RINT(a);
		if(b >= 2400 && a > b){
			flag = 1;
			break;
		}
	}
	printf("%s\n", flag ? "YES" : "NO");
	return 0;
}
