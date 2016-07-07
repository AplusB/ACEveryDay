#include<iostream>
#include<queue>
#include<string.h>
#include<stdio.h>
using namespace std;

int ll,cc,rr;
char mp[40][40][40];
int vis[40][40][40];
int al[6]={0,0,0,0,1,-1};
int ac[6]={0,0,1,-1,0,0};
int ar[6]={1,-1,0,0,0,0};
int ans;
int sl,sc,sr;

struct node{
	int l,c,r;
	int st;
}temp,t;

void bfs()
{
	queue<node>q;
	temp.l=sl;
	temp.c=sc;
	temp.r=sr;
	vis[sl][sc][sr]=1;
	temp.st=0;
	q.push(temp);

	while(!q.empty())
	{
		temp=q.front();
		q.pop();

		for(int i=0;i<6;i++)
		{
			int l2=temp.l+al[i];
			int c2=temp.c+ac[i];
			int r2=temp.r+ar[i];
			if(l2>=0&&l2<ll&&c2>=0&&c2<cc&&r2>=0&&r2<rr)
			{
				if(mp[l2][c2][r2]=='E')
				{
					ans=temp.st+1;
					return ;
				}
				if( mp[l2][c2][r2]=='.' && vis[l2][c2][r2]==0)
				{
					vis[l2][c2][r2]=1;
					t.l=l2;
					t.c=c2;
					t.r=r2;
					t.st=temp.st+1;
					q.push(t);
				}
			}
		}
	}
}

int main()
{
	int t;
	while(cin>>ll>>cc>>rr,(ll+cc+rr))
	{
		ans=-1;

		for(int i=0;i<ll;i++)
		{
			for(int j=0;j<cc;j++)
			{
				for(int k=0;k<rr;k++)
				{
					cin>>mp[i][j][k];
					if(mp[i][j][k]=='S')
					{
						sl=i;
						sc=j;
						sr=k;
						vis[i][j][k]=1;
					}
					if(mp[i][j][k]=='#')
					{
						vis[i][j][k]=1;
					}
				}
			}
			getchar();
		}

		memset(vis,0,sizeof(vis));
		bfs();
		if(ans==-1)
			cout<<"Trapped!"<<endl;
		else
			printf("Escaped in %d minute(s).\n",ans);
	}
	return 0;
}
