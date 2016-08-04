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
const int MAX_N = 105;

int n;
int cntm, cntc;

int main()
{
	//FREAD();
	RINT(n);
	cntm = cntc = 0;
	while(n--){
		int m, c;
		RINT(m); RINT(c);
		if(m > c) cntm++;
		else if(m < c) cntc++;
	}
	if(cntm > cntc) printf("Mishka\n");
	else if(cntm < cntc) printf("Chris\n");
	else printf("Friendship is magic!^^\n");
	return 0;
}
