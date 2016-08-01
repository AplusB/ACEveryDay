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
const int N=1e5+10;
int a[N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k,_;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d",a+i);
        }
        sort(a,a+n-1);
        ll ans=n;
        for(int i=0;i<n-k;i++)
            ans+=a[i];
        printf("%lld\n",ans);
    }
    return 0;
}
