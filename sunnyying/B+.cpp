#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
char a[2000],b[2000];
long long n,p[2000],xxx[2000][2000],sum[2000][2000],sum1[2000][2000];
void init(int x)
{
    memset(p,0,sizeof(p));
    p[x]=x-1;
    int i,j=x-1;
    for(i=x+1;i<=n;i++)
    {
        while(j>x-1&&b[j+1]!=b[i]) j=p[j];
        if(b[j+1]==b[i]) j=j+1;
          p[i]=j;
    }
    xxx[x][x]=0;
    for(i=x+1;i<=n;i++)
        if((i-x+1)%(i-p[i])==0) xxx[x][i]=(i-x+1)/(i-p[i])-1;
}
int main()
{
    while(~scanf("%s",a))
    {
        memset(sum,0,sizeof(sum));
        memset(sum1,0,sizeof(sum1));
        n=strlen(a);
        memset(xxx,0,sizeof(xxx));
        for(int i=0;i<n;i++) b[i+1]=a[i];
        for(int i=1;i<=n;i++) init(i);
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=j;i++)
            {
                int x=xxx[i][j];
                sum[j][x]++;
            }
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<=n;j++) sum1[i][j]=sum1[i+1][j];
            for(int j=i;j<=n;j++)
            {
                int x=xxx[i][j];
                sum1[i][x]++;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=n;j++)
            {
                if(sum[i][j]==0||sum1[i+1][j]==0) continue;
                ans=ans+sum[i][j]*sum1[i+1][j];
            }
        cout<<ans<<endl;
    }
    return 0;
}
