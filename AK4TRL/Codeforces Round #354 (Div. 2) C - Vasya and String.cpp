//尺取法 
//给一行只有a,b字符组成的n长度字符串，在最多改变k个字符的情况下可以组成的最长美丽字符串的长度（即连续相同字符最多的串
//
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n, k;
char c[100005];
int solve(char x){
	int ans = 0, cnt = 0, l = 0, r = 0;
	while(l < n && r < n){
		while ((c[r] == x || cnt < k) && r < n){
			if (c[r] != x)
				cnt++;
			r++;
		}
		ans = max(ans, r - l);
		while (c[l] == x && l <= r)
			l++;
		cnt--;
		l++;
	}
	return ans;
}
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	while (~scanf("%d%d",&n,&k)){
		scanf("%s",c);
		int maxna = solve('a'), maxnb = solve('b');
		printf("%d\n",max(maxna,maxnb));
	}

	return 0;
}
