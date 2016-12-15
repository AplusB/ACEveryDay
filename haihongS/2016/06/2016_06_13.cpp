/* ***********************************************
Author        :shootPlane
Created Time  :2016年06月13日 星期一 09时57分54秒
File Name     :1423.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=30+9;
const int inf=1e9+9;
const double eps=1e-9;

double a[maxn][maxn],x[maxn];//方程的左边的矩阵和等式右边的值，求解之后x存的就是结果
int equ,var;//方程数和未知数个数

int n,m;
int sx,sy;
char mapp[maxn][maxn];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int use[maxn][maxn];
int flag;
int cnt;

struct II
{
	int x,y;
};

int Gauss();
int bfs();

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
			scanf("%s",mapp[i]);

		//init
		memset(use,-1,sizeof(use));
		flag=cnt=0;

		int fs=0;
		for(int i=0;i<n;i++)
		{
			if(fs==1) break;
			for(int j=0;j<m;j++)
			{
				if(mapp[i][j]=='D')
				{
					sx=i,sy=j;fs=1;break;
				}
			}
		}

		bfs();
		if(flag==0)
		{
			printf("tragedy!\n");continue;
		}

		memset(a,0,sizeof(a));
		memset(x,0,sizeof(x));
		equ=var=cnt;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(use[i][j]==-1) continue;
				int index=use[i][j];
				if(mapp[i][j]=='E')
				{
					a[index][index]=1;
					continue;
				}
				int pp=0;
				for(int k=0;k<4;k++)
				{
					int nx=i+dx[k],ny=j+dy[k];
					if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
					if(mapp[nx][ny]=='X') continue;
					pp+=1;
					a[index][use[nx][ny]]=-1;
				}
				a[index][use[i][j]]=pp;
				x[index]=pp;
			}
		}

		if(Gauss())
		{
			double ans=x[use[sx][sy]];
			if(ans>1000000)
				printf("tragedy!\n");
			else
				printf("%.2lf\n",x[use[sx][sy]]);
		}
		else
			printf("tragedy!\n");


	}
    return 0;
}

int bfs()
{
	queue<II> aha;
	while(!aha.empty()) aha.pop();

	II fir;fir.x=sx,fir.y=sy;
	use[sx][sy]=cnt++;
	aha.push(fir);

	while(!aha.empty())
	{
		II tp=aha.front();aha.pop();
		for(int i=0;i<4;i++)
		{
			int nx,ny;
			nx=tp.x+dx[i],ny=tp.y+dy[i];
			if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
			if(use[nx][ny]!=-1) continue;
			if(mapp[nx][ny]=='X') continue;
			if(mapp[nx][ny]=='E') flag=1;
			II next;next.x=nx,next.y=ny;
			use[nx][ny]=cnt++;
			aha.push(next);
		}
	}
	return 0;
}

int Gauss()
{
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
          if(fabs(a[i][col])>fabs(a[max_r][col]))
            max_r=i;
        if(fabs(a[max_r][col])<eps)return 0;
        if(k!=max_r)
        {
            for(j=col;j<var;j++)
              swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1;j<var;j++)a[k][j]/=a[k][col];
        a[k][col]=1;
        for(i=0;i<equ;i++)
          if(i!=k)
          {
              x[i]-=x[k]*a[i][k];
              for(j=col+1;j<var;j++)a[i][j]-=a[k][j]*a[i][col];
              a[i][col]=0;
          }
    }
    return 1;
}
