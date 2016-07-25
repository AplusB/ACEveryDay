#include <cstdio>
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
#define INF 0x3f3f3f3f
#define endl '\n'
#define mod 1000000000
#define ll long long
#define eps 1e-8
using namespace std;
vector<int>v[1000],g[1000];
void solve(int n)
{
    v[1].push_back(1),g[1].push_back(1);
    if(n==1) return;
    for(int i=3;i<=n;i+=2)
    {
        for(int j=1;j<=i/2;j++) v[i].push_back(j),g[i].push_back(i/2+1);
        for(int j=i/2+1;j>0;j--) v[i].push_back(i/2+1),g[i].push_back(j);
    }
    if((n-3)%4==0)
    {
        v[2].push_back(1),g[2].push_back(n/2+2);
        v[2].push_back(2),g[2].push_back(n/2+2);
        int flag=1,x=3,y=n/2+3;
        for(int i=4;i<=n;i+=2)
        {
            if(flag)
            {
                for(int j=1;j<=i/2;j++) v[i].push_back(j),g[i].push_back(y);
                for(int j=i/2;j>0;j--) v[i].push_back(j),g[i].push_back(y+1);
                y=y-i/2+1;flag^=1;
            }
            else
            {
                for(int j=0;j<i/2;j++) v[i].push_back(x),g[i].push_back(y+j);
                for(int j=i/2-1;j>=0;j--) v[i].push_back(x+1),g[i].push_back(y+j);
                y=y+i/2;x=x+2;flag^=1;
            }

        }
    }
    else
    {
        v[2].push_back(1),g[2].push_back(n/2+2);
        v[2].push_back(1),g[2].push_back(n/2+3);
        int flag=1,x=2,y=n/2+2;
        for(int i=4;i<=n;i+=2)
        {
            if(flag)
            {
                for(int j=0;j<i/2;j++) v[i].push_back(x),g[i].push_back(y+j);
                for(int j=i/2-1;j>=0;j--) v[i].push_back(x+1),g[i].push_back(y+j);
                x=x+2,y=y+i/2;flag^=1;
            }
            else
            {
                for(int j=1;j<=i/2;j++) v[i].push_back(j),g[i].push_back(y);
                for(int j=i/2;j>0;j--) v[i].push_back(j),g[i].push_back(y+1);
                y=y-i/2+1;flag^=1;
            }
        }
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<=n;i++) v[i].clear(),g[i].clear();
        int x=(n+1)/2;
        int y=(n+1)*n/2/x;
        cout<<x<<" "<<y<<endl;
        if(n%2) solve(n);
        else
        {
            solve(n-1);
            for(int i=1;i<=x;i++) v[n].push_back(i),g[n].push_back(y-1);
            for(int i=x;i>=1;i--) v[n].push_back(i),g[n].push_back(y);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i-1;j++) cout<<v[i][j]<<" "<<g[i][j]<<" ";
            cout<<v[i][i-1]<<" "<<g[i][i-1]<<endl;
        }
    }
    return 0;
}
