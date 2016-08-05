#include<bits/stdc++.h>
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
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
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

struct TT{
	LL a,b,c,t;
}tt,ss;
LL t,n,m,ans,res;
LL MOD=1e9+7;
char maze[2][22][22];
LL px,py,pz,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
queue<TT> q;

int bfs(){
	LL i,j,k,l;
	while(!q.empty())q.pop();
	tt.a=0,tt.b=0,tt.c=0;tt.t=1;
	q.push(tt);
	while(!q.empty()){
		ss=q.front();q.pop();
		if(ss.a==px&&ss.b==py&&ss.c==pz)return 1;
		for(i=0;i<4;i++){
			tt.a=ss.a+dx[i];
			tt.b=ss.b+dy[i];
			tt.c=ss.c;
			tt.t=ss.t+1;
			if(tt.a<0||tt.a>=n||tt.b<0||tt.b>=m||tt.t>t+1)continue;
			if(maze[tt.c][tt.a][tt.b]=='#'){
				maze[tt.c][tt.a][tt.b]='*';
				tt.c^=1;
			}
			if(maze[tt.c][tt.a][tt.b]=='.'||maze[tt.c][tt.a][tt.b]=='P'){
				maze[tt.c][tt.a][tt.b]='*';
				q.push(tt);
			}
		}
	}
	return 0;
}

int main()
{
	LL ca,i,j,k,l;
	scanf("%d",&ca);
	while(ca--){
		CC(maze);
		scanf("%d%d%d",&n,&m,&t);
		repu(k,0,1)rep(i,0,n){
			scanf("%s",maze[k][i]);
			rep(j,0,m)if(maze[k][i][j]=='P')px=i,py=j,pz=k;
		}
		puts(bfs()?"YES":"NO");
	}
	return 0;
}

