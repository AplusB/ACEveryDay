#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef int LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define repc(i,a,b,c) for(i=a;i<b;i+=c)
#define repcu(i,a,b,c) for(i=a;i<=b;i+=c)
#define repcd(i,a,b,c) for(i=a;i>=b;i-=c)
#define FIN freopen("d.in","r",stdin)
#define FOUT freopen("d.out","w",stdout)
#define mst(a) memset(a,0,sizeof(a))
#define mstb(a,b) memset(a,b,sizeof(a))
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

const LL N=1005;
const LL M=100005;
struct NODE{
	LL type,x,y;
}node[M];
LL t,n,m,q,ans[M],cnt;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;
char f[N][N];
VI son[M];

void dfs(LL u){
	LL i,j,k,l,flag=0;
	if(node[u].type==1&& !f[node[u].x][node[u].y]){
		flag=1;cnt++;
		f[node[u].x][node[u].y]^=1;
	}
	else if(node[u].type==2&& f[node[u].x][node[u].y]){
		flag=2;cnt--;
		f[node[u].x][node[u].y]^=1;
	}
	else if(node[u].type==3){
		flag=3;
		for(i=1;i<=m;i++){
			if(f[node[u].x][i])cnt--;
			else cnt++;
			f[node[u].x][i]^=1;
		}
	}
	ans[u]=cnt;
	l=son[u].size();
	for(i=0;i<l;i++)dfs(son[u][i]);
	if(flag==1){
		cnt--;f[node[u].x][node[u].y]^=1;
	}
	else if(flag==2){
		cnt++;f[node[u].x][node[u].y]^=1;
	}
	else if(flag==3){
		for(i=1;i<=m;i++){
			if(f[node[u].x][i])cnt--;
			else cnt++;
			f[node[u].x][i]^=1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,ca=0,u,v,d;
	cin>>n>>m>>q;
	for(i=1;i<=q;i++){
		cin>>node[i].type>>node[i].x;
		if(node[i].type<=2)cin>>node[i].y;
		if(node[i].type==4)son[node[i].x].pb(i);
		else son[i-1].pb(i);
	}
	dfs(0);
	for(i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}
