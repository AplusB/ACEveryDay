#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define Mn 400
#define Mm 200005
#define mod 1000000007
#define CLR(a,b) memset((a),(b),sizeof((a)))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
#pragma comment(linker, "/STACK:102400000,102400000")
#define ul u<<1
#define ur (u<<1)|1
using namespace std;
typedef long long ll;
struct edge {
    int v,next;
}e[Mm];
struct point {
    int x,y;
}p[Mn];
int dis(point a,point b) {
   return abs(a.x-b.x)+abs(a.y-b.y);
}
int tot,head[Mn];
void addedge(int u,int v) {
    e[tot].v=v;
    e[tot].next=head[u];
    head[u]=tot++;
}
int pre[Mn];
int findpre(int x) {
    return x==pre[x]?pre[x]:pre[x]=findpre(pre[pre[x]]);
}
void ol(int a,int b) {
    a=findpre(a);
    b=findpre(b);
    if(a!=b) pre[a]=b;
}
int n,lk[Mn],vis[Mn],mark[Mn],match[Mn],ne[Mn];
int lca(int x,int y) {
    static int t=0;t++;
    while(1) {
        if(x!=-1) {
            x=findpre(x);
            if(vis[x]==t) return x;
            vis[x]=t;
            if(match[x]!=-1) x=ne[match[x]];
            else x=-1;
        }
        swap(x,y);
    }

}
queue<int> q;
void group(int a,int p) {
    while(a!=p) {
        int b=match[a],c=ne[b];
        if(findpre(c)!=p) ne[c]=b;
        if(mark[b]==2) mark[b]=1,q.push(b);
        if(mark[c]==2) mark[c]=1,q.push(c);
        ol(a,b),ol(b,c);
        a=c;
    }
}
void aug(int s) {
    for(int i=0;i<=n;i++) {
        ne[i]=-1;
        pre[i]=i;
        mark[i]=0;
        vis[i]=-1;
    }
    mark[s]=1;
    while(!q.empty()) q.pop();
    q.push(s);
    while((!q.empty())&&match[s]==-1) {
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=e[i].next) {
            int v=e[i].v;
            if(match[u]==v||findpre(u)==findpre(v)||mark[v]==2) continue;
            if(mark[v]==1) {
                int r=lca(u,v);
                //cout<<r<<endl;
                if(findpre(u)!=r) ne[u]=v;
                if(findpre(v)!=r) ne[v]=u;
                group(u,r);
                group(v,r);
            } else if(match[v]==-1) {
               //cout<<v<<endl;
                ne[v]=u;
                for(int x=v;~x;) {
                    int y=ne[x];
                    int mv=match[y];
                    match[x]=y,match[y]=x;
                    x=mv;
                }
                break;
            } else {
                ne[v]=u;
                q.push(match[v]);
                mark[match[v]]=1;
                mark[v]=2;
            }
        }
    }
}
void init() {
    tot=0;
    CLR(head,-1);
}
int main() {
    while(~scanf("%d",&n)) {
        int l;init();
        for(int i=1;i<=n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        scanf("%d",&l);
        for(int i=1;i<n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(dis(p[i],p[j])<=l) {
                    addedge(i,j);
                    addedge(j,i);
                }
            }
        }
        for(int i=1;i<=n;i++) match[i]=-1;
        for(int i=1;i<=n;i++) {
            if(match[i]==-1) aug(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(match[i]!=-1) ans++;
        }
        if(ans==n) {
            printf("YES\n");
        } else printf("NO\n");
    }
    return 0;
}
