/*
题意： 
就是有n个点，本来相邻点之间就有一条边，1和n之间也有一条，然后给你几个特殊点，说这些特殊点和其他所有点都连起来了，
然后算一个所有边的权值和，每条边的权值等于两个点的c相乘。 

思路： 
水题啊…感觉有好多方法吧。

弱的思路：你把所有点都相连的情况，把所有边权值和算出来，
然后没有被标记的点拿出来，把他们两两相连的边的权值也减掉，
但是你会发现就算没有标记但是相邻还是会有边，
所以加上这些就好了。 

比赛时的挫code…………
*/

#include<cstdio>
#include<math.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef __int64 LL;

const int N=1e5+10;

LL v1[N];
LL v2[N];
bool vis[N];
LL sum[N];
LL s2[N];

int main()
{
    int n,k,x;
    scanf("%d%d",&n,&k);
    memset(vis,0,sizeof(vis));
    memset(sum,0,sizeof(sum));
    memset(s2,0,sizeof(s2));

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v1[i]);
        sum[i]=sum[i-1]+v1[i];
    }
    LL ans1=0,ans2=0,ans3=0;
    for(int i=1;i<=n;i++)
        ans1+=v1[i]*(sum[i-1]); //刚刚好 ，全部相连 

    for(int i=1;i<=k;i++)
    {
        scanf("%d",&x);
        vis[x]=1;
    }
    int num=1;
    for(int i=1;i<=n;i++)
    {
        if(i==n)
        {
            if(!vis[i])
            {
                if(vis[i]==vis[1])
                    ans2+=v1[1]*v1[n];
                v2[num]=v1[i];
                s2[num]=s2[num-1]+v2[num];
                ++num;
            }
        }
        else{
            if(!vis[i])
            {
                if(vis[i]==vis[i+1])
                    ans2+=v1[i]*v1[i+1];    
                v2[num]=v1[i];
                s2[num]=s2[num-1]+v2[num];
                ++num;
            }
        }

    }
    for(int i=1;i<=num;i++)
        ans3+=v2[i]*s2[i-1];
//  printf("%I64d %I64d %I64d\n",ans1,ans2,ans3);
    printf("%I64d\n",ans1+ans2-ans3);
}
