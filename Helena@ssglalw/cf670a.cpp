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
#define FREAD() freopen("in.txt", "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
typedef __int64 ll;
#define sz(a) ll((a).size())
using namespace std;

int n;

int main()
{
	FREAD();
	RINT(n);
	int base = n / 7;
	int remainder = n % 7;
	int minn = base*2;
	int maxx = base*2;
	switch(remainder){
		case 0: break;
		case 1: maxx++; break;
		case 2:
		case 3:
		case 4:
		case 5: maxx += 2; break;
		case 6: minn++; maxx += 2;
	}
	printf("%d %d\n", minn, maxx);
	return 0;
}
