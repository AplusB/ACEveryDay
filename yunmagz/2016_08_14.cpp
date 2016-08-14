//2016中国大学生程序设计竞赛 - 网络选拔赛
//1001 A water problem
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e7+5;

char s[N];
int main()
{
    int ca=1;
    while(~scanf("%s", s))
    {
        int n=strlen(s);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=10*ans+s[i]-'0';
            ans%=10001;
        }
        printf("Case #%d: ", ca++);
        if(ans==0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
//1002 Zhu and 772002
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1000000007;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int equ,var;
int a[1010][1010];
int x[1010];
int free_x[1010];
int free_num;

//返回值为-1表示无解，为0是唯一解，否则返回自由变元个数
int Gauss()
{
    int max_r, col, k;
    free_num = 0;
    for(k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for(int i = k+1 ; i < equ; i++)
            if(abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        if(a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col; //自由变元
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var+1; j++)
                swap(a[k][j],a[max_r][j]);
        }
        for(int i = k+1; i < equ;i++)
            if(a[i][col] != 0)
                for(int j = col; j < var+1;j++)
                    a[i][j] ^= a[k][j];
    }
    for(int i = k;i < equ;i++)
        if(a[i][col] != 0)
            return -1;
    if(k < var)return var-k;
    for(int i = var-1; i >= 0;i--)
    {
        x[i] = a[i][var];
        for(int j = i+1; j < var;j++)
            x[i] ^= (a[i][j] && x[j]);
    }
    return 0;
}
const int MAXN = 3000;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i = 2;i <= MAXN;i++)
    {
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0] && prime[j] <= MAXN/i;j++)
        {
            prime[prime[j]*i] = 1;
            if(i%prime[j] == 0)break;
        }
    }
}
LL b[310];
int main()
{
    getPrime();
    int t,n,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++) scanf("%I64d",&b[i]);
        equ = 305;
        var = n;
        for(int i = 0;i < 305;i++)
            for(int j = 0;j < n;j++)
            {
                int cnt = 0;
                while(b[j]%prime[i+1] == 0)
                {
                    cnt++;
                    b[j] /= prime[i+1];
                }
                a[i][j] = (cnt&1);
            }
        for(int i = 0;i < 305;i++)
            a[i][n] = 0;
        int ret = Gauss();
        printf("Case #%d:\n%d\n",cas++,((powmod(2,ret)-1)%mod+mod)%mod);
    }
    return 0;
}
//1004 Danganronpa
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
char s[100010];
int v[50];
priority_queue<int>q;
int main()
{
    int t,n,cas=1;
    scanf("%d",&t);
    while(t--){
            int a,b;
        while(!q.empty()) q.pop();
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            q.push(a);
            sum+=a;
        }
        int ans=0;
        while(q.size()>1){
            a=q.top();
            q.pop();
            b=q.top();
            q.pop();
            if(a>b){
                ans+=b*2;
                q.push(a-b);
            }
            else if(a<b){
                ans+=a*2;
                q.push(b-a);
            }
            else ans+=a*2;
        }
        if(q.size()>0){
            if(q.top()>1) ans++;
        }
        if(ans>sum/2) ans=sum/2;
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
//1007 Mountain
#include <bits/stdc++.h>
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
const double eps=1e-9;
const int inf=0x3f3f3f3f;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
char g[10][10];
LL ans;
int n,m;
LL cnt[550],dp[30][550];
int v[10][10];
int f[9][2]={1,1,1,0,1,-1,0,1,0,-1,-1,0,-1,-1,-1,1,0,0};
PII q[10];
bool jg(int i,int j){
    for(int k=0;k<8;k++)
        if(g[i+f[k][0]][j+f[k][1]]=='X') return 0;
    return 1;
}
int solve(){
    int k,top=0;
    memset(cnt,0,sizeof cnt);
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(g[i][j]=='X')
                q[++top]=mp(i,j);
    int tot=(1<<top);
    for(int s=0;s<tot;s++)
    {
        memset(v,0,sizeof v);
        for(int i=1;i<=top;i++)
            if(!(s&(1<<(i-1))))
                v[q[i].fi][q[i].se]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                for(k=0;k<9;k++)
                    if(v[i+f[k][0]][j+f[k][1]])
                        break;
                if(k==9)
                    cnt[s]++;
            }
    }
    dp[0][0]=1;
    for(int i=1;i<=n*m;i++)
        for(int s=0;s<tot;s++)
        {
            dp[i][s]=(dp[i][s]+dp[i-1][s]*max(cnt[s]-i+1,0LL))%mod;
            for(int j=1;j<=top;j++)
                if(s&(1<<(j-1)))
                    dp[i][s]=(dp[i][s]+dp[i-1][s^(1<<(j-1))])%mod;
        }
    return dp[n*m][tot-1];
}
void dfs(int i,int j,int s){
    if(j==m+1){
        dfs(i+1,1,s);
        return;
    }
    if(i==n+1){
        if(s&1) ans=((ans-solve())%mod+mod)%mod;
        else ans=(ans+solve())%mod;
        return;
    }
    dfs(i,j+1,s);
    if(jg(i,j) && g[i][j]=='.'){
        g[i][j]='X';
        dfs(i,j+1,s+1);
        g[i][j]='.';
    }
}
int main()
{
    int cas=1;
    while(~scanf("%d%d",&n,&m)){
        memset(g,0,sizeof g);
        for(int i=1;i<=n;i++) scanf("%s",g[i]+1);
        int flag=1;
        ans=0;
        for(int i=1;i<=n&&flag;i++) for(int j=1;j<=m&&flag;j++) if(g[i][j]=='X'&& !jg(i,j)) flag=0;
        if(flag) dfs(1,1,0);
        printf("Case #%d: %d\n",cas++,(int)ans);
    }
    return 0;
}
//1011 Lweb and String
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
char s[100010];
int v[50];
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        memset(v,-1,sizeof v);
        scanf("%s",s);
        int n=strlen(s);
        for(int i=1;i<=n;i++){
            if(v[s[i-1]-'a']==-1){
                v[s[i-1]-'a']=1;
            cnt++;
            }
        }
        printf("Case #%d: %d\n",cas++,cnt);
    }
    return 0;
}

