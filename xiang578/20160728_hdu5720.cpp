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
struct node
{
    ll l,r;
}b[N];
int n;
long long L,R,a[N];

int cmp(node n1,node n2)
{
    if(n1.l==n2.l)
        return n1.r<n2.r;
    else
        return n1.l<n2.l;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    ll ans,cur;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%lld%lld",&n,&L,&R);
        for(int i=0;i<n;i++)
            scanf("%lld",a+i);
        sort(a,a+n);
        for(int i=1;i<n;i++)
        {
            b[i].l=a[i]-a[i-1]+1;
            b[i].r=a[i]+a[i-1]-1;
        }
        //printf("111");
        sort(b+1,b+n,cmp);
        ans=0;
        cur=L;
        for(int i=1;i<n;i++)
        {
            //printf("%lld %lld\n",b[i].l,b[i].r);
            if(cur<b[i].l)
            {
                if(b[i].l>R)
                    ans+=R-cur+1;
                else
                    ans+=b[i].l-cur;
                cur=b[i].r+1;
            }
            if(cur<=b[i].r) cur=b[i].r+1;
            if(cur>=R) break;
        }
        //printf("%d\n",cur);
        if(cur<R) ans+=R-cur+1;
        printf("%lld\n",ans);
    }
    return 0;
}
