/* ***********************************************
Author        :guanjun
Created Time  :2015/9/25 9:30:35
File Name     :4.cpp
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
#define maxn 105000
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
struct node{
	int l,r;
	int c;//延迟标记
}nod[maxn*4];
pair<int,int>a[maxn];
int mp[10001000];
int x[maxn*2],vis[maxn*2];
bool cmp(int a,int b){
    return a>b;
}
void push_down(int i){
	if(nod[i].c){
		nod[i<<1].c=nod[i<<1|1].c=nod[i].c;
		nod[i].c=0;
	}
}
void build(int i,int l,int r){
	nod[i].l=l;
	nod[i].r=r;
	nod[i].c=0;
	if(l==r)return ;
	int mid=(l+r)/2;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
}
void update(int i,int l,int r,int w){
	if(nod[i].l==l&&nod[i].r==r){
		nod[i].c=w;
		return ;
	}
	push_down(i);
	int mid=(nod[i].l+nod[i].r)/2;
	if(r<=mid)update(i<<1,l,r,w);
	else if(l>mid)update(i<<1|1,l,r,w);
	else{
		update(i<<1,l,mid,w);
		update(i<<1|1,mid+1,r,w);
	}
}
int quary(int i){
	int num=0;
	if(nod[i].c!=0){
		if(!vis[nod[i].c])vis[nod[i].c]=1,num++;
		//return num;
	}
	if(nod[i].l==nod[i].r)return num;
	num+=quary(i<<1);
	num+=quary(i<<1|1);
}
int ans;
void serch(int i)
{
	if(nod[i].c!=0)
	{
		if(!vis[nod[i].c])
		{
			vis[nod[i].c]=1,ans++;
		}
		return ;
	}
	if(nod[i].r==nod[i].l)return;
	serch(i<<1);
	serch(i<<1|1);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int n,t;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		int j=0;x[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].first,&a[i].second);
			x[++j]=a[i].first;
			x[++j]=a[i].second;
		}
		sort(x+1,x+1+j);
		int tmp=j;
		for(int i=2;i<=j;i++){
			if(x[i]-x[i-1]>1)x[++tmp]=x[i-1]+1;
		}
		sort(x+1,x+1+tmp);
		cle(mp);
		for(int i=1;i<=tmp;i++){
			if(!mp[x[i]])mp[x[i]]=i;
		}
		build(1,1,tmp);
		for(int i=1;i<=n;i++){
			//cout<<mp[a[i].first]<<" "<<mp[a[i].second]<<endl;
			update(1,mp[a[i].first],mp[a[i].second],i);
		}
		cle(vis);
		ans=0;
		serch(1);
		printf("%d\n",ans);
	}
    return 0;
}
