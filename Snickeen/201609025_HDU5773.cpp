#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef int LL;

const int maxn = 100000+10;
LL t,n,m,ans,f[maxn],num[maxn];

LL bs(LL x[],LL len,LL key){
	LL mid,l=1,r=len;
	while(l<=r){
		mid=l+(r-l)/2;
		if(x[mid]==key)return mid;
		else if(x[mid]>key)r=mid-1;
		else l=mid+1;
	}
	return l;
}

LL solve(LL x){
	LL i,j,k,l,res;
	num[1]=f[x];l=1;
	for(i=x+1;i<=n;i++){
		if(f[i]>num[l]){
			num[++l]=f[i];
		}
		else if(f[i]==0){
			for(j=l;j;j--){
				num[j+1]=num[j]+1;
			}
			l++;num[1]=0;
		}
		else {
			k=bs(num,l,f[i]);
			num[k]=f[i];
		}
	}
	return l;
}

int main()
{
	LL i,j,k,l,ca=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);k=0;
		for(i=1;i<=n;i++){
			scanf("%d",&f[i]);
		}
		ans=solve(1);
		printf("Case #%d: %d\n",++ca,ans);
	}
	return 0;
}
