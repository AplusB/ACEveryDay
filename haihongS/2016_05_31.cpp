#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>


using namespace std;
const int MAXN=1800;

int dp[MAXN][2];
int fa[MAXN];
vector<int> son[MAXN];

int solve(int x);
int min(int a,int b);

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        int root;
        memset(fa,-1,sizeof(fa));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<MAXN;i++)
            son[i].clear();
        for(int i=0;i<n;i++)
        {
            int num;
            scanf("%d",&num);
            root=num;
            dp[num][1]=1;
            char nouse;
            int cnt;
            scanf("%c%c%d%c",&nouse,&nouse,&cnt,&nouse);
            for(int j=0;j<cnt;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                fa[tmp]=num;
                son[num].push_back(tmp);
            }
        }
        while(fa[root]!=-1)
            root=fa[root];
        solve(root);
        printf("%d\n", min(dp[root][0],dp[root][1]));
    }
    return 0;
}

int solve(int x)
{
    int len=son[x].size();
    for(int i=0;i<len;i++)
    {
        solve(son[x][i]);
    }
    for(int i=0;i<len;i++)
    {
        int j=son[x][i];
        dp[x][0]+=dp[j][1];
        dp[x][1]+=min(dp[j][1],dp[j][0]);
    }
    return 0;
}

int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
