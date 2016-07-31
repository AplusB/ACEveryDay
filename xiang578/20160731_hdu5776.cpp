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
int a[10000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,ans,n,m,t,ok;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        ans=0;
        ok=0;
        memset(a,0,sizeof(a));
        a[0]=1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            ans+=t;
            ans%=m;
            if(a[ans]==1) ok=1;
            a[ans]=1;
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
