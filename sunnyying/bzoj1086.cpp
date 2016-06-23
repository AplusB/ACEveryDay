#include <stdio.h>
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
#define N 250010
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
#define mod 1000000007
using namespace std;
int size[N],ans[N],sum,flag[N],n,k;
stack<int>s;
vector<int>v[N];
void dfs(int x,int pre)
{
    size[x]=0;s.push(x);
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i];
        if(xx==pre) continue;
        dfs(xx,x);
        size[x]+=size[xx];
        if(size[x]>=k)
        {
            ans[sum]=x;
            while(s.top()!=x)
            {
                flag[s.top()]=sum;
                s.pop();
            }
            size[x]=0;sum++;
        }
    }
    size[x]++;
}
int main()
{
   // freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    int x,y;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(n<k)
    {
        cout<<0<<endl;
        return 0;
    }
    dfs(1,0);
    while(s.size())
    {
        x=s.top();s.pop();
        flag[x]=sum-1;
    }
    cout<<sum<<endl;
    for(int i=1;i<n;i++) cout<<flag[i]+1<<" ";cout<<flag[n]+1<<endl;
    for(int i=0;i<sum-1;i++) cout<<ans[i]<<" ";cout<<ans[sum-1]<<endl;
    return 0;
}
