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
const int MAX_N = 100005;

int n;
int a[MAX_N];
int last;

bool now(int x){
	if(last&1){
		if(x&1) return true;//偶
		else return false;
	}else{
		if(x&1) return false;//奇
		else return true;
	}
}

int main()
{
	RINT(n);
	last = 0;
	REP(n){
		RINT(a[i]);
		if(!now(a[i])){
			last = 0;
			printf("2\n");
		}else{
			last = 1;
			printf("1\n");
		}
	}
	return 0;
}
