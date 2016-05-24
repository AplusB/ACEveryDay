#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#define endl '\n'
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a > b ? b : a)

using namespace std;

const int MAXN = 1e6 + 5;

vector<int> g[MAXN];
int dig[MAXN],n,m;;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        
        priority_queue<int,vector<int>,less<int> > que;
        
        int i;
        for(i = 0;i <= n;i++)g[i].clear();
        
        int x,y;
        for(i = 0;i < m;i++)
        {
            scanf("%d %d",&x,&y);
            dig[y]++;
            g[x].push_back(y);
        }
        
        long long mmin = n + 1,ans = 0;
        for(i = 1;i <= n;i++)if(!dig[i])que.push(i);
        
        for(i = 1;i <= n;i++)
        {
            int x = que.top();
            que.pop();
            int j;
            for(j = 0;j < g[x].size();j++)
            {
                int y = g[x][j];
                dig[y]--;
                if(!dig[y])que.push(y);
            }
            mmin = min(mmin,x);
            ans += mmin;
        }
        
        cout << ans << endl;
    }
    return 0;
}
