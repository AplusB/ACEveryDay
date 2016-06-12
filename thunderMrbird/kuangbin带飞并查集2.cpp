#include<iostream>
#include <cstdio>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;
int n,m,p,t,st;
int f[30005];
void init()
{
        for(int i=0;i<n;i++)
                f[i]=i;
}
int found(int x)
{
        if(f[x]!=x)
                return f[x]=found(f[x]);
        return x;
}
void mix(int x,int y)
{
        int lx=found(x);
        int ly=found(y);
        if(lx!=ly)
        {
                f[ly]=lx;
        }
}
int main()
{
        while(scanf("%d %d", &n,&m)!=EOF&&(m||n))
        {
                int ans=0;
                init();
                while(m--)
                {
                        scanf("%d",&p);
                        scanf("%d",&st);
                        for(int i=1;i<p;i++)
                        {
                                scanf("%d",&t);
                                mix(st,t);
                        }
                }
                t=found(0);
                for(int i=0;i<n;i++)
                {
                        if(found(i)==t) ans++;
                }
                printf("%d\n",ans);
        }
        return 0;
}
