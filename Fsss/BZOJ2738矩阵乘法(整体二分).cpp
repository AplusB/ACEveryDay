#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<math.h>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=505;
const int MAX=1000000100;
const int mod=100000000;
const int MOD1=1000000007;
const int MOD2=1000000009;
const double EPS=0.00000001;
typedef long long ll;
const ll MOD=1000000007;
const int INF=1000000010;
typedef double db;
typedef unsigned long long ull;
struct node {
    int x,y,w;
    node(){}
    node(int x,int y,int w):x(x),y(y),w(w){}
    bool operator < (const node a) const{
        return w<a.w;
    }
}p[N*N];
struct qnode {
    int x1,x2,y1,y2,k,id;
    qnode(){}
    qnode(int x1,int y1,int x2,int y2,int k,int id):x1(x1),y1(y1),x2(x2),y2(y2),k(k),id(id){}
    bool operator < (const qnode a) const{
        return k<a.k;
    }
}q[60010],h[60010];
int n,ans[60010],f[N][N];
void add(int x,int y,int z) {
    int i,j;
    for (i=x;i<=n;i+=i&(-i))
        for (j=y;j<=n;j+=j&(-j)) f[i][j]+=z;
}
int getsum(int x,int y) {
    int i,j,ret=0;
    for (i=x;i;i-=i&(-i))
        for (j=y;j;j-=j&(-j)) ret+=f[i][j];
    return ret;
}
void div(int l,int r,int L,int R) {
    if (L>R) return ;
    int i,k=L,g,mid=(l+r)>>1;
    if (l==r) {
        for (i=L;i<=R;i++) ans[q[i].id]=p[l].w;
        return ;
    }
    for (i=l;i<=mid;i++) add(p[i].x,p[i].y,1);
    for (i=L;i<=R;i++)
    if (getsum(q[i].x2,q[i].y2)-getsum(q[i].x1-1,q[i].y2)-getsum(q[i].x2,q[i].y1-1)+getsum(q[i].x1-1,q[i].y1-1)>=q[i].k) h[k++]=q[i];
    g=k;
    for (i=L;i<=R;i++)
    if (getsum(q[i].x2,q[i].y2)-getsum(q[i].x1-1,q[i].y2)-getsum(q[i].x2,q[i].y1-1)+getsum(q[i].x1-1,q[i].y1-1)<q[i].k) h[k++]=q[i];
    for (i=L;i<=R;i++) q[i]=h[i];
    div(mid+1,r,g,R);
    for (i=l;i<=mid;i++) add(p[i].x,p[i].y,-1);
    div(l,mid,L,g-1);
}
int main()
{
    int i,j,m,x,g=0,x1,x2,y1,y2,k;
    scanf("%d%d", &n, &m);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
            scanf("%d", &x);
            p[++g]=node(i,j,x);
        }
    sort(p+1,p+g+1);
    for (i=1;i<=m;i++) {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
        q[i]=qnode(x1,y1,x2,y2,k,i);
    }
    sort(q+1,q+m+1);
    div(1,g,1,m);
    for (i=1;i<=m;i++) printf("%d\n", ans[i]);
    return 0;
}
