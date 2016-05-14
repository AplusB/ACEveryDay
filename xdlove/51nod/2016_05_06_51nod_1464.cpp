/* ***********************************************
Author        :xdlove
Created Time  :2016年05月07日 星期六 15时49分30秒
File Name     :2016_05_06_51nod_1464.cpp
 ************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int N = 5005;
char s[N];
int k,n,l,r;
bool dp[N][N];
int vis[N];
string ans;

struct Tree
{
    Tree()
    {
        val = 0;
        memset(next,0,sizeof next);
    }
    int val;
    Tree *next[2];
}*tree_head;

void init()
{
    tree_head = new Tree();
    n = strlen(s);
    memset(dp,false,sizeof dp);
    for(int i = n - 1; i >= 0; --i)
    {
        dp[i][i] = true;
        vis[i] = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(s[i] == s[j])
            {
                if(i + 2 >= j - 2)
                    dp[i][j] = true;
                else dp[i][j] = dp[i + 2][j - 2];
            }
            if(dp[i][j]) vis[i] = j;
        }
    }
}

void insert_tree(Tree *ptemp, char *s)
{
    if(*s == '\0') return;
    if(r > vis[l]) return;
    int c = *s - 'a';
    if(ptemp->next[c] == NULL)
        ptemp->next[c] = new Tree();
    if(dp[l][r]) ptemp->next[c]->val++;
    r++;
    insert_tree(ptemp->next[c], s + 1);
}

void dfs(Tree *ptemp)
{
    string temp = ans;
    if(k > 0 && ptemp->next[0]) 
    {
        k -= ptemp->next[0]->val;
        ans = ans + 'a';
        dfs(ptemp->next[0]);
    }
    if(k > 0 && ptemp->next[1])
    {
        ans = temp;
        k -= ptemp->next[1]->val;
        ans = ans + 'b';
        dfs(ptemp->next[1]);
    }
}

void solve()
{
    scanf("%s %d",s,&k);
    init();
    for(int i = 0; i < n; ++i)
    {
        l = r = i;
        insert_tree(tree_head,s + i);
    }
    dfs(tree_head);
    cout << ans << endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();    
    return 0;
}
