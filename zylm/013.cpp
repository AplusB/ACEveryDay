//http://codeforces.com/contest/673/problem/B
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
	 int i,j,n,m;
	 while(~scanf("%d%d",&n,&m))
	 {
	 	map<int,int> ma,mb;
	 	int a[maxn],b[maxn];
	 	for(i=0;i<m;i++)
	 	{
	 		scanf("%d%d",&a[i],&b[i]);
			 if(a[i]>b[i])swap(a[i],b[i]); 
		 } 
		 sort(a,a+m);
		 sort(b,b+m);
		 for(i=0;i<n;i++)
		 ma[a[i]]=1;
		 int res=1;
		 for(i=0;i<m;i++)
		 {
		 	if(ma[b[i]])
		 	{
		 		res=0;
		 		break;
			 }
		 	else mb[b[i]]=1;
		 }
		 if(a[m-1]>b[0])res=0;
		if(res)
		{
			if(m==0)printf("%d\n",n-1);
		    else printf("%d\n",b[0]-a[m-1]);
		}
		else printf("0\n");
		
	 }
}
