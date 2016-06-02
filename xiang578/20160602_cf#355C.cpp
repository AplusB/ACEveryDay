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
int get(char c)
{
	if(c>='0'&&c<='9')
		return c-'0';
	else if('A'<=c&&c<='Z')
		return c-'A'+10;
	else if('a'<=c&&c<='z')
		return c-'a'+36;
	else if(c=='-') return 62;
	else if(c=='_') return 63;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	char s[100000+10];
	long long a[100];
	long long ans;
	long long mod=1e9+7;
	memset(a,0,sizeof(a));
	for(int i=0;i<=63;i++)
	{
		for(int j=0;j<=63;j++)
		{
			if(i==j) continue;
			a[i&j]++;
		}
	}
	scanf("%s",s);
	int len=strlen(s);
	ans=1;
	for(int i=0;i<len;i++)
	{
		ans=ans+ans*a[get(s[i])];
		ans%=mod;
	}
	printf("%lld\n",ans);
    return 0;
}
