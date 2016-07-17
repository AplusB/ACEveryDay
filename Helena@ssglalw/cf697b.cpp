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

int a, b;
char d[105];
char c;

int main()
{
	RINT(a);
	c = getchar();//.
	c = getchar();//d的首字符
	int len = 0;
	for(int i=0; c != 'e'; i++){
		d[i] = c;
		c = getchar();
		len++;
	}
	RINT(b);
	PINT(a);
	for(int i=0; i<b; i++){
		if(d[i] != '\0')
			printf("%c", d[i]);
		else printf("0");
	}
	if((len > 1 || d[0] != '0') && d[b] != '\0'){
		printf(".");
		for(int i=b; d[i] != '\0'; i++)
			printf("%c", d[i]);
	}
	return 0;
}
