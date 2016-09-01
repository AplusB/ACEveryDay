#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef int LL;

LL t,n,m,ans;
const int maxn = 1000+10;
char  a[maxn][maxn]; 

int main()
{
	LL i,j,k,l,u,v,res,tmp,ca=0;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++)scanf("%s",(a[i]+1));ans=0;
		for(i=2;i<n-ans;i++){
			for(j=2;j<m;j++){
				if(a[i][j]=='*'){
					tmp=1e9;
					res=0;u=i-1;v=j+1;while(u>0&&v<=m&&a[u][v]=='*')res++,u--,v++;tmp=min(tmp,res);
					res=0;u=i+1;v=j+1;while(u<=n&&v<=m&&a[u][v]=='*')res++,u++,v++;tmp=min(tmp,res);
					res=0;u=i+1;v=j-1;while(u<=n&&v>0&&a[u][v]=='*')res++,u++,v--;tmp=min(tmp,res);
					res=0;u=i-1;v=j-1;while(u>0&&v>0&&a[u][v]=='*')res++,u--,v--;tmp=min(tmp,res);
					ans=max(ans,tmp);
				}
			}
		}
		if(ans)ans=ans*2+1;
		printf("%d\n",ans);
	}
	return 0;
}

