/* ***********************************************
Author        :xdlove
Created Time  :2016年05月16日 星期一 20时07分02秒
File Name     :POJ/3764.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int N = 1e5 + 10;
vector<pair<int,int> > G[N];
int val[N];

struct Node
{
    Node()
    {
        next[0] = next[1] = NULL;
    }
    Node *next[2]; 
}*treeRoot;

void insert_treeNode(Node *pRoot,int x)
{
    Node *temp = pRoot;
    bitset<31> bt(x);
    for(int i = 30; i >= 0; --i)
    {
        if(temp->next[bt[i]] == NULL)
            temp->next[bt[i]] = new Node();
        temp = temp->next[bt[i]];
    }
}

int get_val(Node *pRoot,int x)
{
    bitset<31> bt(x);
    int ans = 0;
    Node *temp = pRoot;
    for(int i = 30; i >= 0; --i)
    {
        ans = ans * 2;
        if(temp->next[bt[i] ^ 1])
        {
            ++ans;
            temp = temp->next[bt[i] ^ 1];
        }
        else 
        {
            temp = temp->next[bt[i]];
        }
    }
    return ans;
}

void dfs(int u,int pre,int x)
{
    val[u] = x;
    for(int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i].first;
        if(v != pre)
            dfs(v,u,x ^ G[u][i].second);
    }
}

void readin(int &x)
{
    x = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
}

void destory(Node *pRoot)
{
    if(pRoot == NULL) return;
    for(int i = 0; i < 2; ++i)
        destory(pRoot->next[i]);
    delete pRoot;
}

void solve()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; ++i) G[i].clear();
        for(int i = 0; i < n - 1; ++i)
        {
            int u,v,w;
            readin(u),readin(v),readin(w);
            G[u].push_back(make_pair(v,w));
            G[v].push_back(make_pair(u,w));
        }
        dfs(0,-1,0);
        treeRoot = new Node();
        for(int i = 0; i < n; ++i) insert_treeNode(treeRoot,val[i]);
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans,get_val(treeRoot,val[i]));
        printf("%d\n",ans);
        destory(treeRoot);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve(); 
    return 0;
}
