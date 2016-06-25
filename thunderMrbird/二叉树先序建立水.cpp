#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
const int N=50000;
int tree[10005];
int a[10005];
int t=0;
int sav=0;
bool flag=1;
void creat(int pos)
{
    int x;
    scanf("%d",&x);
    tree[pos] = x;
    if(x!=0)
    {
        creat(pos*2);
        creat(pos*2+1);
    }
}
void dfs(int pos)
{
    if(tree[pos]==0) return;
    dfs(pos*2);
    if(tree[pos]<=sav) {flag=0; return;}
    a[t]=pos;
    sav=a[t++];
    dfs(pos*2+1);
}
int main()
{
    memset(tree,0,sizeof(tree));
    creat(1);
    dfs(1);
    printf("%d",a[0]);
    for(int i=1;i<t;i++)
        printf(" %d",a[i]);
        printf("\n");
    if(flag)
    {
        printf("It is an BinaryOrderTree!\n");
    }
    else
        printf("It is not an BinaryOrderTree\n");
}
