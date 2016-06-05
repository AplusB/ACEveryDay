#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define FREAD(FN) freopen((FN), "r", stdin)
#define pb(a) push_back(a)
#define pf() pop_front()
using namespace std;

const int MAX_N = 200005;
int n;
int a[MAX_N];
int flag;

int main()
{
	scanf("%d", &n);
	REP(n) scanf("%d", &a[i]);
	flag = 0;
	REP(n) a[i] -= n - i;
	sort(a, a+n);
	a[0] += n;
	for(int i=1; i<n; i++){
		a[i] += n - i;
		if(a[i] < a[i-1]){
			flag = 1;
			break;
		}
	}
	
	if(flag) printf(":(\n");
	else{
		REP(n) printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
