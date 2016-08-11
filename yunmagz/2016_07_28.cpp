//2016 Multi-University Training Contest 4
//1001 Another Meaning
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
const LL mod=1000000007;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
/*
* next[]的含义： x[i-next[i]...i-1]=x[0...next[i]-1]
* next[i]为满足x[i-z...i-1]=x[0...z-1]的最大z值（就是x的自身匹配）
*/
int cnt[100010];
void kmp_pre(char x[],int m,int nxt[])
{
    int i,j;
    j=nxt[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j && x[i]!=x[j])j=nxt[j];
        nxt[++i]=++j;
    }
}
/*
* kmpNext[]的意思： next'[i]=next[next[...[next[i]]]] (直到next'[i]<0或者
x[next'[i]]!=x[i])
* 这样的预处理可以快一些
*/
void preKMP(char x[],int m,int kmpNext[])
{
    int i,j;
    j=kmpNext[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j && x[i]!=x[j])j=kmpNext[j];
        if(x[++i]==x[++j])kmpNext[i]=kmpNext[j];
        else kmpNext[i]=j;
    }
}
/*
* 返回x在y中出现的次数，可以重叠
*/
int nxt[10010];
int KMP_Count(char x[],int m,char y[],int n)
{
    //x是模式串， y是主串
    int i,j;
    int ans=0;
//preKMP(x,m,next);
    kmp_pre(x,m,nxt);
    i=j=0;
    while(i<n)
    {
        while(-1!=j && y[i]!=x[j])j=nxt[j];
        i++;
        j++;
        if(j>=m)
        {
            ans++;
            j=nxt[j];
        }
        cnt[i]=ans;
    }
    return ans;
}
char s1[100010],s2[100010];
LL k[100010],fk[100010];
int main()
{
    int t,cas=1,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",s1,s2);
        n=strlen(s1);
        m=strlen(s2);
        KMP_Count(s2,m,s1,n);
        LL sum=1;
        fk[0]=0;
        for(int i=1;i<=n;i++){
            fk[i]=fk[i-1];
            if(cnt[i]>cnt[i-1]){
//                ans[i]*=2;
//                sum+=ans[i];
                fk[i]+=fk[i-m]+1;
                fk[i]%=mod;
            }
//            cout<<fk[i]<<endl;
        }

//        for(int i=0;i<=n;i++) cout<<i<<" "<<cnt[i]<<endl;
        printf("Case #%d: %lld\n",cas++,(fk[n]+1)%mod);
    }
    return 0;
}
//1010  The All-purpose Zero
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
const LL mod=1000000007;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int MAXN=500010;
int a[MAXN],b[MAXN];
//用二分查找的方法找到一个位置，使得num>b[i-1] 并且num<b[i],并用num代替b[i]
int Search(int num,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num>b[mid]) low=mid+1;
        else high=mid-1;
    }
    return low;
}
int DP(int n)
{
    int i,len,pos;
    b[1]=a[1];
    len=1;
    for(i=2; i<=n; i++)
    {
        if(a[i]==0){
            len=len+1;
            for(int j=len;j>=2;j--) b[j]=b[j-1]+1;
            b[1]=0;
//            b[len+1]=b[len]+1;
//            for(int j=len;j>=0;j--) {
//                b[j+1]=min(b[j+1],b[j]+1);
//                if(b[j]+1==j) break;
//            }
//            len=len+1;
        }
        else if(a[i]>b[len])//如果a[i]比b[]数组中最大还大直接插入到后面即可
        {
            len=len+1;
            b[len]=a[i];
        }
        else//用二分的方法在b[]数组中找出第一个比a[i]大的位置并且让a[i]替代这个位置
        {
            pos=lower_bound(b,b+len+1,a[i])-b;
            //pos=Search(a[i],1,len);
            b[pos]=a[i];
        }
    }
    return len;
}
int main()
{
    int t,cas=1,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("Case #%d: %d\n",cas++,DP(n));
    }
    return 0;
}
//1011  Where Amazing Happens
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int eps=1e-9;
const int pi=acos(-1.0);
const int mod=1e6+7;
const LL INF=0x3f3f3f3f;

