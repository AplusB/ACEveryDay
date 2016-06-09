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
int a[maxn];

int main()
{
	 int n;
	 while(~scanf("%d",&n))
	 {
	 	 int i,j;
	 	 for(i=0;i<n;i++)scanf("%d",&a[i]);
	 	 sort(a,a+n);
	 	 int len= unique(a,a+n)-a;
	 	 int flag=0;
	 	 for(i=0;i<len-2;i++)
	 	 {
	 	 	if(a[i]+1==a[i+1] && a[i+1]+1==a[i+2])
	 	 	{
	 	 		flag=1;
	 	 		break;
			  }
		  }
		  if(flag)cout<<"YES"<<endl;
		  else cout<<"NO"<<endl;
	  } 
}
