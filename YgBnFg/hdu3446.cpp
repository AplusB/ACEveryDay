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
#define Mm 20005
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
int tot,head[Mn];
void addedge(int u,int v) {
    e[tot].v=v;
    e[tot].next=head[u];
    head[u]=tot++;
}
int cnt,pre[Mn];
int findpre(int x) {
    return x==pre[x]?pre[x]:pre[x]=findpre(pre[pre[x]]);
}
void ol(int a,int b) {
    a=findpre(a);
    b=findpre(b);
    if(a!=b) pre[a]=b;
}
int lk[Mn],vis[Mn],mark[Mn],match[Mn],ne[Mn];
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
    for(int i=0;i<=cnt;i++) {
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
                if(findpre(u)!=r) ne[u]=v;
                if(findpre(v)!=r) ne[v]=u;
                group(u,r);
                group(v,r);
            } else if(match[v]==-1) {
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
int mp[Mn][Mn],num[Mn][Mn];
void init() {
    tot=0;cnt=0;
    CLR(mp,0);
    CLR(head,-1);
    CLR(num,0);
}
int way[20][2]={-2,-2,-2,-1,-2,1,-2,2,-1,-2,-1,-1,-1,0,-1,1,-1,2,0,-1,0,1,1,-2,1,-1,1,0,1,1,1,2,2,-2,2,-1,2,1,2,2};
int main() {
    int t,n,m,kx,ky;
    char s[Mn];
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++) {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0;i<n;i++) {
            scanf("%s",s);
            for(int j=0;j<m;j++) {
                if(s[j]=='K') {
                    kx=i,ky=j;
                }
                if(s[j]!='#') {
                    num[i][j]=++cnt;
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!num[i][j]||(i==kx&&j==ky)) continue;
                for(int k=0;k<20;k++) {
                    int x=i+way[k][0];
                    int y=j+way[k][1];
                    if(x<0||x>=n||y<0||y>=m||(x==kx&&y==ky)||!num[x][y]) continue;
                    int u=num[i][j],v=num[x][y];
                    if(!mp[u][v]) {
                        addedge(u,v);
                        addedge(v,u);
                        mp[u][v]=mp[v][u]=1;
                    }
                }
            }
        }
        for(int i=1;i<=cnt;i++) match[i]=-1;
        for(int i=1;i<=cnt;i++) {
            if(match[i]==-1) {
                aug(i);
            }
        }
        for(int k=0;k<20;k++) {
            int x=kx+way[k][0];
            int y=ky+way[k][1];
            if(x<0||x>=n||y<0||y>=m||!num[x][y]) continue;
            int u=num[kx][ky],v=num[x][y];
            addedge(u,v);
            addedge(v,u);
        }
        aug(num[kx][ky]);
        printf("Case #%d: ",cas);
        if(match[num[kx][ky]]==-1) printf("daizhenyang lose\n");
        else printf("daizhenyang win\n");
    }
    return 0;
}
