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
const int maxn=2e5+200;
const double eps=1e-9;

int main()
{
	int n,x,y;
	while(~scanf("%d%d%d",&n,&x,&y))
	{
		double num=1.0*y*n/100;
		int ans=(int)num;
		if(ans<num) ans+=1;
		ans-=x;
		if(ans<0) ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
