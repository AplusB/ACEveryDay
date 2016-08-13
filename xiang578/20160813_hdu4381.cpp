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
const int inf=0x3f3f3f3f;
struct node
{
    int s,w;
};
vector<node>p[2];

int cmp1(node a,node b)
{
    return a.s<b.s;
}

int cmp2(node a,node b)
{
    return a.s<b.s;
}

int mi(int x,int y)
{
    if(x<y) return x;
    else return y;
}
int l[N],r[N],n,m,u,v,w;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,cas=0,ans1,ans2;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        p[0].clear();p[1].clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            node t;
            t.w=w;
            if(u==1)
            {
                t.s=v;
                p[0].push_back(t);
            }
            else
            {
                t.s=n-v+1;
                p[1].push_back(t);
            }
        }
        sort(p[0].begin(),p[0].end(),cmp1);
        sort(p[1].begin(),p[1].end(),cmp2);
        for(int i=1;i<=n;i++) l[i]=r[i]=inf;
        l[0]=0;
        r[0]=0;
        for(int i=0;i<p[0].size();i++)
        {
            for(int j=p[0][i].s;j>=p[0][i].w;j--)
                l[j]=mi(l[j],l[j-p[0][i].w]+1);
        }
        for(int i=0;i<p[1].size();i++)
        {
            for(int j=p[1][i].s;j>=p[1][i].w;j--)
                r[j]=mi(r[j],r[j-p[1][i].w]+1);
        }
        ans1=0;
        ans2=inf;
        for(int k=n;k>=0;k--)
        {
            for(int i=0;i<=k;i++)
            {
                if(l[i]<inf&&r[k-i]<inf)
                {
                    if(k==ans1) ans2=mi(ans2,l[i]+r[k-i]);
                    else if(k>ans1)
                    {
                        ans1=k;
                        ans2=l[i]+r[k-i];
                    }
                }
            }
            if(ans1>k) break;
        }
        printf("Case %d: %d %d\n",++cas,ans1,ans2);
    }
    return 0;
}
