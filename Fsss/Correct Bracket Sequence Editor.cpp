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
const int N=500010;
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
int d[N],p[N],w[N],pre[N],sub[N];
char s[N],c[N];
int main()
{
    int i,n,m,q,l,r,k=0;
    scanf("%d%d%d", &n, &m, &q);
    scanf("%s", s);
    scanf("%s", c);
    for (i=n;i;i--)
    if (s[i-1]==')') { p[i]=p[i+1]+1;d[++k]=i; }
    else { p[i]=p[i+1]-1;w[i]=d[k];k--; }
    for (i=1;i<=n;i++) w[w[i]]=i;
    for (i=0;i<=n+1;i++) pre[i]=i-1,sub[i]=i+1;
    for (i=0;i<m;i++)
    if (c[i]=='L') {
        if (pre[q]!=0) q=pre[q];
    } else if (c[i]=='R') {
            if (sub[q]!=n+1) q=sub[q];
        } else {
            if (q==0) continue ;
            l=min(q,w[q]);r=max(q,w[q]);
            if (sub[r]!=n+1) q=sub[r];
            else q=pre[l];
            sub[pre[l]]=sub[r];pre[sub[r]]=pre[l];
        }
    k=sub[0];
    while (k<=n) {
        printf("%c", s[k-1]);k=sub[k];
    }
    printf("\n");
    return 0;
}
