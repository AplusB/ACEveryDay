#include <bits/stdc++.h>
using namespace std;

vector<int> Split(int n)
{
    vector<int> ret;
    if(n == 0)
    {
        ret.push_back(0);
    }
    for( ; n; n /= 7) ret.push_back(n % 7);
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<int> a, b;
int ans;
void dfs(int now, int tot, vector<int> &c)
{
    if(now == tot)
    {
        bool vis[10] = {false};
        bool flag = true;
        for(int ele : c)
        {
            if(vis[ele])
                flag = false;
            vis[ele] = true;
        }
        if(!flag)
            return ;
        for(int i = 0; i < a.size(); i++)
        {
            if(c[i] < a[i])
                break;
            if(c[i] > a[i])
            {
                flag = false;
                break;
            }
        }
        if(!flag)
            return ;

        for(int i = 0; i < b.size(); i++)
        {
            if(c[i + a.size()] < b[i])
                break;
            if(c[i + a.size()] > b[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            ans++;
        }
        return ;
    }
    for(int i = 0; i < 7; i++)
    {
        c.push_back(i);
        dfs(now + 1, tot, c);
        c.pop_back();
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    a = Split(n - 1);
    b = Split(m - 1);

    int tot = a.size() + b.size();
    if(tot > 7)
    {
        puts("0");
    }
    else
    {
        vector<int> c;
        dfs(0, tot, c);
        printf("%d\n", ans);
    }
    return 0;
}
