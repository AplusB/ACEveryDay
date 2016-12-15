#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=1e9+9;
struct II
{
    int x,y,area,p;
}num[500],rec[500];

int n;
int dp[maxn];

int main()
{
    while(scanf("%d",&n) && n)
    {
        for(int i=0;i<n;i++) scanf("%d%d",&num[i].x,&num[i].y);

        int loca=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1,y1,x2,y2;
                x1=num[i].x,y1=num[i].y;
                x2=num[j].x,y2=num[j].y;
                if(x1==x2)
                    rec[loca].area=abs(y1-y2);
                else if(y1==y2)
                    rec[loca].area=abs(x1-x2);
                else
                    rec[loca].area=abs(x1-x2)*abs(y1-y2);
                int tmp=max(x1,x2);
                x1=min(x1,x2);x2=tmp;
                tmp=max(y1,y2);
                y1=min(y1,y2);y2=tmp;

                rec[loca].p=0;
                for(int k=0;k<n;k++)
                {
                    if(x1<=num[k].x && num[k].x<=x2)
                    {
                        if(y1<=num[k].y && num[k].y<=y2)
                        {
                            rec[loca].p=(rec[loca].p) | (1<<k);
                        }
                    }
                }
                loca++;
            }
        }

        for(int i=0;i<(1<<n);i++) dp[i]=inf;
        dp[0]=0;

        for(int i=0;i<loca;i++)
        {
            for(int j=0;j<(1<<n);j++)
            {
                int tmp=j|(rec[i].p);
                dp[tmp]=min(dp[tmp],dp[j]+rec[i].area);
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
    }
    return 0;
}
