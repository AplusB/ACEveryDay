#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
const int N = 3e6 + 10;
struct Node
{
    void init()
    {
        val = 0;
        memset(next,-1,sizeof next);
    }
    int val;
    int next[26];
}treeRoot[N];
int tot;

void init()
{
    tot = 0;
}

void dfs(int pos)
{
    if(treeRoot[pos].val == 1)
        treeRoot[pos].val = -1;
    for(int i = 0; i < 26; ++i)
    {
        if(treeRoot[pos].next[i] != -1)
        {
            int tp = treeRoot[pos].next[i];
            dfs(tp);
        }
    }
}

void insert_string(char *s)
{
    int pos = 0;
    for(int i = 0; s[i]; ++i)
    {
        int c = s[i] - 'a';
        if(treeRoot[pos].next[c] == -1)
        {
            treeRoot[pos].next[c] = ++tot;
            treeRoot[tot].init();
        }
        pos = treeRoot[pos].next[c];
    }
    treeRoot[pos].val = 1;
}

bool dfsAgain(int pos)
{
    if(treeRoot[pos].val == 1)
        return true;
    bool isTrue = false;
    for(int i = 0; i < 26 && !isTrue; ++i)
    {
        if(treeRoot[pos].next[i] != -1)
        {
            int tp = treeRoot[pos].next[i];
            isTrue = dfsAgain(tp);
        }
    }
    return isTrue;
}

bool find_preString(char *s)
{
    int pos = 0;
    for(int i = 0; s[i]; ++i)
    {
        int c = s[i] - 'a';
        if(treeRoot[pos].next[c] == -1)
            return false;
        pos = treeRoot[pos].next[c];
    }
    return dfsAgain(pos);
}

void delete_string(char *s)
{
    int pos = 0;
    for(int i = 0; s[i]; ++i)
    {
        int c = s[i] - 'a';
        if(treeRoot[pos].next[c] == -1)
            return;
        pos = treeRoot[pos].next[c];
    }
    dfs(pos);
}

char s[40],t[40];

int main()
{
    int n;
    cin >> n;
    treeRoot[0].init();
    init();
    for(int i = 0; i < n; ++i)
    {
        scanf("%s %s",t,s);
        if(!strcmp(t,"insert")) insert_string(s);
        else if(!strcmp(t,"search")) puts(find_preString(s) ? "Yes" : "No");
        else
        {
            delete_string(s);
        }
    }
    return 0;
}

