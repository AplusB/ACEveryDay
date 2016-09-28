#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+90;
const ll inf=2e13+9;
const ll mod=1e9+7;
const double eps=1e-9;

const int MAXN=100005;
const ll Mod=1000000007;
struct Matrix
{
    ll a[2][2];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=1LL*(i==j);
    }
    Matrix operator + (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                C.a[i][j]=(a[i][j]+B.a[i][j])%Mod;
        return C;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int k=0;k<2;k++)
                for(int j=0;j<2;j++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const ll &t)const
    {
        Matrix A=(*this),res;
        res.init();
        ll p=t;
        while(p)
        {
            if(p&1)res=res*A;
            A=A*A;
            p>>=1;
        }
        return res;
    }
};


ll b[maxn];
Matrix f,v[maxn*4],lazy[4*maxn];

void build(int node,int l,int r);
void push_up(int node);
void push_down(int node,int l,int r);
ll query(int node,int l,int r,int L,int R);
void update(int node,int l,int r,int L,int R,Matrix go);


int main()
{
	f.a[0][0]=1,f.a[0][1]=1;
	f.a[1][0]=1,f.a[1][1]=0;
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",&b[i]);
		build(0,1,n);
		while(m--)
		{
			int op,l,r;
			scanf("%d%d%d",&op,&l,&r);
			if(op==1)
			{
				ll x;
				scanf("%lld",&x);
				update(0,1,n,l,r,f^x);
			}
			else
				printf("%lld\n",query(0,1,n,l,r));
		}
	}
	return 0;
}

void update(int node,int l,int r,int L,int R,Matrix go)
{
	if(L<=l && r<=R)
	{
		v[node]=v[node]*go;
		lazy[node]=lazy[node]*go;
		return ;
	}
	if(R<l || r<L) return ;
	int mid=l+(r-l)/2;
	push_down(node,l,r);
	update(2*node+1,l,mid,L,R,go);
	update(2*node+2,mid+1,r,L,R,go);
	push_up(node);
	return ;
}

ll query(int node,int l,int r,int L,int R)
{
	if(r<L || R<l) return 0;
	if(L<=l && r<=R)
		return v[node].a[0][1];
	int mid=l+(r-l)/2;
	push_down(node,l,r);
	ll ans=0;
	ans+=query(2*node+1,l,mid,L,R);
	ans%=mod;
	ans+=query(2*node+2,mid+1,r,L,R);
	ans%=mod;
	return ans;
}

void push_down(int node,int l,int r)
{
	lazy[2*node+1]=lazy[node]*lazy[2*node+1];
	lazy[2*node+2]=lazy[node]*lazy[2*node+2];
	v[2*node+1]=lazy[node]*v[2*node+1];
	v[2*node+2]=lazy[node]*v[2*node+2];
	lazy[node].init();
}

void push_up(int node)
{
	v[node]=v[2*node+1]+v[2*node+2];
}

void build(int node,int l,int r)
{
	lazy[node].init();
	if(l==r)
	{
		v[node]=f^b[l];
		return ;
	}
	int mid=l+(r-l)/2;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	push_up(node);
	return ;
}
