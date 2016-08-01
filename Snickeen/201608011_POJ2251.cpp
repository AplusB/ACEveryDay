#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
#define CC(a) memset(a,0,sizeof(a))

struct TT{
	int a,b,c;
};TT tt,ss;
int t,n,m,ans,L,R,C;
int dx[]={0,0,1,-1,0,0},
	dy[]={1,-1,0,0,0,0},
	dz[]={0,0,0,0,1,-1},
	sx,sy,sz,ex,ey,ez;
int vis[33][33][33];
char maze[33][33][33];
queue<TT> q;

void bfs(){
	while(!q.empty())q.pop();
	int i,j,k,l,res;
	tt.a=sz;tt.b=sx;tt.c=sy;
	vis[tt.a][tt.b][tt.c]=1;
	q.push(tt);
	while(!q.empty()){
		ss=q.front();q.pop();
		if(ss.a==ez&&ss.b==ex&&ss.c==ey)break;
		for(i=0;i<6;i++){
			tt.a=ss.a+dz[i];
			tt.b=ss.b+dx[i];
			tt.c=ss.c+dy[i];
			if(tt.a<0||tt.a>=L||tt.b<0||tt.b>=R||tt.c<0||tt.c>=C)continue;
			if(maze[tt.a][tt.b][tt.c]!='#' && !vis[tt.a][tt.b][tt.c]){
				q.push(tt);
				vis[tt.a][tt.b][tt.c]=vis[ss.a][ss.b][ss.c]+1;
			}
		}
	}
}

int main()
{
	int i,j,k,l,tmp,cnt;
	while(scanf("%d%d%d",&L,&R,&C)&&L+R+C){
		CC(maze);CC(vis);
		for(i=0;i<L;i++){
			for(j=0;j<R;j++){
				scanf("%s",maze[i][j]);
				for(k=0;k<C;k++){
					if(maze[i][j][k]=='S'){sx=j;sy=k;sz=i;}
					if(maze[i][j][k]=='E'){ex=j;ey=k;ez=i;}
				}
			}
		}
		bfs();
		if(k=vis[ez][ex][ey]){printf("Escaped in %d minute(s).\n",k-1);}
		else puts("Trapped!");
	}
	return 0;
}
