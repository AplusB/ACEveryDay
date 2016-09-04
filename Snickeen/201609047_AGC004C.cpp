#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define repc(i,a,b,c) for(i=a;i<b;i+=c)
#define repcu(i,a,b,c) for(i=a;i<=b;i+=c)
#define repcd(i,a,b,c) for(i=a;i>=b;i-=c)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define MST(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define VI vector<int>
#define VL vector<long long>
#define VII vector<PII>
#define VLL vector<PLL>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front

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

const LL maxn=500+10;
struct NODE{
	db o,r,d;
};
LL t,n,m,ans;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;
char  f[maxn][maxn],a[maxn][maxn],b[maxn][maxn];

int main()
{
//	FOUT;//FIN;
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u=0,v=0,d;
	cin>>n>>m;
	repu(i,1,n){
		cin>>f[i];
		strcpy(a[i],f[i]);
		if(i&1){
			rep(j,0,m-1)a[i][j]='#';
		}
		else {
			rep(j,1,m)f[i][j]='#';
		}
	}
	repu(i,2,n-1)a[i][0]=f[i][m-1]='#';
	repu(i,1,n)cout<<a[i]<<endl;
	cout<<endl;
	repu(i,1,n)cout<<f[i]<<endl;
	
	return 0;
}
