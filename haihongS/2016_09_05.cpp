#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=100+9;
const double eps=1e-9;
const ll inf=2e15+9;
const ll mod=2016;

int x[maxn],y[maxn];

int main()
{
	int n1,b1,n2,b2;
	while(~scanf("%d%d",&n1,&b1))
	{
		for(int i=0;i<n1;i++)
			scanf("%d",&x[i]);
		scanf("%d%d",&n2,&b2);
		for(int i=0;i<n2;i++)
			scanf("%d",&y[i]);
		ll g1=0,g2=0;
		ll go=1;
		for(int i=n1-1;i>=0;i--)
		{
			g1+=go*(ll)x[i];
			go*=(ll)b1;
		}
		go=1;
		for(int i=n2-1;i>=0;i--)
		{
			g2+=go*(ll)y[i];
			go*=(ll)b2;
		}
		if(g1==g2)
			printf("=\n");
		else if(g1<g2)
			printf("<\n");
		else
			printf(">\n");
	}
	return 0;
}
