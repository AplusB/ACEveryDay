#include <bits/stdc++.h>
#define LL long long
#define PI acos(-1.0)
using namespace std;
char ss[1200];
int dp[1050][1050];
bool visit[1050][1050];

int dfs(int l,int r)
{
    if(l > r) return 0;
    if(l == r) return 1;
    if(visit[l][r]) return dp[l][r] = 1;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = 3000;
    for(int i = l; i <= r; i++)
        if(visit[l][i])
        ans = min(ans,dfs(i+1,r)+1);
    ans = min(ans,dfs(l+1,r)+1);
    return dp[l][r] = ans;
}

void solve()
{
    scanf("%s",ss+1);
    int len = (int)strlen(ss+1);
    memset(dp,-1,sizeof(dp));
    memset(visit,false,sizeof(visit));
    for(int i = 1; i <= len; i++)
    {
        visit[i][i] = true;
        int mid = i,l,r;
        l = mid,r = mid+1;
        while(l >= 1 && r <= len && ss[l] == ss[r])
        {
            visit[l][r] = true;
            l--;
            r++;
        }
        l = mid-1,r = mid+1;
        while(l >= 1 && r <= len && ss[l] == ss[r])
        {
            visit[l][r] = true;
            l--;
            r++;
        }
    }

    int ans = dfs(1,len);
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
