#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=500+60;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

int go[maxn][2*maxn];
vector<pair<int,int> >aha[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<maxn;i++) aha[i].clear();
		int row,col;
		if(n%2==1)
		{
			row=(n+1)/2,col=(n+1)/2+(n-1)/2;
			printf("%d %d\n",row,col);
			int now=1;
			for(int i=n;i>=1;i-=2)
			{
				for(int j=now+i/2;j>=now;j--)
					aha[i].push_back(make_pair(now,j));
				for(int j=now+1;j<=row;j++)
					aha[i].push_back(make_pair(j,now));
				now+=1;
			}
			int x=1,y=(n+1)/2+1;
			int bb=1; // 1-row 0-col
			for(int i=n-1;i>=4;i-=2)
			{
				if(bb==1)
				{
					for(int j=y;j<=col;j++)
						aha[i].push_back(make_pair(x,j));
					for(int j=col;j>=y;j--)
						aha[i].push_back(make_pair(x+1,j));
					x+=2;
				}
				else
				{
					for(int j=x;j<=row;j++)
						aha[i].push_back(make_pair(j,y));
					for(int j=row;j>=x;j--)
						aha[i].push_back(make_pair(j,y+1));
					y+=2;
				}
				bb=!bb;
			}
			if(x==row)
			{
				aha[2].push_back(make_pair(x,y));
				aha[2].push_back(make_pair(x,y+1));
			}
			else
			{
				aha[2].push_back(make_pair(x,y));
				aha[2].push_back(make_pair(x+1,y));
			}
		}
		else
		{
			row=n/2,col=n/2+2+(n-2)/2;
			printf("%d %d\n",row,col);
			int now=1;
			for(int i=n-1;i>=1;i-=2)
			{
				for(int j=now+i/2;j>=now;j--)
					aha[i].push_back(make_pair(now,j));
				for(int j=now+1;j<=row;j++)
					aha[i].push_back(make_pair(j,now));
				now+=1;
			}
			int x=1,y=n/2+1;
			int bb=0; // 0-col 1-row
			for(int i=n;i>=4;i-=2)
			{
				if(bb==0)
				{
					for(int j=x;j<=row;j++)
						aha[i].push_back(make_pair(j,y));
					for(int j=row;j>=x;j--)
						aha[i].push_back(make_pair(j,y+1));
					y+=2;
				}
				else
				{
					for(int j=y;j<=col;j++)
						aha[i].push_back(make_pair(x,j));
					for(int j=col;j>=y;j--)
						aha[i].push_back(make_pair(x+1,j));
					x+=2;
				}
				bb=!bb;
			}
			if(x==row)
			{
				aha[2].push_back(make_pair(x,y));
				aha[2].push_back(make_pair(x,y+1));
			}
			else
			{
				aha[2].push_back(make_pair(x,y));
				aha[2].push_back(make_pair(x+1,y));
			}
		}
		for(int i=1;i<=n;i++)
		{
			int len=aha[i].size();
			for(int j=0;j<len;j++)
			{
				if(j!=0) printf(" ");
				printf("%d %d",aha[i][j].first,aha[i][j].second);
			}
			printf("\n");
		}
	}
	return 0;
}



