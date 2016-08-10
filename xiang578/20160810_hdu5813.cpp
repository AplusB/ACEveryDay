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
int n,u[N];
vector<int>g[N];
struct node
{
    int num,cnt;
}p[N];

int cmp(node n1,node n2)
{
    if(n1.cnt==n2.cnt)
        return n1.num<n2.num;
    else
        return n1.cnt<n2.cnt;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,__,t,ans;
    scanf("%d",&__);
    for(_=1;_<=__;_++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            p[i].num=i;
            p[i].cnt=t;
        }
        sort(p+1,p+n+1,cmp);
        int ok=1;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i].cnt==0) continue;
            else if(p[i].cnt>i-1)
            {
                ok=0;break;
            }
            else
            {
                for(int j=1;j<=p[i].cnt;j++)
                {
                    g[p[i].num].push_back(p[j].num);
                    ans++;
                }
            }
        }
        printf("Case #%d: ",_);
        if(ok==0) puts("No");
        else
        {
            puts("Yes");
            printf("%d\n",ans);
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<g[i].size();j++)
                {
                    printf("%d %d\n",i,g[i][j]);
                }
            }
        }
    }
    return 0;
}
