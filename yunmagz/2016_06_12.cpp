//lightoj1201 - A Perfect Murder	
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define ull unsigned long long  
#define mod 100000007  
#define inf 0x3f3f3f3f  
int f[1234];  
int dp[1234][2],head[1234],tot,used[1234];  
struct edge  
{  
    int u,v,next;  
}edge[1234*1234];  
void init(int n)  
{  
    memset(head,-1,sizeof(head));  
    memset(used,0,sizeof(used));  
    tot=0;  
    for(int i=0;i<=n;i++)  
        f[i]=i;  
}  
void add(int u,int v)  
{  
    edge[tot].v=v;  
    edge[tot].next=head[u];  
    head[u]=tot++;  
}  
int finde(int x)  
{  
    if(x!=f[x])  
        return f[x]=finde(f[x]);  
    return x;  
}  
void dfs(int u)  
{  
    dp[u][0]=0;  
    dp[u][1]=1;  
    used[u]=1;  
    for(int i=head[u];i!=-1;i=edge[i].next)  
    {  
        int v=edge[i].v;  
        if(used[v]) continue;  
        dfs(v);  
        dp[u][0]+=max(dp[v][1],dp[v][0]);  
        dp[u][1]+=dp[v][0];  
    }  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        int n,m,v,u;  
        scanf("%d %d",&n,&m);  
        init(n);  
        for(int i=0;i<m;i++)  
        {  
            scanf("%d %d",&u,&v);  
            add(u,v);  
            add(v,u);  
            int x=finde(u);  
            int y=finde(v);  
            if(x!=y)  
                f[y]=x;  
        }  
        int ans=0;  
        for(int i=1;i<=n;i++)  
        {  
            if(used[i]==0&&f[i]==i)  
            {  
                dfs(i);  
                ans+=max(dp[i][0],dp[i][1]);  
                used[i]=1;  
            }  
        }  
        printf("Case %d: %d\n",cas,ans);  
    }  
    return 0;  
}  
