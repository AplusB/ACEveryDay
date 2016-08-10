/*
    //18476kb	1123ms 
    思路：bfs+cantor  预处理9种位置的情况   O(1)查询 
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef int LL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define FIN freopen("HDU3567.in","r",stdin)
#define FOUT freopen("HDU3567.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

const int N=363000;//362880
struct TT{
	LL num,pos,cantor;
}rr,ss,tt;
LL t,n,m,ans,aim;
LL MOD=1e9+7;
LL dx[11],fac[11],from[10][N],step[10][N];
char vis[11],df[10][N],fans[N],ma[5]={'u','r','l','d'};
LL dr[11][6]={{0},
	{0,2,0,4},{0,3,1,5},{0,0,2,6},
	{1,5,0,7},{2,6,4,8},{3,0,5,9},
	{4,8,0,0},{5,9,7,0},{6,0,8,0}};
queue<TT> q;

LL cantor(LL x){
	CC(vis);
	LL i,j,k,l,res,tmp,cnt=0;
	for(i=1;i<9;i++){
		k=x/dx[i]%10;
		vis[k]=1;
		tmp=0;
		for(j=0;j<k;j++)if(!vis[j])tmp++;
		cnt+=tmp*fac[i]; 
	}
	return cnt+1;
}

void bfs(LL xp){
	LL i,j=0,k,l,res,tmp,cnt,p,s;
	while(!q.empty()){
		ss=q.front();q.pop();
		for(i=3;i>=0;i--){
			if(dr[ss.pos][i]==0)continue;
			k=dr[ss.pos][i];
			tmp=ss.num/dx[k]%10;
			res=ss.num-tmp*dx[k]+tmp*dx[ss.pos];
			p=cantor(res);
			if(from[xp][p])continue;
			from[xp][p]=ss.cantor;df[xp][p]=ma[i];step[xp][p]==step[xp][ss.cantor]+1;
			tt.num=res;tt.pos=k;tt.cantor=p;
			q.push(tt);
		}
	}
}

void pre(){
	LL i,j,k,l,res,p,x,a[11]={0};
	repu(i,1,9)a[i]=i-1;
	repu(i,1,9){
		swap(a[i],a[i-1]);
		res=0;
		repu(j,1,9)res=res*10+a[j];
		aim=cantor(res);p=aim;
		from[i][p]=-1;
		tt.num=res;tt.pos=i;tt.cantor=p;
		q.push(tt);
		bfs(i);
	}
}

int main()
{
//	FIN;FOUT;
	LL ca=0,i,j,k,l,res,p;
	fac[8]=1;repd(i,7,1)fac[i]=fac[i+1]*(9-i);
	dx[9]=1;repd(i,8,0)dx[i]=dx[i+1]*10;
	pre();
	scanf("%d",&t);
	while(t--){
		char a[22],b[22];int c[22];
		CC(fans);
		scanf("%s%s",a,b);
		res=0;ans=0;k=1;
		rep(i,0,9){
			if(a[i]=='X')c[0]=0,l=i+1;
			else c[a[i]-'0']=k++;
		}
		rep(i,0,9){
			if(b[i]=='X')ans=ans*10;
			else ans=ans*10+c[b[i]-'0'];
		}
		p=cantor(ans);
		j=0;k=p;
		while(from[l][k]&&from[l][k]!=-1){
			fans[j++]=df[l][k],k=from[l][k];
		}
		printf("Case %d: %d\n%s\n",++ca,j,strrev(fans));
	}
	return 0;
}