string ans[]= {"Cleveland Cavaliers",
               "Golden State Warriors",
               "San Antonio Spurs",
               "Miami Heat",
               "Miami Heat",
               "Dallas Mavericks",
               "L.A. Lakers",
               "L.A. Lakers",
               "Boston Celtics",
               "San Antonio Spurs",
               "Miami Heat",
               "San Antonio Spurs",
               "Detroit Pistons",
               "San Antonio Spurs",
               "L.A. Lakers",
               "L.A. Lakers",
               "L.A. Lakers",
               "San Antonio Spurs",
               "Chicago Bulls",
               "Chicago Bulls",
               "Chicago Bulls",
               "Houston Rockets",
               "Houston Rockets",
               "Chicago Bulls",
               "Chicago Bulls",
               "Chicago Bulls",
               "Detroit Pistons",
               "Detroit Pistons",
               "L.A. Lakers",
               "L.A. Lakers",
               "Boston Celtics",
               "L.A. Lakers",
               "Boston Celtics",
               "Philadelphia 76ers",
               "L.A. Lakers",
               "Boston Celtics",
               "L.A. Lakers",
               "Seattle Sonics",
               "Washington Bullets",
               "Portland Trail Blazers",
               "Boston Celtics",
               "Golden State Warriors",
               "Boston Celtics",
               "New York Knicks",
               "L.A. Lakers",
               "Milwaukee Bucks",
               "New York Knicks",
               "Boston Celtics",
               "Boston Celtics",
               "Philadelphia 76ers",
               "Boston Celtics",
               "Boston Celtics",
               "Boston Celtics",
               "Boston Celtics",
               "Boston Celtics",
               "Boston Celtics",
               "Boston Celtics",
               "Boston Celtics",
               "St. Louis Hawks",
               "Boston Celtics",
               "Philadelphia Warriors",
               "Syracuse Nats",
               "Minneapolis Lakers",
               "Minneapolis Lakers",
               "Minneapolis Lakers",
               "Rochester Royals",
               "Minneapolis Lakers",
               "Minneapolis Lakers",
               "Baltimore Bullets",
               "Philadelphia Warriors"
              };



int main()
{
    string tmp;
    int t;
    cin>>t;
    getchar();
    int casee=1;
    while(t--)
    {
        //cin>>tmp;
        getline(cin,tmp);
        int cnt=0;
        printf("Case #%d: ",casee++);

        for(int i=0; i<70; ++i)
        {
            if(ans[i]==tmp)
                cnt++;
            //cout<<ans[i]<<endl;
            //cout<<i<<endl;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
//1012  Bubble Sort
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair< PI, int> PII;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
#define mp make_pair
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int a[100000+10];
int L[100010],R[100010];
int tree[100010<<2];

inline void push(int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}

void build(int l, int r, int rt)
{
    if(l == r)
    {
        tree[rt]=0;
        return ;
    }
    int m = ( l + r )>>1;
    build(lson);
    build(rson);
    push(rt);
}

void updata(int p, int add, int l, int r, int rt)
{
    if( l == r )
    {
        tree[rt] = add;
        return ;
    }
    int m = ( l + r ) >> 1;
    if(p <= m)
        updata(p, add, lson);
    else
        updata(p, add, rson);

    push(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if( L <= l && r <= R )
    {
        return tree[rt];
    }
    int m = ( l + r ) >> 1;
    int ans=0;
    if(L<=m)
        ans+=query(L,R,lson);
    if(R>m)
        ans+=query(L,R,rson);

    return ans;
}



int main()
{
    int t,cas=1;
    scanf("%d",&t);
    int n;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d",&a[i]);
            L[a[i]]=i;
        }
        build(1,n,1);
        for(int i=n; i>=1; i--)
        {

            int tmp=query(1,a[i],1,n,1);
            R[a[i]]=max(L[a[i]]+tmp,a[i]);
            L[a[i]]=min(L[a[i]],a[i]);
            updata(a[i],1,1,n,1);
        }
        printf("Case #%d:",cas++);
        for(int i=1;i<=n;i++) printf(" %d",R[i]-L[i]);
        puts("");

    }


    return 0;
}
