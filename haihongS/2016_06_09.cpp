/* ***********************************************
Author        :shootPlane
Created Time  :2016年06月09日 星期四 15时41分20秒
File Name     :main.cpp
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
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int cnt=0;
		while(1)
		{
		cnt++;
		n-=1;
		if(cnt%m==0) n+=1;
		if(n<=0) break;
		}
		printf("%d\n",cnt);
	}
    return 0;
}
