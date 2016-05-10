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
const int N=50010;
const int MAX=1000000100;
const int mod=100000000;
const int MOD1=1000000007;
const int MOD2=1000000009;
const double EPS=0.00000001;
typedef long long ll;
const ll MOD=998244353;
const int INF=1000000010;
typedef double db;
typedef unsigned long long ull;
struct node {
    int x,y,z,w,idx;
    node(){}
    node(int x,int y,int z,int w,int idx):x(x),y(y),z(z),w(w),idx(idx){}
}q[8*N],s[8*N],s1[8*N],s2[8*N];
int cnt,f[2*N],a[2*N],ans[N];
int cmy(node a,node b) {
    if (a.y!=b.y) return a.y<b.y;
    return a.idx<b.idx;
}
int cmz(node a,node b) {
    if (a.z!=b.z) return a.z<b.z;
    return a.idx<b.idx;
}
void add(int a,int b) {
    for (;a<=cnt;a+=a&(-a)) f[a]+=b;
}
int getsum(int a) {
    int ret=0;
    for (;a;a-=a&(-a)) ret+=f[a];
    return ret;
}
void cdq1(int l,int r) {
    if (r<=l) return ;
    int mid=(l+r)>>1;
    cdq1(l,mid);cdq1(mid+1,r);
    int i,j=1,g1=0,g2=0;
    for (i=l;i<=mid;i++)
    if (!s[i].w) s1[++g1]=s[i];
    for (i=mid+1;i<=r;i++)
    if (s[i].w) s2[++g2]=s[i];
    sort(s1+1,s1+g1+1,cmy);
    sort(s2+1,s2+g2+1,cmy);
    for (i=1;i<=g2;i++) {
        while (j<=g1&&s1[j].y<=s2[i].y) add(s1[j++].x,1);
        ans[s2[i].idx]+=s2[i].w*getsum(s2[i].x);
    }
    for (i=1;i<j;i++) add(s1[i].x,-1);
}
void cdq(int l,int r) {
    if (r<=l) return ;
    int mid=(l+r)>>1;
    cdq(l,mid);cdq(mid+1,r);
    int i,g=0;
    for (i=l;i<=mid;i++)
    if (!q[i].w) s[++g]=q[i];
    for (i=mid+1;i<=r;i++)
    if (q[i].w) s[++g]=q[i];
    sort(s+1,s+g+1,cmz);
    cdq1(1,g);
}
int uniqu(int n) {
    int i,cnt=1;
    sort(a+1,a+n+1);
    for (i=2;i<=n;i++)
    if (a[i]!=a[cnt]) a[++cnt]=a[i];
    return cnt;
}
int find_x(int x) {
    int l=1,r=cnt,mid=(l+r)>>1;
    while (l<r)
    if (a[mid]>=x) { r=mid;mid=(l+r)>>1; }
    else { l=mid+1;mid=(l+r)>>1; }
    return l;
}
int main()
{
    int i,n,m,t,op,x1,x2,y1,y2,z1,z2;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        m=cnt=0;
        for (i=1;i<=n;i++) {
            scanf("%d", &op);
            if (op==1) {
                scanf("%d%d%d", &x1, &y1, &z1);
                a[++cnt]=x1;ans[i]=-1;
                q[++m]=node(x1,y1,z1,0,0);
            } else {
                scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
                a[++cnt]=x1-1;a[++cnt]=x2;ans[i]=0;
                q[++m]=node(x2,y2,z2,1,i);
                q[++m]=node(x1-1,y2,z2,-1,i);
                q[++m]=node(x2,y1-1,z2,-1,i);
                q[++m]=node(x2,y2,z1-1,-1,i);
                q[++m]=node(x1-1,y1-1,z2,1,i);
                q[++m]=node(x1-1,y2,z1-1,1,i);
                q[++m]=node(x2,y1-1,z1-1,1,i);
                q[++m]=node(x1-1,y1-1,z1-1,-1,i);
            }
        }
        cnt=uniqu(cnt);
        for (i=1;i<=cnt;i++) f[i]=0;
        for (i=1;i<=m;i++) q[i].x=find_x(q[i].x);
        cdq(1,m);
        for (i=1;i<=n;i++)
        if (~ans[i]) printf("%d\n", ans[i]);
    }
    return 0;
}
