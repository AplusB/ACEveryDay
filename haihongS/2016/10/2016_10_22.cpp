#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

priority_queue<ll,vector<ll>,greater<ll> > aha;

char op[maxn][30],ans[10*maxn][30];
ll go[10*maxn];
char use[10][30]={"insert","getMin","removeMin"};
ll v[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		while(!aha.empty()) aha.pop();
		for(int i=0;i<n;i++)
		{
			scanf("%s",op[i]);
			scanf("%lld",&v[i]);
		}
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(strcmp(op[i],use[1])==0)
			{
				while(!aha.empty())
				{
					int tp=aha.top();
					if(tp<v[i]) 
					{
						aha.pop();
						strcpy(ans[cnt++],use[2]);
						continue;
					}
					else if(tp>v[i])
					{
						aha.push(v[i]);
						strcpy(ans[cnt],use[0]);
						go[cnt]=v[i];
						cnt++;
						break;
					}
					else
						break;
				}
				if(aha.empty())
				{
					aha.push(v[i]);
					go[cnt]=v[i];
					strcpy(ans[cnt++],use[0]);
				}
				go[cnt]=v[i];
				strcpy(ans[cnt++],use[1]);
			}
			else if(strcmp(op[i],use[0])==0)
			{
				aha.push(v[i]);
				go[cnt]=v[i];
				strcpy(ans[cnt++],use[0]);
			}
			else
			{
				if(aha.empty())
				{
					go[cnt]=1;
					strcpy(ans[cnt++],use[0]);
					aha.push(1);
				}
				strcpy(ans[cnt++],use[2]);
				aha.pop();
			}
		}
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++)
		{
			printf("%s",ans[i]);
			if(strcmp(ans[i],use[2])==0)
			{

			}
			else
			{
				printf(" %lld",go[i]);
			}
			printf("\n");
		}
	}
	return 0;
}


