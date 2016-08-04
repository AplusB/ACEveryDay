/* ***********************************************
Author        :guanjun
Created Time  :2016/8/1 10:11:01
File Name     :hdu4747.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 200010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
bool cmp(int a,int b){
    return a>b;
}
struct node{
    int l,r;
    ll sum,mx;
    ll c;
}nod[maxn*4];
void push_up(int i){
    nod[i].sum=nod[i<<1].sum+nod[i<<1|1].sum;
	nod[i].mx=max(nod[i<<1].mx,nod[i<<1|1].mx);
}
void push_down(int i){
    if(nod[i].c!=-1){
        nod[i<<1].c=nod[i<<1|1].c=nod[i].c;
        nod[i<<1].sum=(ll)(nod[i<<1].r-nod[i<<1].l+1)*nod[i].c;
        nod[i<<1|1].sum=(ll)(nod[i<<1|1].r-nod[i<<1|1].l+1)*nod[i].c;
		//这里不能用 +=啊!
		nod[i<<1].mx=nod[i<<1|1].mx=nod[i].c;

        nod[i].c=-1;
    }
}
void build(int i,int l,int r){
    nod[i].l=l;
    nod[i].r=r;
    nod[i].c=-1;
    if(l==r){
        return ;
    }
    int mid=(l+r)/2;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
}
void update(int i,int l,int r,ll w){
    if(nod[i].l==l&&nod[i].r==r){
		nod[i].mx=nod[i].c=w;
		nod[i].sum=(r-l+1)*w;//注意
        return ;
    }
    if(nod[i].l==nod[i].r)return ;
    push_down(i);
    int mid=(nod[i].l+nod[i].r)/2;
    if(r<=mid)update(i<<1,l,r,w);
    else if(mid<l) update(i<<1|1,l,r,w);
    else{
        update(i<<1,l,mid,w);
        update(i<<1|1,mid+1,r,w);
    }
    push_up(i);
}
ll quary(int i,int l,int r){
    if(nod[i].l==l&&nod[i].r==r){
        return nod[i].sum;
    }
    push_down(i);
    int mid=(nod[i].l+nod[i].r)/2;
    ll ans=0;
    if(r<=mid)ans+=quary(i<<1,l,r);
    else if(l>mid)ans+=quary(i<<1|1,l,r);
    else {
        ans+=quary(i<<1,l,mid);
        ans+=quary(i<<1|1,mid+1,r);
    }
    push_up(i);
    return ans;
}
int up_bound(int i,int w){
	if(nod[i].l==nod[i].r){
		if(nod[i].mx<w)return -1;
		return nod[i].l;
	}
	push_down(i);
	if(w<nod[i<<1].mx)return up_bound(i<<1,w);
	else return up_bound(i<<1|1,w);
}
int n,a[maxn],d[maxn],Next[maxn];
bool vis[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int mex;
	ll ans;
	while(cin>>n&&n){
		cle(vis);
		mex=ans=0;
		build(1,1,n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]=a[i]>n?n+1:a[i];
			vis[a[i]]=true;
			if(a[i]==mex){
				for(int j=mex+1;i<=n;j++)if(!vis[j]){
					mex=j;break;
				}
			}
			update(1,i,i,mex);
			ans+=mex;
		}
		memset(d,-1,sizeof d);
		for(int i=n;i>=1;i--){
			if(d[a[i]]==-1)Next[i]=n+1;
			else Next[i]=d[a[i]];
			d[a[i]]=i;
		}
		for(int i=2;i<=n;i++){
			int l=up_bound(1,a[i-1]);
		//	cout<<"l "<<l<<endl;
			if(l!=-1)update(1,l,Next[i-1]-1,a[i-1]);
			ans+=quary(1,i,n);
		}
		printf("%I64d\n",ans);  
	}
    return 0;
}
