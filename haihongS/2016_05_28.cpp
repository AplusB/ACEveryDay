/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月28日 星期六 14时58分40秒
File Name     :m2.cpp
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

int a[maxn],b[maxn];
int n,k;
string tmp;

int bib(int lt,int rt,int x);
int bia(int lt,int rt,int x);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(~scanf("%d%d",&n,&k))
	{
		cin>>tmp;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		if(tmp[0]=='a') a[0]=1;
		else b[0]=1;
		for(int i=1;i<n;i++)
		{
			if(tmp[i]=='a')
			{
				a[i]=a[i-1]+1;
				b[i]=b[i-1];
			}
			else
			{
				a[i]=a[i-1];
				b[i]=b[i-1]+1;
			}
		}
		
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int last;
			if(i==0) last=0;
			else last=b[i-1];

			if(tmp[i]=='b')
			{
				int len=bib(i+1,n-1,k+last);
				ans=max(ans,len-i);
				continue;
			}
			int len=bib(i+1,n-1,k+1+last);
			ans=max(ans,len-i);
		}
		for(int i=0;i<n;i++)
		{
			int last;
			if(i==0) last=0;
			else last=a[i-1];

			if(tmp[i]=='a')
			{
				int len=bia(i+1,n-1,k+last);
				ans=max(ans,len-i);
				continue;
			}
			int len=bia(i+1,n-1,k+1+last);
			ans=max(ans,len-i);
		}
		printf("%d\n",ans);
	}
    return 0;
}

int bia(int lt,int rt,int x)
{
	int ans=rt;
	int mid;
	int f=0;
	while(lt<=rt)
	{
		mid=lt+(rt-lt)/2;
		if(a[mid]<x)
			lt=mid+1;
		else
		{
			f=1;
			ans=min(ans,mid);
			rt=mid-1;
		}
	}
	if(f==1)
		return ans;
	else return n;
}

int bib(int lt,int rt,int x)
{
	int ans=rt;
	int mid;
	int f=0;
	while(lt<=rt)
	{
		mid=lt+(rt-lt)/2;
		if(b[mid]<x)
			lt=mid+1;
		else
		{
			f=1;
			ans=min(ans,mid);
			rt=mid-1;
		}
	}
	if(f==1)
		return ans;
	else return n;
}
