#include<cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 200000+10
#define INF 0x3f3f3f3f
#define endl '\n'
#define mod  1000000007
#define ll long long
#define eps 1e-10
using namespace std;
int sg[(1<<21)],vis[22];
int main()
{
    for(int i=1;i<(1<<20);i++)
    {
        memset(vis,-1,sizeof(vis));
        int last=-1;
        for(int j=0;j<20;j++)
        {
            if(!(i&(1<<j))) last=j;
            else if(last!=-1) vis[sg[i^(1<<j)^(1<<last)]]=1;
        }
        int x=0;
        while(vis[x]!=-1) x++;
        sg[i]=x;
    }
    int t,n,m,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        while(n--)
        {
            scanf("%d",&m);
            int flag=0;
            while(m--)
            {
                scanf("%d",&x);
                flag=flag^(1<<(20-x));
            }
            ans=ans^sg[flag];
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
