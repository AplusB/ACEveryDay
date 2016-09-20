#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long LL;

const LL MAXN=1e5+10;
LL t,n,m,ans,cnt,tmp,tot;
LL f[MAXN];
struct NODE{
	LL x,num;
}v[MAXN*2];

bool cmp(NODE a,NODE b){
	return (a.x<b.x)||(a.x==b.x&&a.num<b.num);
}

int main()
{
	LL i,j,k,l,r,x,y;
	scanf("%I64d%I64d",&n,&m);
	for(i=1;i<=m;i++)scanf("%I64d",&f[i]);
	for(i=2;i<=m;i++){
		if(f[i]!=f[i-1]){
			v[tot].x=f[i];
			v[tot++].num=f[i-1];
			v[tot].x=f[i-1];
			v[tot++].num=f[i];
			ans+=abs(f[i]-f[i-1]);
		}
	}
	if(ans==0)return 0*puts("0");
	
	sort(v,v+tot,cmp);
	v[tot].x=1e9;
	for(i=j=0;i<tot;i=j){
		while(v[j].x==v[i].x&&j<=tot)j++;
		k=i+(j-i)/2;
		t=v[k].x;k=v[k].num;
		LL tmpt=0,tmpk=0;
		for(l=i;l<j;l++){
			tmpt+=abs(t-v[l].num);
			tmpk+=abs(k-v[l].num);
		}
		if(tmpk<tmpt){
//			cnt=max(cnt,tmpt-tmpk);
			/***************/
			if((tmp=tmpt-tmpk)>cnt){
				cnt=tmp;
				x=t;
				y=k;
			}
			/****************/
		}
	}
//	cout<<x<<" "<<y<<" "<<cnt<<endl;//you can change x to y 
	ans=max(0ll,ans-cnt);
	printf("%I64d\n",ans);
	return 0;
}
