#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char A[50],B[50];

LL sta[50][50][100];
int la,lb,lc;


LL dfs(int cura,int curb,int curc)
{
    LL &ans = sta[cura][curb][curc];
    if(curc <= 0) return ans = (cura == 0 && curb == 0);
    if(ans != -1) return ans;
    ans = 0;
    if(cura > 0 && curb > 0 && A[cura] == B[curb])
    {
        ans += dfs(cura-1, curb-1, curc-1);
    }
    else
    {
        if(cura > 0)
            ans += dfs(cura-1, curb, curc-1);
        if(curb > 0)
            ans += dfs(cura, curb-1, curc-1);
    }
    return ans;
}

void solve()
{
    scanf("%s %s",A+1,B+1);

    la = strlen(A+1);
    lb = strlen(B+1);

    int dp[40][40];
    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= la; i ++)
        for(int j = 1; j <= lb; j ++)
            if(A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    lc = la+lb - dp[la][lb];
    memset(sta,-1,sizeof(sta));
    reverse(A+1, A+la+1), reverse(B+1, B+lb+1);
    //puts(A+1), puts(B+1);
    LL ans = dfs(la,lb,lc);
    printf("%d %lld\n", lc, ans);
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
