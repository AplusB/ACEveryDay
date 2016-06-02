//hdoj  1528

#include<cstdio>
#include<math.h>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0X3f3f3f3f
typedef long long LL;

int ma[55][55];
bool in1[55];
bool in2[55];
bool vis[55];
int cx[55];
int cy[55];

int findpath(int u)
{
    for(int i=1;i<=52;i++)
    {
        if(!vis[i]&&in2[i]&&ma[u][i])
        {
            vis[i]=1;
            if(cy[i]==-1)
            {
                cx[u]=i;
                cy[i]=u;
                return 1;
            }
            else if(in1[cy[i]])
            {
                if(findpath(cy[i]))
                {
                    cy[i]=u;
                    cx[u]=i;
                    return 1;
                }
            }
        }
    }
    return 0;
}


void init()
{
    memset(ma,0,sizeof(ma));
    for(int i=1;i<=52;i++)
    {
        for(int j=1;j<i;j++)
            ma[i][j]=1;
    }
}

int get1(char x)
{
    if(x>='2'&&x<='9')
        return x-1-48;
    if(x=='T')
        return 9;
    if(x=='J')
        return 10;
    if(x=='Q')
        return 11;
    if(x=='K')
        return 12;
    if(x=='A')
        return 13;
}
int get2(char x)
{
    if(x=='C')
        return 1;
    if(x=='D')
        return 2;
    if(x=='S')
        return 3;
    if(x=='H')
        return 4;
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        char xx[3];
        memset(in1,0,sizeof(in1));
        memset(in2,0,sizeof(in2));

        for(int i=0;i<n;i++)
        {
            scanf("%s",xx);
            int s1=get1(xx[0]);
            s1=(s1-1)*4;
            int s2=get2(xx[1]);
            in2[s1+s2]=1;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",xx);
            int s1=get1(xx[0]);
            s1=(s1-1)*4;
            int s2=get2(xx[1]);
            in1[s1+s2]=1;
        }

//        for(int i=1;i<=52;i++)
//        {
//            if(in2[i])
//                printf("%d ",i);
//        }
//        puts("");
//
//        for(int i=1;i<=52;i++)
//        {
//            if(in1[i])
//                printf("%d ",i);
//        }
//        puts("");

        memset(cx,-1,sizeof(cx));
        memset(cy,-1,sizeof(cy));

        int ans=0;
        for(int i=1;i<=52;i++)
        {
            if(cx[i]==-1&&in1[i])
            {
                memset(vis,0,sizeof(vis));
                if(findpath(i))
                {
                    //printf("%d\n",i);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


/*

100
1
JD
JH
2
5D TC
4C 5H
3
2H 3H 4H
2D 3D 4D


*/
