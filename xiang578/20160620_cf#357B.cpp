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
	int n,a,b,c;
	cin>>n;
	a=n/1234567;
	for(int i=a;i>=0;i--)
	{
		b=(n-i*1234567)/123456;
		for(int j=b;j>=0;j--)
		{
			c=n-i*1234567-j*123456;
			if(c%1234==0)
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
    return 0;
}
