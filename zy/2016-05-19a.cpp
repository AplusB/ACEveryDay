#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int vis[11];
char m[10][10];
int ans;
int num;
   int n,k;
void dfs(int i)
{
    if(num==k) {ans++;return;}
    if(i>n) return;
    for(int j=1;j<=n;j++)
        if(m[i][j]=='#'&&(!vis[j]))
        {
            vis[j]=1;
            num++;
            dfs(i+1);
            vis[j]=0;
            num--;
        }
    dfs(i+1);
}

int main()
{

    while(~scanf("%d%d",&n,&k))
    {

        memset(vis,0,sizeof(vis));
       // memset(m,0,sizeof(m));
        getchar();
        if(n==-1&&k==-1) break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%c",&m[i][j]);
            getchar();
        }

         //for(int i=1;i<=n;i++)
         //   for(int j=1;j<=n;j++)
         //       printf("%c",m[i][j]);

        ans=0;
        num=0;
        dfs(1);
        cout<<ans<<endl;

    }
    return 0;
}
