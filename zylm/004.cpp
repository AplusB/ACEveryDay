//http://codeforces.com/contest/672/problem/A
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 100005
using namespace std;
char a[maxn]; 
int main()
{
	int i,j,n,k=0;
	for(i=1;i<=1000;i++)
	{
		char str[10];
		itoa(i,str,10);
		int len = strlen(str);
	//	printf("%s\n",str);
		for(j=0;j<len;j++)a[k++]=str[j];
	}
	while(~scanf("%d",&n))
	{
		cout<<a[n-1]<<endl;
	}
	
}
