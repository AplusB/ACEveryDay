#include<bits/stdc++.h>
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
#define FIN freopen("c.in","r",stdin)
#define FOUT freopen("c.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector<int>
#define VII vector<PII>
#define VLL vector<PLL>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second

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

const int N=300005;
struct TT{
	LL a,w,left;
}v[300005];
LL t,n,m,ans,cnt,now;
LL MOD=1e9+7;
LL vis[300005],f[300005];

int main()
{
//	FIN;FOUT;
	LL i,j,k,x,y,res;
	gn(n);gn(m);
	while(m--){
		gn(x);gn(y);
		if(x==1){
			v[++cnt].a=y;
			v[cnt].w=1;
			v[cnt].left=f[y];
			f[y]=cnt;
			vis[y]++;
			ans++;
		}
		else if(x==2){
			ans-=vis[y];
//			vis[y]=0;
			k=f[y];
			while(k>0&&vis[y]){
				v[k].w=0;
				k=v[k].left;
				vis[y]--;
			}
		}
		else if(x==3){
			if(y>now){
				for(i=now+1;i<=y&&i<=cnt;i++){
					if(v[i].w){
						v[i].w=0;
						vis[v[i].a]--;
						ans--;
					}
				}
				now=y;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
