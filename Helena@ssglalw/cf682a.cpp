#include <cstdio>
#include <algorithm>
using namespace std;
__int64 remaider[5];
int n, m;
int main()
{
	while(~scanf("%d%d", &n, &m)){
		for(int i=0; i<=4; i++){
			remaider[i] = m/5;
		}
		remaider[0]--;
		int a = m % 5;
		for(int i = 0; i <=a; i++)
			remaider[i]++;
		__int64 ans = 0;
		for(int i=1; i<=n; i++){
			int b = (5 - i % 5) % 5;
			ans += remaider[b];
		}
		printf("%I64d\n", ans);
	}
	
	return 0;
}
