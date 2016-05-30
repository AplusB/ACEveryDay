//统计前缀和，每次转移为相邻一个银行间，因而每个前缀和都会出现，求出最多区间为0的数，用n-最多区间为0的数
//若有n = 8，且a{} = 1 2 3 -6 1 2 3 -6 则为6次 -> 1 + 2 + 3 - 6 = 0操作为3的情况出现两次，此时只需要最少 8 - 2 = 6次就能让两个区间变成0
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int a[100005];
map<ll, int> m;
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, num = 0;
	ll sum = 0;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
		sum += a[i];
		num = max(num,++m[sum]);
	}

	printf("%d\n",n - num);

	return 0;
}
