/*
    学习了人生第一道线段树
*/
//#include<bits/stdc++.h>

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<algorithm> 
#include<stdlib.h>
#include<math.h> 
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define db double
#define ld long double
#define FIN  freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

template<typename T> inline void in(T &x){
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

const int N=50005;
struct NODE{
	int l,r,num;
};NODE tree[N*4];
int num[N];
LL MOD=1e9+7;
int x=0;

void build(int root,int l, int r){
//    int y=0;printf("%d %d %d %d %d\n",y++,x++,root,l,r);
	tree[root].l=l;
	tree[root].r=r;
	if(tree[root].l==tree[root].r){
		tree[root].num=num[l];
		return ;
	}
	int mid=(r+l)/2;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	tree[root].num=tree[root<<1].num+tree[root<<1|1].num;
}

int query(int root,int l,int r){
	if(l<=tree[root].l&&r>=tree[root].r) return tree[root].num;
	int mid=tree[root].l+(tree[root].r-tree[root].l)/2,res=0;
	if(l<=mid)res+=query(root<<1,l,r);
	if(r>mid)res+=query(root<<1|1,l,r);
	return res;
}

void update(int root,int p,int v){
	if(tree[root].l==tree[root].r){
		tree[root].num=v;return ;
	}
	int mid=tree[root].l+(tree[root].r-tree[root].l)/2;
	if(p<=mid)update(root<<1,p,v);
	else update(root<<1|1,p,v);
	tree[root].num=tree[root<<1].num+tree[root<<1|1].num;
}

int main(){
//	FIN;FOUT;
    int ca,cas=1,n,Q,a,b,i;char str[11];
	scanf("%d",&ca);
	while(ca--){
		scanf("%d",&n);
		repu(i,1,n)scanf("%d",&num[i]);
		build(1,1,n);
		printf("Case %d:\n",cas++);
		while(scanf("%s",&str),strcmp(str,"End")){
			scanf("%d%d",&a,&b);
			if(strcmp(str,"Query")==0){
				if(a>b)swap(a,b);
				printf("%d\n",query(1,a,b));
			}
			else if(strcmp(str,"Add")==0){
				num[a]+=b;
				update(1,a,num[a]);
			}
			else if(strcmp(str,"Sub")==0){
				num[a]-=b;
				update(1,a,num[a]);
			}
		}
	}
	return 0;
}
