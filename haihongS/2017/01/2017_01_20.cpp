#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>


using namespace std;
typedef long long ll;
const int maxn=2e6+9;
const double inf=2e13+9;
const ll mod=1e9+7;
double eps=1e-6;
double pi=acos(-1.0);

char a[maxn],b[maxn],m[5]={'R','B','Y','G'};
int ans[5],pos[5];

// r b y g
int main()
{
	while(~scanf("%s",a))
	{
		memset(ans,0,sizeof(ans));
		memset(pos,-1,sizeof(pos));
		memset(b,0,sizeof(b));
		int len=strlen(a);
		for(int i=0;i<len;i++)
		{
			if(a[i]=='!') continue;
			if(a[i]=='R' && pos[0]==-1) pos[0]=i;
			if(a[i]=='B' && pos[1]==-1) pos[1]=i;
			if(a[i]=='Y' && pos[2]==-1) pos[2]=i;
			if(a[i]=='G' && pos[3]==-1) pos[3]=i;
		}
		for(int i=0;i<4;i++)
			pos[i]%=4;
		for(int i=0;i<4;i++)
		{
			for(int j=pos[i];j<len;j+=4)
				b[j]=m[i];
		}
		for(int i=0;i<len;i++)
		{
			if(a[i]=='!')
			{
				if(b[i]=='R') ans[0]++;
				else if(b[i]=='B') ans[1]++;
				else if(b[i]=='Y') ans[2]++;
				else if(b[i]=='G') ans[3]++;
			}
		}
		printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);


	}
	return 0;
}
