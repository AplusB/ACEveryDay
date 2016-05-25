/* ***********************************************
Author        :shootPlane
Created Time  :2016/5/23 21:02:09
File Name     :D:\sherlock\main.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=1e9+9;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll r,g,b;
	while(~scanf("%I64d%I64d%I64d",&r,&g,&b))
	{
		ll ans=0;
		ll a[4];
		a[0]=r,a[1]=g,a[2]=b;
		sort(a,a+3);
		ans=min(a[0]+a[1],(a[0]+a[1]+a[2])/3);
		printf("%I64d\n",ans);
	}
    return 0;
}
