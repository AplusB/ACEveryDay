//poj 1724
//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<queue>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=1e2+10;
struct asd{
    int to;
    int w;
    int c;
    int next;
};
asd q[N*N*2];
int tol,head[N*N*2];
bool vis[N];
int used[N];
int n,k;

void add(int a,int b,int c,int d)
{
    q[tol].to=b;
    q[tol].w=c;
    q[tol].c=d;
    q[tol].next=head[a];
    head[a]=tol++;
}
struct node{
    int id,dis,time;
    friend bool operator<(node a,node b)
    {
        if(a.dis==b.dis)
            return a.time>b.time;
        return a.dis>b.dis;
    }
};
int spfa(int s,int t)
{
    priority_queue<node>e;
    node u;
    u.id=s;
    u.dis=u.time=0;
    e.push(u);
    while(!e.empty())
    {
        u=e.top();
        e.pop();
        if(u.id==n){
            return u.dis;
        }
        for(int i=head[u.id];i!=-1;i=q[i].next)
        {
            node v;
            v.id=q[i].to;
            if(u.time+q[i].c<=k){
                v.dis=u.dis+q[i].w;
                v.time=u.time+q[i].c;
                e.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    int m;
    cin>>k;
    cin>>n;
    cin>>m;
    tol=0;
    memset(head,-1,sizeof(head));
    for(int i=0;i<m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add(a,b,c,d);
    }
    int ans=spfa(1,n);
    printf("%d\n",ans);
    return 0;
}
