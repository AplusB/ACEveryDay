//GCJ2016 round2
//A
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int s[3][15],p[3][15],r[3][15];
string solve(string s){
    int n=s.size();
    string ss;
    for(int k=4;k<=n;k<<=1){
        ss="";
        for(int i=0;i<n;i+=k){
            string x=s.substr(i,k/2);
            string y=s.substr(i+k/2,k/2);
            if(x<y) ss+=(x+y);
            else ss+=(y+x);
        }
        s=ss;
    }
    return s;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    string str[3][15],ps="PS",rs="RS",rp="PR";
    memset(s,0,sizeof s);
    memset(p,0,sizeof p);
    memset(r,0,sizeof r);
    str[0][0]="R";
    str[1][0]="P";
    str[2][0]="S";
    for(int g=0;g<3;g++){
        for(int i=1;i<=12;i++){
            str[g][i]="";
            for(int j=0;j<str[g][i-1].size();j++){
                if(str[g][i-1][j]=='S') str[g][i]+=ps,s[g][i-1]++;
                if(str[g][i-1][j]=='R') str[g][i]+=rs,r[g][i-1]++;
                if(str[g][i-1][j]=='P') str[g][i]+=rp,p[g][i-1]++;
            }
            str[g][i]=solve(str[g][i]);
        }
        for(int j=0;j<str[g][12].size();j++){
            if(str[g][12][j]=='S') s[g][12]++;
            if(str[g][12][j]=='R') r[g][12]++;
            if(str[g][12][j]=='P') p[g][12]++;
        }
    }
    int t,cas=1;
    cin>>t;
    while(t--){
        int n,R,P,S;
        cin>>n>>R>>P>>S;
        printf("Case #%d: ",cas++);
        int flag=1;
        for(int i=0;i<3;i++){
            if(R==r[i][n]&&S==s[i][n]&&P==p[i][n]){
                cout<<str[i][n]<<endl;
                flag=0;
                break;
            }
        }
        if(flag) puts("IMPOSSIBLE");
    }
    return 0;
}
//B
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
double p[220];
vector<double>A;
int n,k;
double dp[220][220];
double solve(int pre,int m){
    A.clear();
    for (int i = 0 ; i < pre ; ++i) A.PB(p[i]);
    int last = m - pre;
    for (int j = n - 1 ; last ; --j , --last) A.PB(p[j]);
    memset(dp,0,sizeof dp);
    dp[1][1] = A[0];
    dp[1][0] = 1. - A[0];
    for (int i = 1 ; i < m ; ++i){
        for (int j = 0 ; j <= i ; ++j){
            dp[i + 1][j + 1] += dp[i][j] * A[i];
            dp[i + 1][j] += dp[i][j] * (1. - A[i]);
        }
    }
    return dp[m][m / 2];
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>p[i];
        sort(p,p+n);
        double ans=0;
        for(int i=0;i<=k;i++){
            ans=max(ans,solve(i,k));
        }
        printf("Case #%d: %.6lf\n",cas++,ans);
    }
    return 0;
}
//百毒之星2016 round3
//02
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int mod = 1e9+9;
LL dp[20][(1<<14)+10],g[(1<<14)+10];
int tmp[(1<<14)+10][20],id[(1<<14)+10],mb[(1<<14)+10];
int gg[(1<<14)+10],n,m,K,tot,t,cas;
bool a[20][20];
char mp[30][30];
LL pow_mod(LL x,LL b){
	LL res = 1;
	while(b){
		if(b&1LL) res = (res*x)%mod;
		x =(x*x)%mod;
		b>>=1LL;
	}
	return res;
}
void init(){
    memset(dp,0,sizeof dp);
    memset(g,0,sizeof g);
    memset(a,0,sizeof a);
    memset(tmp,0,sizeof tmp);
}
LL fuck(){
    int mx=n-K+1;
    for (int i=0; i<n; i++) id[1<<i]=i;
    for (int i=0; i<n; i++) g[1<<i]=1;
    for (int S=0; S<(1<<n); S++){
        if (g[S]>mx) continue;
        int x=S&(-S),i=id[x];
        for (int s=(S-1)&S; s; s=(s-1)&S)
            if (!(s&x) && mb[s]>mb[S-s]) g[S]=(g[S]+g[S-s]*g[s]%mod*(tmp[s][i]-1))%mod;
        dp[1][S]=g[S];
    }
    for (int i=1; i<K; i++){
        for (int S=0; S<(1<<n); S++){
            if (gg[S]>mx) continue;
            int bg=(1<<n)-1-S;
            for (int s=bg; s; s=(s-1)&bg)
                dp[i+1][S|s]=(dp[i+1][S|s]+dp[i][s]*g[S])%mod;
        }
    }
    LL ans=dp[K][(1<<n)-1];
    ans=ans*(1<<tot)%mod;
    LL yy=1;
    for (int i=1; i<=K; i++) yy=yy*i%mod;
    ans=ans*pow_mod(yy,mod-2)%mod;
    return ans;
}
int main()
{
    gg[0]=0;
    for(int i=1; i<(1<<14); i++) gg[i]=gg[i>>1]+(i&1);
    for(int i=1; i<(1<<14); i++)
        for(int j=13; j>=0; j--)
            if(i&(1<<j)){
                mb[i]=j;
                break;
            }
    cin>>t;
    for(cas=1;cas<=t;cas++){
        cin>>n>>m>>K;
        init();
        tot=0;
        for (int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            a[x][y]=a[y][x]=1;
            if (x==y) tot++;
        }
        for (int s=0; s<(1<<n); s++){
            for (int i=0; i<n; i++){
                tmp[s][i]=1;
                for (int j=0; j<n; j++)
                    if ((s&(1<<j)) && a[i][j]) tmp[s][i]<<=1;
            }
        }
        printf("Case #%d:\n%I64d\n",cas,fuck());
    }
    return 0;
}
