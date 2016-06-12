/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int ans=0,n,a,b[1024];
	scanf("%d%d",&n,&a);
	a--;
	for(int i=0;i<n;i++)
		scanf("%d",b+i);
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(b[a]==1) ans++;
		}
		else 
		{
			if(a-i>=0&&a+i<n)
			{
				if(b[a-i]&&b[a+i])
					ans+=2;
			}else if(a-i<0&&a+i<n&&b[a+i]) ans++;
			else if(a+i>=n&&a-i>=0&&b[a-i]) ans++;
		} 
	}
	printf("%d\n",ans);
    return 0;
}
