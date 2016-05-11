#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
vector<P> edge[1200];
vector<int> ans;
int mindis[1200];
bool inQue[1200];
int toCycle[1200];
int updated[1200];
int n, m;

void Dfs(int cur)
{
    ans.push_back(cur);
    toCycle[cur] = true;
    for(int i = 0; i < static_cast<int>(edge[cur].size()); ++i)
    {
        P next = edge[cur][i];
        if(!toCycle[next.first])
            Dfs(next.first);
    }
}
bool Spfa()
{
    ans.clear();
    memset(mindis, 0, sizeof(mindis));
    memset(updated, 0, sizeof(updated));
    queue<int> que;
    for(int i = 0; i < n; ++i)
        que.push(i);
    memset(inQue, true, sizeof(inQue));
    while(que.size())
    {
        int now = que.front();
        que.pop();
        inQue[now] = false;
        if(updated[now] > n)
        {
            if(!toCycle[now])
                Dfs(now);
            continue;
        }
        for(int i = 0; i < static_cast<int>(edge[now].size()); ++i)
        {
            P next = edge[now][i];
            if(next.second + mindis[now] < mindis[next.first])
            {
                mindis[next.first] = next.second + mindis[now];
                if(!inQue[next.first])
                {
                    inQue[next.first] = true;
                    que.push(next.first);
                }
                ++updated[next.first];
            }
        }
    }
    return !ans.empty();
}
int main()
{
    int _case = 1;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(edge, 0, sizeof(edge));
        memset(toCycle, false, sizeof(toCycle));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[v].push_back(make_pair(u, w));
        }
        printf("Case %d: ", _case++);
        if(Spfa())
        {
            sort(ans.begin(), ans.end());
            for(int i = 0; i < static_cast<int>(ans.size()); ++i)
            {
                if(i)
                    printf(" ");
                printf("%d", ans[i]);
            }
        }
        else
            printf("impossible");
        printf("\n");
    }
    return 0;
}
