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
const int N=10000010;
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
    ll x,y,z;
    node(){}
    node(ll x,ll y):x(x),y(y){}
    bool operator < (const node a) const{
        return x<a.x;
    }
}f[700000];
int g,a[N],q[N];
void deal(ll n) {
    int i,j,k=0;
    ll mul;
    memset(q,0,sizeof(q));
    for (i=2;i<=n;i++) {
        if (!q[i]) a[++k]=i;
        for (j=1;j<=k;j++) {
            if ((ll)a[j]*i>n) break ;
            q[a[j]*i]=1;
            if (i%a[j]==0) break ;
        }
    }
    n=n*n;
    for (i=1;i<=k;i++) {
        mul=(ll)a[i]*a[i];
        f[++g]=node(mul,a[i]);
        while (log(mul)+log(a[i])<=log(n)) {
            f[++g]=node(mul*a[i],a[i]);mul*=a[i];
        }
    }
    sort(f+1,f+g+1);f[1].z=2ll;
    for (i=2;i<=g;i++) f[i].z=f[i-1].z*f[i].y%MOD;
}
ll getans(ll n) {
    if (n<4) return 1ll;
    if (n>=f[g].x) return f[g].z;
    int l=1,r=g,mid=(l+r)>>1;
    while (l+1<r)
    if (f[mid].x>n) { r=mid;mid=(l+r)>>1; }
    else { l=mid;mid=(l+r)>>1; }
    return f[l].z;
}
int main()
{
    int i,t,ca;
    ll n,ans;
    deal(10000000ll);
    scanf("%d", &t);
    for (ca=1;ca<=t;ca++) {
        scanf("%lld", &n);
        printf("Case %d: %lld\n", ca, (getans(n)+MOD)%MOD);
    }
    return 0;
}
