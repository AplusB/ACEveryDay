#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
const int maxn=1000+9;
const int inf=2e9+9;

int m[10],w[10],fen[10];

int main()
{
	fen[0]=500,fen[1]=1000,fen[2]=1500,fen[3]=2000,fen[4]=2500;
	for(int i=0;i<5;i++)
		scanf("%d",&m[i]);
	for(int i=0;i<5;i++)
		scanf("%d",&w[i]);
	int s,u;
	scanf("%d%d",&s,&u);
	int ans=0;
	for(int i=0;i<5;i++)
	{
		int tmp=fen[i]-fen[i]/250*m[i]-50*w[i];
		int t2=0.3*fen[i];
		ans+=max(t2,tmp);

	}
	ans=ans+100*s-50*u;
	printf("%d\n",ans);
	return 0;
}
