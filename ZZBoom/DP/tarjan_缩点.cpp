//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=1e4+8;

struct asd{
    int to;
    int next;
};
asd q[N*5];
int head[N*5],tol;

int n;
int dfn[N];
int low[N];
int st[N],vis[N],in[N];
int p,tp,sum;
int kr[N];
int xx[N];

void INIT()
{
    tol=0;
    memset(head,-1,sizeof(head));
}
void add(int a,int b)
{
    q[tol].to=b;
    q[tol].next=head[a];
    head[a]=tol++;
}

void tarjan(int u)
{
    dfn[u]=low[u]=++p;
    st[++tp]=u;
    vis[u]=1;
    for(int i=head[u];i!=-1;i=q[i].next)
    {
        int x=q[i].to;
        if(!dfn[x]){
            tarjan(x);
            low[u]=min(low[u],low[x]);
        }
        else if(vis[x]){
            low[u]=min(low[u],dfn[x]);
        }
    }
    if(dfn[u]==low[u]){
        int temp;
        sum++;
        while(1){
            temp=st[tp];
            in[temp]=sum;
            vis[temp]=0;
            tp--;
            if(temp==u){
                break;
            }
        }
    }
}


void solve()
{
    memset(kr,0,sizeof(kr));
    memset(xx,0,sizeof(xx));
    for(int i=1;i<=n;i++){
        for(int v=head[i];v!=-1;v=q[v].next){
            int t=q[v].to;
            if(in[t]!=in[i]){
                kr[in[i]]++;
            }
        }
    }
    int ans=0,num=0,k;
    for(int i=1;i<=sum;i++){
        if(!kr[i]){
            num+=1;
            k=i;
        }
    }
    if(num==1){
        for(int i=1;i<=n;i++)
        {
            if(in[i]==k){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    else{
        puts("0");
    }
}

int main()
{
    int a,b,m;
    scanf("%d%d",&n,&m);
    INIT();
    while(m--){
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    tp=p=sum=0;
    memset(vis,0,sizeof(vis));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]){
            tarjan(i);
        }
    }
    solve();
    return 0;
}




