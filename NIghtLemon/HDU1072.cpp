#include<bits/stdc++.h>
using namespace std;

int mx[4]={0,0,1,-1};
int my[4]={1,-1,0,0};
int a[10][10],b[10][10],s[10][10];
int n,m,sx,sy,ex,ey,ans;

void dfs(int x,int y,int z,int k){
	if(z==0) return;
	if(a[x][y]==3){
		ans = min(k,ans);
		return;
	}
	if(s[x][y]<=k&&b[x][y]>=z) return;
	s[x][y]=k;
	b[x][y]=z;
	for(int i=0;i<4;i++)if(a[x+mx[i]][y+my[i]]!=0){
		int p=x+mx[i],q=y+my[i];
		if(a[x][y]==4)
			dfs(p,q,5,k+1);
		else dfs(p,q,z-1,k+1);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		ans = 1000;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				s[i][j] = 1000;
				if(a[i][j]==2){
					sx = i; sy = j;
				}
				if(a[i][j]==3){
					ex = i; ey = j;
				}
			}
		dfs(sx,sy,6,0);
		if(ans!=1000) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
