#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(int i=0; i<(N); i++)
#define REPE(N) for(int i=1; i<=(N); i++)
#define FREAD(FN) freopen((FN), "r", stdin)
#define pb(a) push_back(a)
using namespace std;
const int MAX_N = 1005;

int n, h;
int a[MAX_N];
int main()
{
	scanf("%d%d", &n, &h);
	int ans = n;
	REP(n){
		scanf("%d", &a[i]);
		if(a[i] > h) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
