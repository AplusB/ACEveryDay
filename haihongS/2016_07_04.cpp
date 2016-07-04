#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

vector<int> ans[maxn*10];

int main()
{
	for(int i=0;i<maxn;i++)
		ans[i].clear();

	int cnt2,cnt5,cnt;
	cnt2=cnt5=cnt=0;
	for(int i=1;i<5*maxn;i++)
	{
		if(i%2==0)
		{
			int tmp=i;
			while(tmp%2==0)
			{
				cnt2+=1;
				tmp/=2;
			}
		}
		if(i%5==0)
		{
			int tmp=i;
			while(tmp%5==0)
			{
				cnt5+=1;
				tmp/=5;
			}
		}
		int tmp=min(cnt2,cnt5);
		cnt+=tmp;
		cnt2-=tmp;
		cnt5-=tmp;
		ans[cnt].push_back(i);
	}
	int m;
	while(~scanf("%d",&m))
	{
			printf("%d\n",ans[m].size());
			if(ans[m].size()==0)
				continue;
			for(int i=0;i<ans[m].size()-1;i++)
				printf("%d ",ans[m][i]);
			printf("%d\n",ans[m][ans[m].size()-1]);
	}
	return 0;
}
