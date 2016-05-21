//百毒之星
//01
#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
LL pow_mod(LL x,LL b,LL mod){
    LL res = 1;
    while(b){
        if(b&1LL) res=(res*x)%mod;
        x=(x*x)%mod;
        b>>=1LL;
    }
    return res;
}
LL solve(LL m, LL mod){
    if(m==1) return 1%mod;
    if(m%2==0){
        LL ans=solve(m>>1,mod);
        return (ans*pow_mod(10,m>>1,mod)%mod+ans)%mod;
    }
    else return (solve(m-1,mod)*10+1)%mod;
}
int main()
{
    int t,cas=1;
    cin>>t;
    while(t--){
        int x, c, k;
        LL m;
        cin>>x>>m>>k>>c;
        if(solve(m, k)*x%k==c) printf("Case #%d:\nYes\n",cas++);
        else printf("Case #%d:\nNo\n",cas++);
    }
    return 0;
}
//02
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define LL long long
const int inf=0x3f3f3f3f;
LL dp[(1<<16)+10][20],a[20],p[20],v[20];
int main()
{
    int t,n,cas=1;
    cin>>t;
    while(t--){
        cin>>n;
        memset(v,-1,sizeof v);
        for(int i=0;i<n;i++){
            cin>>a[i]>>p[i];
            if(p[i]!=-1) v[p[i]]=i;
        }
        int N=(1<<n);
        for(int s=0;s<N;s++){
            for(int i=0;i<n;i++)
                dp[s][i]=(1<<31);
        }
        if(n==1){
            printf("Case #%d:\n0\n",cas++);
            continue;
        }
        if(v[0]==-1){
            for(int i=0;i<n;i++){
                dp[(1<<i)][i]=0;
            }
        }
        else dp[(1<<v[0])][v[0]]=0;
        for(int s=1;s<N;s++){
            int k=0;
            for(int i=0;i<n;i++)
                if(s&(1<<i)) k++;
            if(v[k]!=-1){
                for(int i=0;i<n;i++){
                    if(s&(1<<i)){
                        dp[s|(1<<v[k])][v[k]]=max(dp[s|(1<<v[k])][v[k]],dp[s][i]+a[i]*a[v[k]]);
                    }
                }
            }
            else {
                for(int i=0;i<n;i++){
                    if(s&(1<<i)){
                        for(int j=0;j<n;j++){
                            if(!(s&(1<<j)) && p[j]==-1)
                                dp[s|(1<<j)][j]=max(dp[s|(1<<j)][j],dp[s][i]+a[j]*a[i]);
                        }
                    }
                }
            }
        }
        LL ans=(1<<31);
        for(int i=0;i<n;i++){
            ans=max(ans,dp[N-1][i]);
        }
        printf("Case #%d:\n%I64d\n",cas++,ans);
    }
    return 0;
}
//05
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define LL long long
const int N=1024;
LL a[N];
LL b[N];
LL solve(LL L)
{
    if(L<=0) return 0;
    if(L==1) return 1;
    a[1]=1;
    b[1]=0;
    for(int i=2;;i++){
        b[i]=a[i-1]+b[i-1];
        a[i]=b[i]+1;
        if(a[i]+b[i]>=L){
            LL las=a[i-1]+b[i-1];
            LL duo=L-(las+1);
            return a[i-1]+1+(b[i-1]-((las-duo)-solve(las-duo)));
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        LL l,r;
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",solve(r)-solve(l-1));
    }
    return 0;
}
//06
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#include <vector>
#include <map>
#include <queue>
#define N 100010
#define mod 1000000007
vector<int> V[N];
int in[N];
int ans[N];
int main()
{
   // priority_queue<int,vector<int>,greater<int> >Q;
   priority_queue<int>Q;
    int T;
    int n,m;
    int a,b;
    int i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            V[i].clear();
            in[i]=0;
        }
        while(m--)
        {
           scanf("%d %d",&b,&a);
           V[b].push_back(a);
           in[a]++;
        }
        for(i=1;i<=n;i++)
            if(in[i]==0)
               Q.push(i);
        int id=0;
        while(!Q.empty())
        {
            a=Q.top();
            Q.pop();
           ans[id]=a;
           id++;
            for(i=0;i<V[a].size();i++){
                b=V[a][i];
                in[b]--;
                if(in[b]==0)
                    Q.push(b);

            }
        }
        int mn=111111;
        LL sum=0;
//        for(i=id-1;i>=0;i--)
//            printf("%d%c",ans[i],i==0?'\n':' ');
        for(i=0;i<id;i++){
            mn=min(mn,ans[i]);
            sum+=mn;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
