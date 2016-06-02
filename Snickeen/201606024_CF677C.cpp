#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef long long LL;

LL n,m,t,s,r,i,j,k,l,ans,num;
LL ff[111],dd[333];
char a[100005];
char b[111]={
    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_"
};
char c[111];
LL MOD=1e9+7;
map<char,LL > ma;

int main()
{
	t=0;
	for(i=0;i<64;i++)dd[b[i]]=i;
	for(i=0;i<=63;i++){
		dd[b[i]]=i;
		for(j=0;j<=63;j++){
			for(k=0;k<=63;k++){
				if((j&k)==dd[b[i]])ff[i]++;
			}
		}
//		printf("%I64d %I64d\n",i,ff[i]);
	}
	scanf("%s",a);
	l=strlen(a);
	ans=1LL;
	for(i=0;i<l;i++){
		ans=ans*ff[dd[a[i]]]%MOD;
	}
	printf("%I64d\n",ans);
	return 0;
 } 
