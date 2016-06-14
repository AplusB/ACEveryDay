//lightoj	1257 - Farthest Nodes in a Tree (II)
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define ull unsigned long long  
#define mod 1000000007  
#define inf 0x3f3f3f3f  
int dp[40000];  
struct edge  
{  
    int u,v,w,next;  
}edge[80000];  
int head[40000],tot,used[40000],s,mlen;  
void init()  
{  
    memset(dp,0,sizeof(dp));  
    memset(head,-1,sizeof(head));  
    memset(used,0,sizeof(used));  
    tot=0;  
}  
void add(int u,int v,int w)  
{  
    edge[tot].v=v;  
    edge[tot].w=w;  
    edge[tot].next=head[u];  
    head[u]=tot++;  
}  
void dfs(int u,int pre,int len)  
{  
    if(mlen<len)  
    {  
        s=u;  
        mlen=len;  
    }  
    for(int i=head[u];i!=-1;i=edge[i].next)  
    {  
        int v=edge[i].v;  
        int w=edge[i].w;  
        if(v==pre) continue;  
        dfs(v,u,len+w);  
        dp[v]=max(dp[v],len+w);  
    }  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        int n,u,v,w;  
        init();  
        scanf("%d",&n);  
        for(int i=0;i<n-1;i++)  
        {  
            scanf("%d %d %d",&u,&v,&w);  
            add(u,v,w);  
            add(v,u,w);  
        }  
        s=mlen=0;  
        dfs(1,-1,0);  
        dfs(s,-1,0);  
        dfs(s,-1,0);  
        printf("Case %d:\n",cas);  
        for(int i=0;i<n;i++)  
            printf("%d\n",dp[i]);  
    }  
    return 0;  
}  
