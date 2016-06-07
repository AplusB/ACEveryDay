//http://codeforces.com/contest/669/problem/A 
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 100005
using namespace std;
int main()
{
	 int i,j,n;
	 while(~scanf("%d",&n))
	 {
	     printf("%d\n",n/3*2+(n%3==0?0:1));
	 }
}
