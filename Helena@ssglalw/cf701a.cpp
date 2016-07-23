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
using namespace std;

const int MAX_N = 105;

struct Number
{
	int id;
	int value;
};
bool cmp(Number n1, Number n2){
	return n1.value < n2.value;
}

int n;
Number a[MAX_N];

int main()
{
	//FREAD();
	RINT(n);
	REP(n){
		a[i].id = i+1;
		RINT(a[i].value);
	}
	sort(a, a+n, cmp);
	REP(n/2){
		printf("%d %d\n", a[i].id, a[n-i-1].id);
	}
	return 0;
}
