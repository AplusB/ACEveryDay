#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

template<typename T>inline void gn(T &x){
	x=0;T f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
template<typename T>inline void gt(T x){
	if(!x)return;
	gt(x/10);putchar(x%10+'0');
}

int t,n,m,num,cnt,ans=1e9+7;
int MOD=1e9+7;
int ff[100011],vis[333];
char a[100011],le[333];

int main()
{
//	FIN;FOUT;
	int i,j,k,l,r;
	gn(n);
	scanf("%s",a+1);a[n+1]='.';
	repu(i,1,n){
		if(!le[a[i]])cnt++,le[a[i]]=1;
	}
	i=j=1;num=0;
	repu(i,1,n){
		if(!vis[a[i]])num++;
		vis[a[i]]++;
		if(num==cnt)break;
	}
	ans=min(ans,i);l=i+1;
	repu(i,1,n){
		vis[a[i]]--;
		if(!vis[a[i]])num--;
		while(num<cnt){
			if(l>n)break;
			if(!vis[a[l]])num++;
			vis[a[l]]++;
			l++;
		}
		if(num==cnt)ans=min(ans,l-i-1);
	}
	printf("%d\n",ans);
	return 0;
}
