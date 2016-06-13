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
        for(int i=1;i<=n;i++)
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
        int T,x,y;
        scanf("%d",&T);
        init();
        while(T--)
        {
                int ans=0;
                scanf("%d %d",&n,&m);
                init();
                while(m--)
                {
                        scanf("%d %d",&x,&y);
                        mix(x,y);
                }
                for(int i=1;i<=n;i++)
                {
                        //printf("%d ",f[i]);
                        if(f[i]==i) ans++;
                }
                printf("%d\n",ans);
        }
        return 0;
}
