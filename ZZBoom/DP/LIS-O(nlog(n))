//poj 2533

/*#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
const double pi = acos(-1.0);

const int mod =9973;

const int N = 1e8+10;

int vis[N];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int x;
		int ans;
		int y;
		y=(n+1)/2;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			vis[x]++;
			if(vis[x]>y)
				ans=x;
		}
		printf("%d\n",ans);
	}
	return 0;
}

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N =1e5+10;
int a[N];
int d[N];

int kill(int len,int x)
{
	int b=1,e=len;
	while(b<=e)
	{
		int mid=(b+e)/2;
		if(x>d[mid])
			b=mid+1;
		else
			e=mid-1;
	}
	return b;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	d[1]=a[1];
	int len=1;
	int j;
	
	for(int i=2;i<=n;i++)
	{
		if(d[1]>=a[i])
			j=1;
		else if(a[i]>d[len])
			j=++len;
		else
			j=kill(len,a[i]);
		d[j]=a[i];
	}
	printf("%d\n",len);
	return 0;
}






