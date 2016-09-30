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
const int maxn=2e5+90;
const ll inf=2e13+9;
const ll mod=1e9+7;
const double eps=1e-9;

int a[4];

int main()
{
	int x,y;
	while(~scanf("%d%d",&x,&y))
	{
		int cnt=0;
		if(x>y) swap(x,y);
		a[0]=a[1]=a[2]=x;
		while(1)
		{
			sort(a,a+3);
			if(a[0]==y && a[2]==y) break;
			int nx=a[1]+a[2]-1;
			if(nx>=y) nx=y;
			a[0]=nx;
			cnt++;
		}
		printf("%d\n",cnt);

	}
	return 0;
}

