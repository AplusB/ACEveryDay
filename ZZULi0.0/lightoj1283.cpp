#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <stack>
//#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>
#include <ctime>
#define LL long long
using namespace std;
const int N = 105;

int books[N],ans,n;
int status[105][105][105];

void dfs(int low,int high,int cur)
{
    //printf("%d %d %d %d\n",low,high,cur,status[low][high][cur]);
    if(books[low] > books[high]) return;
    if(cur == n+1)
    {
        ans = max(ans,status[low][high][cur]);
        return;
    }
    if(books[cur] >= books[low])
    {
        if(status[cur][high][cur+1] < status[low][high][cur] + 1)
        {
            status[cur][high][cur+1] = status[low][high][cur] + 1;
            dfs(cur,high,cur+1);
        }
    }
    if(books[cur] <= books[high])
    {
        if(status[low][cur][cur+1] < status[low][high][cur] + 1)
        {
            status[low][cur][cur+1] = status[low][high][cur] + 1;
            dfs(low,cur,cur+1);
        }
    }
    if(status[low][high][cur+1] < status[low][high][cur])
    {
        status[low][high][cur+1] = status[low][high][cur];
        dfs(low,high,cur+1);
    }
}

void solve()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&books[i]);
    }
    books[0] = 0;
    books[n+1] = 100005;
    memset(status,-1,sizeof(status));
    ans = 0;

    status[0][n+1][1] = 0;
    dfs(0,n+1,1);

    printf("%d\n",ans);

}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
