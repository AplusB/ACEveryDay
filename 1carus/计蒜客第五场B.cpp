#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define endl '\n'
#define min(a,b) (a > b ? b : a)
#define max(a,b) (a > b ? a : b)

using namespace std;

const int MAXN = 1e3 + 5;

struct node{
	int val,index;
}v[MAXN];

int cmp(node a,node b)
{
	return a.val < b.val;
}

int num[MAXN][MAXN],m[MAXN];
int n,q;

int main()
{
	while(scanf("%d",&n) == 1)
	{
		memset(num,0,sizeof(num));
		memset(m,0,sizeof(m));
		
		int i,j;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&m[i]);
			for(j = 0;j < m[i];j++)
			{
				scanf("%d",&num[i][j]);
			}
		}
		
		scanf("%d",&q);
		while(q--)
		{
			int x,y;
			int k1,k2;
			scanf("%d %d %d %d",&x,&k1,&y,&k2);
			x--;y--;
			
			int temp1[MAXN],temp2[MAXN];
			for(i = 0;i < k1;i++)
			{
				temp1[i] = num[x][i];
			}
			
			for(i = 0;i  < k2;i++)
			{
				temp2[i] = num[y][i];
			}
			
			int cur1 = k1,cur2 = k2;
			for(i = k2;i < m[y];i++)
			{
				temp1[cur1++] = num[y][i];
			}
			
			for(i = k1;i < m[x];i++)
			{
				temp2[cur2++] = num[x][i];
			}
			
			m[x] = m[x] - k1 + k2;
			for(i = 0;i < m[x];i++)
			{
				num[x][i] = temp2[i];
			}
			
			m[y] = m[y] - k2 + k1;
			for(i = 0;i < m[y];i++)
			{
				num[y][i] = temp1[i];
			}
			
			//cout << " *" << m[x] << " " << m[y] << endl;
			
			for(i = 0;i < n;i++)
			{
				int j;
				int maxi = 0;
				v[i].index = m[i];
				for(j = 0;j < m[i];j++)
				{
					if(num[i][j] - j> num[i][maxi] - maxi)maxi = j;
				}
				v[i].val = num[i][maxi] - maxi;
				//cout << "***" << maxi << endl;
				//if(m[i] == 0)v[i].val = 0;
				
				//cout << i << " " << m[i] << " " << v[i].val << endl;
			}
			
			sort(v,v + n,cmp);
			
			int i,ans = 0,sum = 0;
			for(i = 0;i < n;i++)
			{
				//cout << v[i].index << " " << v[i].val << endl;
				v[i].val -= sum;
				ans = max(v[i].val,ans);
				sum += v[i].index;
			}
			
	        cout<<ans<<endl;
		}
	}
	return 0;
}
