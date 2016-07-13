#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
const int N=1024;
int mark[2*N],s[2*N],c,n,st[N][2],ed[N][2],t[N];
vector<int>g[2*N];

int ok(int i,int a,int j,int b)
{
    if(st[i][a]<st[j][b]&&ed[i][a]<=st[j][b]) return 1;
    if(st[j][b]<st[i][a]&&ed[j][b]<=st[i][a]) return 1;
    return 0;
}
void init()
{
    for(int i=0;i<2*n;i++) g[i].clear();
    memset(mark,0,sizeof(mark));
}
void add(int x,int y)
{
    g[x].push_back(y^1);
    g[y].push_back(x^1);
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

int main()
{
    int H1,M1,H2,M2,T1,T2,T;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d:%d",&H1,&M1);
            scanf("%d:%d",&H2,&M2);
            scanf("%d",&T);
            T1=H1*60+M1;
            T2=H2*60+M2;
            st[i][0]=T1;
            ed[i][0]=T1+T;
            st[i][1]=T2-T;
            ed[i][1]=T2;
        }
        init();
        for(int i=0;i<n;i++)
        {
            for(int a=0;a<2;a++)
            {
                for(int j=i+1;j<n;j++)
                {
                    for(int b=0;b<2;b++)
                    {
                        if(ok(i,a,j,b)==0)
                        add(i*2+a,j*2+b);
                    }
                }
            }
        }
        if(solve()==0) printf("NO\n");
        else
        {
            printf("YES\n");
            for(int i=0;i<2*n;i++)
            {
                if(mark[i])
                {
                    int a=i/2;
                    int b=i%2;
                    T1=st[a][b];
                    T2=ed[a][b];
                    printf("%02d:%02d %02d:%02d\n",T1/60,T1%60,T2/60,T2%60);
                }
            }
        }
    }
    return 0;
}
