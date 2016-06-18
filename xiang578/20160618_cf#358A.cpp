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
ll a[10],b[10];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	ll t,ans,n,m;
	scanf("%lld%lld",&n,&m);
	t=n/5;
	n%=5;
	for(int i=0;i<5;i++)
	{	
		a[i]=t;
		if(i&&i<=n) a[i]++;
	}
	t=m/5;
	m%=5;
	ans=0;
	for(int i=0;i<5;i++)
	{
		b[i]=t;
		if(i&&i<=m) b[i]++;
		if(i) ans+=b[i]*a[5-i];
		else ans+=b[0]*a[0];
	}
	cout<<ans<<endl;
    return 0;
}
