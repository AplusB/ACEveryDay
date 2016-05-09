#include<bits/stdc++.h>
#define MAXN 100007
using namespace std;

int a[MAXN][12];
int n,x,y,maxt,ans;

int MAX3(int a ,int b, int c){
	if(a>b&&a>c) return a;
	if(b>c) return b;
	return c;
}

int main()
{
	while(scanf("%d",&n) && n){
		memset(a,0,sizeof(a));
		maxt = ans = 0;	
		while(n--){
			scanf("%d%d",&x,&y);
			if(abs(x-5)>y) continue;
			a[y][x]++;
			if(y>maxt) maxt = y;
		}
		for(int i=1;i<=maxt;i++){
			a[i][0] += MAX3(0,a[i-1][0],a[i-1][1]);
			for(int j=1;j<11;j++) {
				a[i][j] += MAX3(a[i-1][j-1],a[i-1][j],a[i-1][j+1]);
				if(a[i][j] > ans) ans = a[i][j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
