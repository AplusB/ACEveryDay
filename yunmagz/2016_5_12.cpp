//lightoj 1051 - Good or Bad
#include <bits/stdc++.h>
using namespace std;
#define LL long long
char s[55];
int v[55];
bool dp[55][2];
bool ok(char a){
    if(a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
        return 1;
    else
        return 0;
}
bool jg1(int x){
    if(x<3) return false;
    for(int i=0;i<3;i++) if(v[x-i]>0) return false;
    return true;
}
bool jg2(int x){
    if(x<5) return false;
    for(int i=0;i<5;i++) if(v[x-i]<0) return false;
    return true;
}

int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int t,cas=1;
    cin>>t;
    while(t--){
        scanf("%s",s);
        printf("Case %d: ",cas++);
        int n=strlen(s);
        for(int i=0;i<n;i++){
            if(s[i]=='?') v[i+1]=0;
            else if(ok(s[i])) v[i+1]=-1;
            else v[i+1]=1;
        }
        int flag=1;
        for(int i=1;i<=n&&flag;i++) if(jg1(i)||jg2(i)) flag=0;
        if(flag) puts("GOOD");
        else {
            memset(dp,false,sizeof dp);
            dp[0][0]=1;
            dp[0][1]=1;
            for(int i=1;i<=n;i++){
                if(i<3){
                    if(v[i]<=0) dp[i][0]=1;
                    if(v[i]>=0) dp[i][1]=1;
                }
                else {
                    if(v[i]<=0){
                        if(v[i-1]>=0) dp[i][0]=(dp[i-1][1]||dp[i][0]);
                        if(v[i-1]<=0&&v[i-2]>=0) dp[i][0]=(dp[i-2][1]||dp[i][0]);
                    }
                    if(v[i]>=0){
                        if(v[i-1]<=0) dp[i][1]=(dp[i][1]||dp[i-1][0]);
                        if(v[i-1]>=0){
                            if(v[i-2]<=0) dp[i][1]=(dp[i][1]||dp[i-2][0]);
                            if(v[i-2]>=0){
                                if(v[i-3]<=0) dp[i][1]=(dp[i][1]||dp[i-3][0]);
                                if(v[i-3]>=0) {
                                    if(v[i-4]<=0) dp[i][1]=(dp[i][1]||dp[i-4][0]);
                                }
                            }
                        }
                    }
                }
            }
            if(dp[n][0]||dp[n][1]) puts("MIXED");
            else puts("BAD");
        }
    }
    return 0;
}
