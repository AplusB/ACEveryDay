#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define INF 32768
#define ll long long
using namespace std;
int vis[100000],a[100000];
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        ll x,m,k,c;
        scanf("%I64d%I64d%I64d%I64d",&x,&m,&k,&c);
        memset(vis,-1,sizeof(vis));
        vis[0]=0;
        cout<<"Case #"<<cas++<<":"<<endl;
        int ans=0,sum=1;a[0]=0;
        if(k==0)
        {
            if(c==0) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            continue;
        }
        while(m--)
        {
            ans=(ans*10+x)%k;
            if(vis[ans]!=-1) break;
            vis[ans]=sum;
            a[sum++]=ans;
        }
        if(m==0)
        {
            if(ans==c) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            continue;
        }
        int xx=vis[ans];
        int yy=sum-vis[ans];
        if(a[m%yy+xx]==c) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
/*
3
1 3 5 2
*/
