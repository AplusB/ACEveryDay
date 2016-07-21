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
int sg[1<<21];

int get(int x)
{
    if(x==0) return sg[x]=0;
    if(sg[x]!=-1) return sg[x];
    int mex[50];
    int pre=-1;
    memset(mex,0,sizeof(mex));
    for(int j=19;j>=0;j--)
    {
        if(x&(1<<j))
        {
            if(pre==-1) continue;
            int t=x^(1<<j)^(1<<pre);
           mex[get(t)]=1;
        }
        else
        {
            pre=j;
        }
    }
    for(int i=0;i<50;i++)
    {
        if(mex[i]==0)
        {
            sg[x]=i;
            break;
        }
    }
    return sg[x];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,m,t,k,ans;
    memset(sg,0xff,sizeof(sg));
    for(int i=0;i<(1<<20);i++) sg[i]=get(i);
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        ans=0;
        for(int i=0;i<n;i++)
        {
            t=0;
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&k);
                k--;
                t|=(1<<k);
            }
            ans=ans^sg[t];
        }
        if(ans==0) puts("NO");
        else puts("YES");
    }
    return 0;
}
/*
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
int sg[1<<20];

int get(int x)
{
    if(x==0) return sg[x]=0;
    if(sg[x]!=-1) return sg[x];
    int mex[50];
    memset(mex,0,sizeof(mex));
    int pre=-1;
    for(int j=19;j>=0;j--)
    {
        int k=(1<<j);
        if(x&k)
        {
            if(pre==-1) continue;
            int t=x-k+(1<<pre);
           mex[get(t)]=1;
        }
        else
        {
            pre=j;
        }
    }
    for(int i=0;i<50;i++)
    {
        if(mex[i]==0)
        {
            sg[x]=i;
            break;
        }
    }
    return sg[x];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,m,t,k,ans;
    for(int i=0;i<(1<<20);i++) sg[i]=-1;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        ans=0;
        for(int i=0;i<n;i++)
        {
            t=0;
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&k);
                k--;
                t|=(1<<k);
            }
            ans=ans^get(t);
        }
        if(ans==0) puts("NO");
        else puts("YES");
    }
    return 0;
}*/
