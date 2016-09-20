//poj3071 - Football
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <Stack>
#include <set>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <time.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=772002;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
double dp[10][1005],p[1005][1005];
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=-1){
        int t=1<<n;
        for(int i=0;i<t;i++)
            for(int j=0;j<t;j++)
                scanf("%lf",&p[i][j]);
        memset(dp,0,sizeof dp);
        for(int i=0;i<t;i++) dp[0][i]=1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<t;j++)
                for(int k=0;k<t;k++)
                    if((j>>i)==(k>>i)&&(j>>(i-1))!=(k>>(i-1)))
                        dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
        double ans=0;
        int res=0;
        for(int i=0;i<t;i++)
            if(dp[n][i]>ans){
                ans=dp[n][i];
                res=i+1;
            }
        printf("%d\n",res);
    }
    return 0;
}
//poj2128 Highways
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <Stack>
#include <set>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <time.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=772002;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[50010];
int main()
{
    int n;
    cin>>n;
    a[0]=0;
    int mn=2e9,mni=0;
    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=2;i<n-1;i++){
        if(a[i]-a[i-1]<mn){
            mn=a[i]-a[i-1];
            mni=i;
        }
    }
    if(n<4) puts("0");
    else printf("%d\n%d 1 %d %d\n",mn+a[n-1],mni+1,n,mni);
    return 0;
}
//poj2286 The Rotation Game
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <Stack>
#include <set>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <time.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=772002;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[50010];
int main()
{
    int n;
    cin>>n;
    a[0]=0;
    int mn=2e9,mni=0;
    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=2;i<n-1;i++){
        if(a[i]-a[i-1]<mn){
            mn=a[i]-a[i-1];
            mni=i;
        }
    }
    if(n<4) puts("0");
    else printf("%d\n%d 1 %d %d\n",mn+a[n-1],mni+1,n,mni);
    return 0;
}
