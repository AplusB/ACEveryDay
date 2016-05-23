#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long LL;

const int N=1e5+5;
int n,a[N];
LL dp[N];

struct Tree
{
    int l,r,ans;
}tr[4*N];

void pushup(int root)
{
    if(a[tr[2*root].ans]>a[tr[2*root+1].ans])
        tr[root].ans=tr[2*root].ans;
    else tr[root].ans=tr[2*root+1].ans;
}

void build(int root,int L,int R)
{
    tr[root].l=L;
    tr[root].r=R;
    if(L==R)
    {
        tr[root].ans=L;
        return ;
    }
    int mid=(L+R)>>1;
    build(2*root,L,mid);
    build(2*root+1,mid+1,R);
    pushup(root);
}

int query(int root,int L,int R)
{
    if(L<=tr[root].l&&R>=tr[root].r)return tr[root].ans;
    int mid=(tr[root].l+tr[root].r)>>1;
    if(R<=mid)return query(2*root,L,R);
    else if(L>mid)return query(2*root+1,L,R);
    else
    {
        int fl=query(2*root,L,mid),fr=query(2*root+1,mid+1,R);
        if(a[fl]>a[fr])return fl;
        else return fr;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    LL ans=0;
    
    a[n]=n-1;
    dp[n]=0;
    for(int i=n-1;i>0;i--)
    {
        int temp=query(1,i+1,a[i]);
        dp[i]=dp[temp]+(LL)(n-i-(a[i]-temp));
        ans+=dp[i];
    }
    
    cout<<ans<<endl;
    
    return 0;
}