#include<bits/stdc++.h>
using namespace std;
const double eps=1e-4;
int n,mark[1024],s[1024],c;
double x[105][2],y[105][2];
vector<int>g[1024];

double dis(double a1,double b1,double a2,double b2)
{
    return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}

void init()
{
    memset(mark,0,sizeof(mark));
    for(int i=0;i<2*n;i++)
        g[i].clear();
}

void addedge(int tx,int ty)
{
    g[tx].push_back(ty^1);
    g[ty].push_back(tx^1);
}

int dfs(int tx)
{
    if(mark[tx^1]) return 0;
    if(mark[tx]) return 1;
    mark[tx]=1;
    s[c++]=tx;
    for(int i=0;i<g[tx].size();i++)
    {
        if(!dfs(g[tx][i])) return 0;
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
                if(!dfs(i+1)) return 0;
            }
        }
    }
    return 1;
}

int get(double m)
{
    init();
    for(int i=0;i<n;i++)
    {
        for(int a=0;a<2;a++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int b=0;b<2;b++)
                {
                    double t=dis(x[i][a],y[i][a],x[j][b],y[j][b]);
                    if(t<2*m)
                    {
                        addedge(2*i+a,2*j+b);
                        //printf("%d %d\n",i,j);
                    }
                }
            }
        }
    }
    return solve();
}
int main()
{
    double L,R,M,ans;
    while(~scanf("%d",&n))
    {
        ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
                scanf("%lf%lf",&x[i][j],&y[i][j]);
        L=0;
        R=dis(10000,10000,-10000,-10000);
        while(fabs(R-L)>eps)
        {
            M=(R+L)/2;
            if(get(M))
            {
                ans=M;
                L=M;
            }
            else
            {
                R=M;
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
