#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
const int maxn=4000009;

struct II
{
    int v;
    int next[26];
} tree[maxn];

char op[20],ans[40];
int loca;

int insert_word();
int creat_node(int s);
int searchit();
int del();

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        loca=1;
        for(int i=0; i<26; i++)
            tree[0].next[i]=-1;
        tree[0].v=0;
        while(n--)
        {
            scanf("%s",op);
            scanf("%s",ans);
            if(op[0]=='i')
                insert_word();
            else if(op[0]=='s')
            {
                int tmp=searchit();
                if(tmp) printf("Yes\n");
                else printf("No\n");
            }
            else if(op[0]=='d')
                del();
/*
            for(int i=0;i<loca;i++)
            {
                printf("%d-%d: ",i,tree[i].v);
                for(int j=0;j<26;j++)
                {
                    if(tree[i].next[j]!=-1)
                        printf(" %d",j);
                }
                printf("\n");
            }
*/
        }
    }
    return 0;
}

int del()
{
    int len=strlen(ans);
    int p=0;
    for(int i=0; i<len; i++)
    {
        int tmp=ans[i]-'a';
        if(tree[p].next[tmp]==-1) return 0;
        p=tree[p].next[tmp];
    }
    int tmp=tree[p].v;
    p=0;
    int last=p;
    for(int i=0; i<len; i++)
    {
        p=tree[p].next[ans[i]-'a'];
        tree[p].v-=tmp;
        if(tree[p].v==0)
        {
            tree[last].next[ans[i]-'a']=-1;return 0;
        }
        last=p;
    }
    tree[last].next[ans[len-1]-'a']=-1;
    return 0;
}

int searchit()
{
    int len=strlen(ans);
    int p=0;
    for(int i=0; i<len; i++)
    {
        int tmp=ans[i]-'a';
        if(tree[p].next[tmp]==-1) return 0;
        p=tree[p].next[tmp];
    }
    return 1;
}

int creat_node(int s)
{
    tree[s].v=0;
    for(int i=0; i<26; i++) tree[s].next[i]=-1;
    return 0;
}

int insert_word()
{
    int len=strlen(ans);
    int p=0;
    tree[0].v++;
    for(int i=0; i<len; i++)
    {
        int tmp=ans[i]-'a';
        if(tree[p].next[tmp]==-1)
        {
            creat_node(loca);
            tree[p].next[tmp]=loca;
            p=loca;
            loca++;
        }
        else
        {
            p=tree[p].next[tmp];
        }
        tree[p].v++;
    }
    return 0;
}
