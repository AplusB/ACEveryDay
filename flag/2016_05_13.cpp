#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int deg[maxn];

int main(){
	int n, x, T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		memset(deg, 0, sizeof deg);
		for(int i = 2; i <= n; i++){
			scanf("%d", &x);
			x++;
			deg[x]++;
			deg[i]++;
		}
		int f = 1, cnt = 0, ans1, ans2 = 0;
		for(int i = 1; i <= n; i++){
			if(deg[i] == 1) cnt++;
			if(f) ans2 += (deg[i] + 1) / 2, f = 0;
			else ans2 += (deg[i] - 1) / 2;
		}
		ans1 = (cnt + 1) / 2;
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
