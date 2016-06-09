#include <cstdio>
#define REPE(N) for(int i=1; i<=(N); i++)
using namespace std;
const int MAX_N = 105;
int n, a;
int t[MAX_N];

int main()
{
	scanf("%d%d", &n, &a);
	REPE(n) scanf("%d", &t[i]);
	int ans = t[a];
	int l = a - 1, r = a + 1;
	while(l >= 1 && r <= n){
		//printf("%d %d\n", l, r);
		ans += t[l] && t[r] ? 2 : 0;
		l--; r++;
	}
	while(l >= 1){
		if(t[l]) ans++;
		l--;
	}
	while(r <= n){
		if(t[r]) ans++;
		r++;
	}
	printf("%d\n", ans);
	return 0;
}
