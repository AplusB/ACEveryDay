//HDOJ  1016

#include<cstdio>
#include<math.h>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0X3f3f3f3f
typedef long long LL;

#define N 10010
int t;
int d[25];
bool vis[25];


int isprime(int n)
{
    if(n==1)
        return 0;
    int q=sqrt(n);

    for(int i=2;i<=q;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

void DFS(int num)
{
    if(num==t)
    {
        for(int i=0;i<num;i++)
        {
            if(i)
                printf(" ");
            printf("%d",d[i]);
        }
        puts("");
    }
    for(int i=2;i<=t;i++)
    {
        if(!vis[i])
        {
            if(!num)
            {
                d[num]=i;
                vis[i]=1;
                DFS(num+1);
            }
            else if(num==t-1)
            {
                int s1=i+d[num-1];
                int s2=i+d[0];
                if(isprime(s1)&&isprime(s2))
                {
                    d[num]=i;
                    vis[i]=1;
                    DFS(num+1);
                }
            }
            else
            {
                int s1=i+d[num-1];
                if(isprime(s1))
                {
                    d[num]=i;
                    vis[i]=1;
                    DFS(num+1);
                }
            }
            vis[i]=0;
        }
    }
}

int main()
{
    int T;
    T=1;
    while(~scanf("%d",&t))
    {
        memset(vis,0,sizeof(vis));
        printf("Case %d:\n",T++);
        d[0]=1;
        vis[1]=1;
        DFS(1);
        puts("");
    }
    return 0;
}


