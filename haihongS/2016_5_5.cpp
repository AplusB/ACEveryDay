#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;

struct II
{
    vector<int> aha;
    int lchild,rchild;
}tree[4*maxn];

int n,m;
int num[maxn],bb[maxn];

int build(int node,int l,int r);
int query(int node,int l,int r,int L,int R,int x);

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            bb[i]=num[i];
        }
        sort(bb,bb+n);
        build(0,0,n);

        while(m--)
        {
            int u,v,k;
            scanf("%d%d%d",&u,&v,&k);
            u--,v--;
            int low=0,up=n-1,ans=n-1;
            while(low<=up)
            {
                int mid=low+(up-low)/2;
                int c=query(0,0,n,u,v+1,bb[mid]);
                if(c>=k)
                {
                    up=mid-1;
                    ans=min(ans,mid);
                }
                else
                    low=mid+1;
            }
            printf("%d\n",bb[ans]);
        }
    }
    return 0;
}

// [l,r)
int query(int node,int l,int r,int L,int R,int x)
{
    if(R<=l || L>=r) return 0;
    if(L<=l && r<=R)
    {
        int tmp=upper_bound(tree[node].aha.begin(),tree[node].aha.end(),x)-tree[node].aha.begin();
        return tmp;
    }
    int mid=l+(r-l)/2;
    int t1=query(2*node+1,l,mid,L,R,x);
    int t2=query(2*node+2,mid,r,L,R,x);
    return t1+t2;
}

//  [l,r)
int build(int node,int l,int r)
{
    if(l+1==r)
    {
        //tree[node].aha.clear();
        tree[node].aha.push_back(num[l]);
        return node;
    }
    int mid=l+(r-l)/2;
    tree[node].lchild=build(2*node+1,l,mid);
    tree[node].rchild=build(2*node+2,mid,r);
    int u=tree[node].lchild,v=tree[node].rchild;

    //tree[node].aha.clear();
    tree[node].aha.resize(r-l);
    merge(tree[u].aha.begin(),tree[u].aha.end(),tree[v].aha.begin(),tree[v].aha.end(),tree[node].aha.begin());
    return node;
}
