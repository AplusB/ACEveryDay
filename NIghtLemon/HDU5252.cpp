#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct A{
	ll x,y,z;
}a[50007];
int n;

int check(ll dis){
	ll x1,y1,x2,y2;
	x1=y1=-10000000000LL;
	x2=y2=-x1;
	for(int i=0;i<n;i++){
		ll t =0;
		if(i) t=a[i].z-a[i-1].z;
		t<<=1;
		x1 -=t;y1 -=t;
		x2 +=t;y2 +=t;
		ll t1 = (a[i].y-a[i].x)<<1;
		ll t2 = (a[i].y+a[i].x)<<1;
		x1 = max(x1,t1 -dis);
		y1 = max(y1,t2 -dis);
		x2 = min(x2,t1 +dis);
		y2 = min(y2,t2 +dis);
		if(x1 >x2 || y1> y2) return 0;
	}
	return 1;
}

int cmp(A a,A b){
	return a.z<b.z;
}

int main()
{
	int T,NT = 0;
	scanf("%d",&T);
	
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%I64d%I64d%I64d",&a[i].x,&a[i].y,&a[i].z);
		sort(a,a+n,cmp);
		ll l=0ll,r=4000000000ll,m,ans=r;
		while(l<=r){
			m =l+(r-l)/2;
			if(check(m)) { ans = m; r = m - 1; }
			else l = m + 1;
		}
		if(ans%2) printf("Case #%d:\n%I64d/2\n",++NT,ans);
		else  printf("Case #%d:\n%I64d/1\n",++NT,ans/2);
	}
	return 0;
}
