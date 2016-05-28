/*
    学习线段树的区间更新和区间查询
*/
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef __int64 LL;

const int N=100005;

struct NODE{
	LL l,r,sum,mark;
}; NODE tt[N*4];
LL num[N],t,n,m,q,i,j,a,b,c;
char s[2];

void build(LL ro,LL l,LL r){
	tt[ro].l=l;tt[ro].r=r;
	tt[ro].mark=0;
	if(l==r){
		tt[ro].sum=num[l];
		return ;
	}
	LL mid=(l+r)/2;
	build(ro<<1,l,mid);
	build(ro<<1|1,(mid+1),r);
	tt[ro].sum=tt[ro<<1].sum+tt[ro<<1|1].sum;
}

void update(LL ro,LL l,LL r,LL v){
	if(tt[ro].l==l&&tt[ro].r==r){
		tt[ro].mark+=v;
		return ;
	}
	tt[ro].sum+=v*(r-l+1);
	if(tt[ro<<1].r>=r)update(ro<<1,l,r,v);
	else if(tt[ro<<1|1].l<=l)update(ro<<1|1,l,r,v);
	else {
		update(ro<<1,l,tt[ro<<1].r,v);
		update(ro<<1|1,tt[ro<<1|1].l,r,v);
	}
}

LL query(LL ro,LL l,LL r){
	if(tt[ro].l==l&&tt[ro].r==r)return tt[ro].sum+tt[ro].mark*(r-l+1);
	if(tt[ro].mark!=0){
		tt[ro<<1].mark+=tt[ro].mark;
		tt[ro<<1|1].mark+=tt[ro].mark;
		tt[ro].sum+=(tt[ro].r-tt[ro].l+1)*tt[ro].mark;
		tt[ro].mark=0;
	}
	LL mid=(tt[ro].l+tt[ro].r)/2,res=0LL;
	if(r<=mid)res+=query(ro<<1,l,r);
	else if(l>mid)res+=query(ro<<1|1,l,r);
	else {
		res+=query(ro<<1,l,mid);
		res+=query(ro<<1|1,mid+1,r);
	}
	return res;
}

int main()
{
	while(~scanf("%lld%lld",&n,&q)){
		for(i=1;i<=n;i++)scanf("%lld",&num[i]);
		build(1,1,n);
		while(q--){
			scanf("%s",s);
			if(s[0]=='Q'){
				scanf("%lld%lld",&a,&b);
				printf("%lld\n",query(1,a,b));
			}
			if(s[0]=='C'){
				scanf("%lld%lld%lld",&a,&b,&c);
				update(1,a,b,c);
			}
		}
	}
	return 0;
}
