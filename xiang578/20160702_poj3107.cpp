#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
using namespace std;
const int N=60000;
vector<int>ans;
int n,mi,son[N],head[N],tot;
struct
{
    int to;
    int next;
}g[2*N];

void dfs(int x,int fa)
{
    int tmp=0;
    for(int i=head[x];i!=-1;i=g[i].next)
    {
        int y=g[i].to;
        if(fa==y) continue;
        dfs(y,x);
        son[x]+=son[y]+1;
        tmp=max(tmp,son[y]+1);

    }
    tmp=max(tmp,n-son[x]-1);
    if(tmp<mi)
    {
        mi=tmp;
        ans.clear();
        ans.push_back(x);
    }
    else if(tmp==mi)
    {
        ans.push_back(x);
    }
}

int main()
{
    int a,b;
    while(~scanf("%d",&n))
    {
        memset(head,0xff,sizeof(head));
        tot=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            g[tot].to=a;
            g[tot].next=head[b];
            head[b]=tot;
            tot++;

            g[tot].to=b;
            g[tot].next=head[a];
            head[a]=tot;
            tot++;
        }
        memset(son,0,sizeof(son));
        ans.clear();
        mi=n;
        dfs(1,0);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

/*
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
using namespace std;
const int N=50000+10;
vector<int>g[N];
vector<int>ans;
int n,mi,son[N];
void dfs(int x,int fa)
{
    int tmp=0;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(fa==y) continue;
        dfs(y,x);
        son[x]+=son[y]+1;
        tmp=max(tmp,son[y]+1);
    }
    tmp=max(tmp,n-son[x]-1);
    //printf("   %d %d\n",tmp,mi);
    if(tmp<mi)
    {
        mi=tmp;
        ans.clear();
        ans.push_back(x);
    }
    else if(tmp==mi)
    {
        ans.push_back(x);
    }
}
int main()
{
    int a,b;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(son,0,sizeof(son));
        ans.clear();
        mi=n;
        dfs(1,0);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
*/
