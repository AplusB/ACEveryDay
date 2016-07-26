#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
#define eps 1e-8
using namespace std;
struct node
{
    int l,r,i;
}a[100100];
int n,q,dp[100100][20],sta[100100],z;
ll sl[100100],sr[100100],ans[100100],s[100100];
bool cmp(node a,node b)
{
    if(a.l/z==b.l/z) return a.r<b.r;
    return a.l/z<b.l/z;
}
void rmq_init()
{
    for(int i=1; i<=n; i++) dp[i][0]=i;
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
             dp[i][j]=s[dp[i][j-1]]<s[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
}
int rmq(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return s[dp[L][k]]<s[dp[R-(1<<k)+1][k]]?dp[L][k]:dp[R-(1<<k)+1][k];
}
void init()
{
    z=sqrt(n);
    sort(a,a+q,cmp);
    rmq_init();
    int top=0;sta[0]=0;sl[0]=0;
    for(int i=1;i<=n;i++)
    {
        while(top&&s[sta[top]]>=s[i]) top--;sta[++top]=i;
        sl[i]=sl[sta[top-1]]+(i-sta[top-1])*s[i];
    }
    top=0;sta[0]=n+1,sr[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        while(top&&s[sta[top]]>s[i]) top--;sta[++top]=i;
        sr[i]=sr[sta[top-1]]+(sta[top-1]-i)*s[i];
    }
}
ll call(int l,int r)
{
     int x=rmq(l,r);
     return s[x]*(r-x+1)+sr[l]-sr[x];
}
 ll calr(int l,int r)
 {
     int x=rmq(l,r);
     return s[x]*(x-l+1)+sl[r]-sl[x];
 }
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
    for(int i=0;i<q;i++) scanf("%d%d",&a[i].l,&a[i].r),a[i].i=i;
    init();
    int l=1,r=0,x;
    ll sum=0;
    for(int i=0;i<q;i++)
    {
        int L=a[i].l,R=a[i].r;
        while(r>R)
        {
            x=rmq(l,r);
            sum=sum-(s[x]*(x-l+1)+sl[r]-sl[x]);
            r--;
        }
        while(r<R)
        {
            r++;
            x=rmq(l,r);
            sum=sum+s[x]*(x-l+1)+sl[r]-sl[x];
        }
        while(l>L)
        {
            l--;
            x=rmq(l,r);
            sum=sum+s[x]*(r-x+1)+sr[l]-sr[x];
        }
        while(l<L)
        {
            x=rmq(l,r);
            sum=sum-(s[x]*(r-x+1)+sr[l]-sr[x]);
            l++;
        }
        ans[a[i].i]=sum;
    }
    for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
    return 0;
}
