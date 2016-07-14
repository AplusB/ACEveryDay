#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
const int N=1024;
int mark[2*N],s[2*N],c,n,A,B,sx1,sx2,sy1,sy2,ax[N],ay[N],bx[N],by[N],tx[N],ty[N];
vector<int>g[2*N];

int dis(int a1,int b1,int a2,int b2)
{
    return abs(a1-a2)+abs(b1-b2);
}

void init()
{
    for(int i=0;i<2*n;i++) g[i].clear();
    memset(mark,0,sizeof(mark));
}

void add(int x,int y)
{
    g[x].push_back(y);
}

int dfs(int x)
{
    if(mark[x^1]) return 0;
    if(mark[x]) return 1;
    mark[x]=1;
    s[c++]=x;
    for(int i=0;i<g[x].size();i++)
    {
        if(!dfs(g[x][i])) return 0;
    }
    return 1;
}
int solve()
{
    for(int i=0;i<2*n;i+=2)
    {
        if(!mark[i]&&!mark[i+1])
        {
            c=0;
            if(!dfs(i))
            {

                while(c>0)
                    mark[s[--c]]=0;
                if(!dfs(i+1))
                    return 0;
            }
        }
    }
    return 1;
}
int get(int k)
{
    int tmp=dis(tx[n],ty[n],tx[n+1],ty[n+1]);
    init();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int i1=dis(tx[i],ty[i],tx[n],ty[n]);
            int j1=dis(tx[j],ty[j],tx[n],ty[n]);

            int i2=dis(tx[i],ty[i],tx[n+1],ty[n+1]);
            int j2=dis(tx[j],ty[j],tx[n+1],ty[n+1]);
            if(i1+j1>k)
            {
                add(2*i,2*j+1);
                add(2*j,2*i+1);
            }
            if(i2+j2>k)
            {
                add(2*i+1,2*j);
                add(2*j+1,2*i);
            }
            if(i1+j2+tmp>k)
            {
                add(2*i,2*j);
                add(2*j+1,2*i+1);
            }
            if(i2+j1+tmp>k)
            {
                add(2*i+1,2*j+1);
                add(2*j,2*i);
            }
        }
    }
    for(int i=0;i<A;i++)
    {
        add(2*ax[i]+1,2*ay[i]);
        add(2*ay[i]+1,2*ax[i]);
        add(2*ax[i],2*ay[i]+1);
        add(2*ay[i],2*ax[i]+1);
    }
    for(int i=0;i<B;i++)
    {
        add(2*bx[i],2*by[i]);
        add(2*by[i],2*bx[i]);
        add(2*bx[i]+1,2*by[i]+1);
        add(2*by[i]+1,2*bx[i]+1);
    }
    return solve();
}
int main()
{
    int L,R,M,ans;
    while(~scanf("%d%d%d",&n,&A,&B))
    {
       scanf("%d%d%d%d",&tx[n],&ty[n],&tx[n+1],&ty[n+1]);
        for(int i=0;i<n;i++)
            scanf("%d%d",&tx[i],&ty[i]);
        for(int i=0;i<A;i++)
        {
            scanf("%d%d",&ax[i],&ay[i]);
            ax[i]--;
            ay[i]--;

        }
        for(int i=0;i<B;i++)
        {
            scanf("%d%d",&bx[i],&by[i]);
            bx[i]--;
            by[i]--;
        }
        ans=-1;
        L=0;
        R=4000000+10;
        while(L<=R)
        {
            M=(R+L)/2;
            if(get(M))
            {
                ans=M;
                R=M-1;
            }
            else
            {
                L=M+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
