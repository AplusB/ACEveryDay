#include <bits/stdc++.h>
using namespace std;

const int N = 300010;
vector<int> edge[N];
int ans[N], son[N], father[N];

void AddEdge(int u, int v)
{
    edge[u].push_back(v);
}

int n;
int dfs(int u)
{
    son[u] = 1;
    int mx = 0, center = u;
    for(int v: edge[u])
    {
        dfs(v);
        son[u] += son[v];
        if(son[v] > mx)
        {
            mx = son[v];
            center = ans[v];
        }
    }
    while(son[center] < (son[u] + 1) / 2 && center != u)
    {
        center = father[center];
    }
    ans[u] = center;
}
int main()
{
    int q;
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        cin >> father[i + 1];
        AddEdge(father[i + 1], i + 1);
    }
    dfs(1);
    int x;
    while(q--)
    {
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}
