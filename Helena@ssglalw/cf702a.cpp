#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 100005;

int n;
int a[MAX_N];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	int cnt = 1;
	int ans = 1;
	for(int i=1; i<n; i++){
		if(a[i] > a[i-1]) cnt++;
		else{
			ans = max(ans, cnt);
			cnt = 1;
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
