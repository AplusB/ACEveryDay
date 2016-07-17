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
    long long s,t,x;
    int f=0;
    scanf("%lld%lld%lld",&t,&s,&x);
    if(x==t) f=1;
    else if(x>t)
    {
        if(x-t>0&&(x-t)%s==0) f=1;
        if(x-t-1>0&&(x-t-1)%s==0) f=1;
    }

    if(f==1) puts("YES");
    else puts("NO");
    return 0;
}
