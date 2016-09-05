#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<complex>
using namespace std;
typedef long long LL;
typedef double db;
#define repu(i,a,b) for(i=a;i<=b;i++)
const int maxn = 2000+10;
LL t,n,m,ans,cnt[maxn];
struct NODE{
	LL a,b;
}f[maxn];

LL cmp(NODE a,NODE b){
	return a.a<b.a;
}

int main()
{
	LL i,j,k,l,r;
	cin>>n;
	repu(i,1,n)cin>>f[i].a,f[i].b=i;
	sort(f+1,f+n+1,cmp);
	repu(i,2,n){
		if(f[i].a==f[i-1].a){
			cnt[++cnt[0]]=i;
		}
	}
	if(cnt[0]<2)return 0*puts("NO");
	puts("YES");
	repu(i,1,n)cout<<f[i].b<<" ";cout<<endl;
	swap(f[cnt[1]],f[cnt[1]-1]);
	repu(i,1,n)cout<<f[i].b<<" ";cout<<endl;
	swap(f[cnt[1]],f[cnt[1]-1]);swap(f[cnt[2]],f[cnt[2]-1]);
	repu(i,1,n)cout<<f[i].b<<" ";cout<<endl;
	return 0;
}
