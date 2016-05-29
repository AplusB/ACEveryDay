#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
int x[2005],y[2005];
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d %d",x+i,y+i);
            for(int j=0;j<i;j++)
            ans+=mp[{x[i]+x[j],y[i]+y[j]}]++;
    }
    printf("%d\n",ans);
    return 0;
}
