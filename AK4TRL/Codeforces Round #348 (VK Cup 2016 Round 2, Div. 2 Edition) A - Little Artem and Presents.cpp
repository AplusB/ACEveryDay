//暴力美学
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	while(~scanf("%d",&n)){
		int ans = 0, flag = 0;
		while(n > 0){
			n -= (ans & 1? 1 : 2);
			ans ++;
		}
		printf("%d\n",ans);
	}

	return 0;
}
