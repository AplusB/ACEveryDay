#include<bits/stdc++.h>
using namespace std;
int a[1007][1007];
int ans,x,y,n,m;
int main()
{
	int T,i,j;
	memset(a,0,sizeof(a));
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&x,&y);
		ans = 0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				a[i][j] +=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
				if(i>=x&&j>=y)
					ans = max(ans,a[i][j] - a[i-x][j] - a[i][j-y] +a[i-x][j-y]);			
			}
		printf("%d\n",ans);
	}
	return 0;
}
