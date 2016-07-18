//CodeForces 687C【DP】
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;


const int N=2550;

int a[510];
vector<int>d;
bool dp[N][N];
int k,n;

int main()
{
    int i,j,h;
    cin>>n>>k;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(i=0;i<n;i++){
        for(j=k;j>=a[i];j--){
            for(h=0;h<=k-a[i];h++){
                if(dp[j-a[i]][h])
                    dp[j][h]=dp[j][h+a[i]]=1;
            }
        }
    }

    for(i=0;i<=k;i++){
        if(dp[k][i])
            d.push_back(i);
    }
    sort(d.begin(),d.end());
    int len=d.size();
    printf("%d\n",len);
    for(i=0;i<len;i++){
        if(i) printf(" ");
        printf("%d",d[i]);
    }
    puts("");
    return 0;
}
