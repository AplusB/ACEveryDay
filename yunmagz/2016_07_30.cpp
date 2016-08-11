//hdu5344 MZL's xor
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
const LL mod=1e9+7;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main()
{
    int t,n,m,z,l;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&z,&l);
        LL ans=0,a=0;
        for(int i=1;i<n;i++){
            a=(a*m+z)%l;
            ans^=(a+a);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//hdu5347 MZL's chemistry
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
const LL mod=1e9+7;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
double a[87]={0,13,24,5,9,8,11,14,13,17,21,5,7,5,8,10.4,10.3,12,15};
int main()
{
    a[35]=11.8,a[36]=13.9,a[53]=10.4,a[54]=12.1,a[85]=0,a[86]=10;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(a[n]>a[m]) puts("FIRST BIGGER");
        else puts("SECOND BIGGER");
    }
    return 0;
}
//hdu5348 MZL's endless loop
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
const LL mod=1e9+7;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int maxn = 100005;
struct node{
    int to, next, id;
}edge[maxn*6];
int head[maxn],du[2][maxn],sum[maxn];
int vis[maxn*6],ans[maxn*6],tot;

void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
    memset(du,0,sizeof(du));
    memset(sum,0,sizeof(sum));
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
}
void Add(int from,int to,int id){
    edge[tot].to=to;
    edge[tot].id=id;
    edge[tot].next=head[from];
    head[from]=tot++;
}
void dfs(int u,int y){
    for (int i=head[u];i!=-1;i=edge[i].next){
        if (vis[i]){
            head[u]=edge[i].next;
            continue;
        }
        int v=edge[i].to;
        if(v!=u&&du[y][v]<du[y^1][v]) continue;
        vis[i]=vis[i^1]=1;
        if(i&1) ans[i/2]=y^1;
        else ans[i/2]=y;
        du[y][u]++;
        du[y^1][v]++;
        head[u]=edge[i].next;
        dfs(v,y);
        break;
    }
}
int main()
{
    int t,n,m,u,v;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            Add(u,v,i);
            Add(v,u,i);
            sum[u]++;
            sum[v]++;
        }
        for(int i=1;i<=n;i++){
            while(du[0][i]+du[1][i]<sum[i]){
                if(du[0][i]<=du[1][i]) dfs(i,0);
                else dfs(i,1);
            }
        }
        for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
//hdu5349 MZL's simple problem
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
const LL mod=1e9+7;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
set<int >s;
int main()
{
    set<int>::iterator it;
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a;
        scanf("%d",&n);
        if(n==1){
            scanf("%d",&a);
            s.insert(a);
        }
        else if(n==2){
            if(s.empty()) continue;
            s.erase(s.begin());
        }
        else {
            if(s.empty()){
                puts("0");
                continue;
            }
            it=s.end();
            it--;
            printf("%d\n",*it);
        }
    }
    return 0;
}
//hdu5351  MZL's Border
import java.util.Scanner;
import java.math.BigInteger;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        BigInteger[] a=new BigInteger[1055];
        BigInteger[] b=new BigInteger[1055];
        a[1]=BigInteger.valueOf(1);
        a[2]=BigInteger.valueOf(2);
        b[1]=a[1].subtract(BigInteger.valueOf(1));
        b[2]=a[2].subtract(BigInteger.valueOf(1));
        for(int i=3;i<1050;++i)
        {
            a[i]=a[i-1].add(a[i-2]);
            b[i]=a[i].subtract(BigInteger.valueOf(1));
        }
        while(N>0)
        {
            N--;
            int n=sc.nextInt();
            BigInteger m = sc.nextBigInteger();
            for(int i=1;i<1050;++i)
            {
                if( m.compareTo(b[i+1])<0 && m.compareTo(b[i])>=0 )
                {

                     System.out.println((m.subtract(a[i-1])).mod(BigInteger.valueOf(258280327)));
                     break;
                }
            }
        }
    }
}
