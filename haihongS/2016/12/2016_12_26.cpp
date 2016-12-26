#include <bits/stdc++.h>

using namespace std;
const int maxn=3e2+9;

int a[maxn],flag[maxn],ans[maxn],cnt[maxn];
char mapp[maxn][maxn];
vector<int> G[maxn];

struct II
{
    int pos,v;
};
vector<II> b[maxn];

int update(int v,int fa,int inn);
int cmp(II x,II y);

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<maxn;i++) G[i].clear(),b[i].clear();
        memset(flag,-1,sizeof(flag));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%s",mapp[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mapp[i][j]=='1')
                    G[i].push_back(j+1);
            }
        }
        int inn=1;
        for(int i=1;i<=n;i++)
        {
            if(flag[i]==-1)
                update(i,i,inn++);
        }
        for(int i=1;i<=n;i++)
        {
            int v=flag[i];
            //printf("*%d %d\n",a[i],v);
            b[v].push_back(II{i,a[i]});
        }
        for(int i=1;i<inn;i++)
            sort(b[i].begin(),b[i].end(),cmp);
        for(int i=1;i<=n;i++)
        {
            int pos=cnt[flag[i]];
            cnt[flag[i]]++;
            ans[i]=b[flag[i]][pos].v;
        }

        for(int i=1;i<=n;i++)
        {
            if(i!=1) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

int cmp(II x,II y)
{
    return x.v<y.v;
}

int update(int v,int fa,int inn)
{
    flag[v]=inn;
    int len=G[v].size();
    for(int i=0;i<len;i++)
    {
        int nx=G[v][i];
        if(nx==fa) continue;
        if(flag[nx]==-1)
            update(nx,v,inn);
    }
    return 0;
}
