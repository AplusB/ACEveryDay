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

int main()
{
	FREAD("681b.txt");
	RINT(n);
	int t = 0;
	bool ans = 0;
	for(int a=0; a<n/1234567+1; a++){
		for(int b=0; b<n/123456+1; b++){
			if( (n-a*1234567-b*123456) >= 0 && (n-a*1234567-b*123456) % 1234 == 0){
				ans = 1;
				break;
			}
		}
		if(ans) break;
	}

	// for(int c=0; c<n/1234+1 && t<=n; c++, t = c*1234){//超时
	// 	for(int b=0; b<n/123456+1 && t<=n; b++, t = c*1234 + b*123456){
	// 		for(int a =0; a<n/1234567+1 && t<=n; a++, t = c*1234 + b*123456 + a*1234567){	
	// 			if(t == n){
	// 				ans = 1;
	// 				break;
	// 			}
	// 		}
	// 		if(ans) break;
	// 	}
	// 	if(ans) break;
	// }
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}
