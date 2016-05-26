//水题签到来一发
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, flag[105], a;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i){
		cin >> a; flag[a] = i;
	}
	int maxn = max(abs(flag[1] - 1),abs(flag[1] - n));
	int maxn1 = max(abs(flag[n] - 1), abs(flag[n] - n));
	int ans = max(maxn,max(maxn1,abs(flag[n] - flag[1])));
	cout << ans << endl;

	return 0;
}
