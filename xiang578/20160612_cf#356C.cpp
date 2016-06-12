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
	int flag,a[100]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
	string s;
	flag=0;
	for(int i=0;i<19;i++)
	{
		cout<<a[i]<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]=='y') flag++;
	}
	if(flag>=2) 
		printf("composite\n");
	else 
		printf("prime\n");
    return 0;
}
