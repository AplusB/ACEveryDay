#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 105;
int a[MAX_N];
int n;
int ans;

int main()
{
	scanf("%d", &n);
	int pmax, pmin;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 1) pmin = i;
		else if(a[i] == n) pmax = i;
	}
	if(pmin == 1 && pmax == n || pmin == n && pmax == 1) ans = n-1;
	else{
		int aa = min(pmin, pmax), bb = max(pmin, pmax);
		ans = bb - aa;
		int difa = aa - 1;
		int difb = n - bb;
		ans += max(difa, difb);
	}
	printf("%d\n", ans);
	return 0;
}
