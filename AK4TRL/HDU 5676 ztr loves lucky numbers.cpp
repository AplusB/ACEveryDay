//暴力，先把所有情况与处理出来，再根据给出数据判断数字位置
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
typedef long long ll;
ll flag[100000], cnt;
void dfs(int len, int mid, int numc, ll num){
	if(numc == len){
		flag[cnt++] = num;
		return ;
	}
	else{
		if(mid > 0)
			dfs(len, mid-1, numc + 1, num * 10 + 4);
		if(len - numc > mid)
			dfs(len, mid, numc + 1, num * 10 + 7);
	}
	return ;
}
void init(){
	for(int i = 2; i <= 18; i += 2)
		dfs(i,i/2,0,0);
	std::sort(flag,flag+cnt);
}
int main(){
#ifdef hantai
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cnt = 0;
	init();
	int t;
	std::scanf("%d",&t);
	while(t--){
		ll a;
		std::cin >> a;
		ll id = std::lower_bound(flag,flag+cnt,a)-flag;
		if(a >= 1e18)
			puts("44444444447777777777");
		else
			std::printf("%lld\n",flag[id]);
	}

	return 0;
}
