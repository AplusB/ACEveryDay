#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;
int dp[maxn], cnt[maxn][maxn], nxt[maxn];
char str[maxn];

void get_next(char s[], int len){
    int i = 0, j = -1;
    nxt[i] = -1;
    while(i < len){
        if(j == -1 || s[i] == s[j]){
            i++;
            j++;
            nxt[i] = j;
        }else j = nxt[j];
    }
}

int main(){
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    for(int i = 1; i <= n; i++){
        get_next(str + i, n - i + 1);
        for(int j = i; j <= n; j++){
            int l = j - i + 1;
            cnt[i][j] = l % (l - nxt[l]) ? 1 : l / (l - nxt[l]);
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            ans += dp[cnt[i][j]];
        }
        for(int j = 1; j <= i; j++){
            dp[cnt[j][i]]++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
