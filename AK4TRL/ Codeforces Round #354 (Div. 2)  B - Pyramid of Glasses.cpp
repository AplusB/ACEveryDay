//枚举i层第i个酒杯的量进行分流，一杯酒流向两边各为当前杯流进的数量的一半
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, t;
	double c[15][15];
	while (~scanf("%d%d",&n,&t)){
		memset(c,0,sizeof c);
		c[1][1] = (double)t;
		int ans = 0;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= i; ++j){
				if (c[i][j] >= 1){
					c[i + 1][j] += (c[i][j] - 1) / 2.0;
					c[i + 1][j + 1] += (c[i][j] - 1) / 2.0;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
