#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=3e5+9;
const int inf=2e9+9;

struct II
{
	int index,num;
};

queue<int> aha[maxn];
queue<II> go;
int flag[maxn];

int main()
{
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		for(int i=0;i<maxn;i++)
		{
			while(!aha[i].empty()) aha[i].pop();
			flag[i]=0;
		}
		while(!go.empty()) go.pop();
		int cnt=0,ans=0;
		while(q--)
		{
			int op,x;
			scanf("%d%d",&op,&x);
			if(op==1)
			{
				cnt++,ans++;
				aha[x].push(cnt);
				II tmp;
				tmp.index=cnt,tmp.num=x;
				go.push(tmp);
			}
			else if(op==2)
			{
				while(!aha[x].empty())
				{
					int tp=aha[x].front();
					aha[x].pop();
					if(flag[tp]==0)
					{
						flag[tp]=1;
						ans--;
					}
				}
			}
			else
			{
				while(!go.empty())
				{
					II tp=go.front();
					if(tp.index>x) break;
					go.pop();
					if(flag[tp.index]==0)
					{
						flag[tp.index]=1;
						ans--;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
