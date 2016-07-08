#include<bits/stdc++.h>
using namespace std;
const int N=200000+10;
int n,a[N],use[N],ans[N];
vector<int>g[N];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            g[i].push_back(a[i]);
            if(i!=n) g[i].push_back(i+1);
            if(i!=1) g[i].push_back(i-1);
        }
        memset(ans,0xff,sizeof(ans));
        queue<int>q;
        q.push(1);
        ans[1]=0;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int i=0;i<g[k].size();i++)
            {
                int y=g[k][i];
                if(ans[y]==-1||ans[y]>ans[k]+1)
                {
                    ans[y]=ans[k]+1;
                    q.push(y);
                }
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
