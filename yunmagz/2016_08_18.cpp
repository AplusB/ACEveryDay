//2016 Multi-University Training Contest 10
//1001	Median
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
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[100010];
int main()
{
    int t,n,m,l1,l2,r1,r2;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        while(m--){
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            if(l1>l2||(l1==l2&&r1<r2)){
                swap(l1,l2);
                swap(r1,r2);
            }
            int sum=r1-l1+r2-l2+2,mid;
            if(r1<l2){
                if(sum&1){
                    mid=sum/2+1;
                    if(mid+l1-1<=r1) printf("%d.0\n",a[mid+l1-1]);
                    else printf("%d.0\n",a[mid-(r1-l1+1)+l2-1]);
                }
                else {
                    mid=sum/2;
                    int a1,a2;
                    if(mid+l1-1<=r1) a1=mid+l1-1;
                    else a1=mid-(r1-l1+1)+l2-1;
                    mid++;
                    if(mid+l1-1<=r1) a2=mid+l1-1;
                    else a2=mid-(r1-l1+1)+l2-1;
                    printf("%.1lf\n",a[a1]/2.0+a[a2]/2.0);
                }
            }
            else if(r1<r2){
                if(sum&1){
                    mid=sum/2+1;
                    if(mid<l2-l1+1) printf("%d.0\n",a[mid+l1-1]);
                    else if(mid>r1-l1+1+r1-l2+1) printf("%d.0\n",a[mid-(r1-l1+1+r1-l2+1)+r1]);
                    else printf("%d.0\n",a[(mid+1-l2+l1)/2+l2-1]);
                }
                else {
                    mid=sum/2;
                    int a1,a2;
                    if(mid<l2-l1+1) a1=mid+l1-1;
                    else if(mid>r1-l1+1+r1-l2+1) a1=mid-(r1-l1+1+r1-l2+1)+r1;
                    else a1=(mid+1-l2+l1)/2+l2-1;
                    mid++;
                    if(mid<l2-l1+1) a2=mid+l1-1;
                    else if(mid>r1-l1+1+r1-l2+1) a2=mid-(r1-l1+1+r1-l2+1)+r1;
                    else a2=(mid+1-l2+l1)/2+l2-1;
                    printf("%.1lf\n",a[a1]/2.0+a[a2]/2.0);
                }
            }
            else {
                if(sum&1){
                    mid=sum/2+1;
                    if(mid<l2-l1+1) printf("%d.0\n",a[mid+l1-1]);
                    else if(mid>l2-l1+(r2-l2+1)*2) printf("%d.0\n",a[mid-(l2-l1+(r2-l2+1)*2)+r2]);
                    else printf("%d.0\n",a[(mid+1-(l2-l1))/2+l2-1]);
                }
                else {
                    mid=sum/2;
                    int a1,a2;
                    if(mid<l2-l1+1) a1=mid+l1-1;
                    else if(mid>l2-l1+(r2-l2+1)*2) a1=mid-(l2-l1+(r2-l2+1)*2)+r2;
                    else a1=(mid+1-(l2-l1))/2+l2-1;
                    mid++;
                    if(mid<l2-l1+1) a2=mid+l1-1;
                    else if(mid>l2-l1+(r2-l2+1)*2) a2=mid-(l2-l1+(r2-l2+1)*2)+r2;
                    else a2=(mid+1-(l2-l1))/2+l2-1;
                    printf("%.1lf\n",a[a1]/2.0+a[a2]/2.0);
                }
            }
        }
    }
    return 0;
}
//1002	Hard problem
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
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[100010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        double l;
        scanf("%lf",&l);
        printf("%.2lf\n",((4-pi)*3/4*l*l-(3*l*l-2*l*l*sin(acos(0.75))-(pi/4-acos(5*sqrt(2)/8))/(2*pi)*pi*4*l*l*2-(acos(0.75)+acos(5*sqrt(2)/8)-pi/4)/pi*pi*l*l))/2);
    }
    return 0;
}
//1006	Counting Intersections
#include <bits/stdc++.h>
using namespace std;

struct Line
{
    int x1, x2;
    bool vis; //竖线：false  横线：true
};
int x1[100010], x2[100010], y1[100010], y2[100010];
long long bit[200010];
vector<Line> l[200010];
void add(int i, int x, int n)
{
    while(i <= n)
    {
        bit[i] += x;
        i += i & -i;
    }
}
int sum(int i)
{
    int ret = 0;
    while(i)
    {
        ret += bit[i];
        i -= i & -i;
    }
    return ret;
}
int Com(int *arr1, int *arr2, int n)
{
    vector<int> xs;
    xs.reserve(2 * n);
    for(int i = 0; i < n; ++i)
    {
        xs.push_back(arr1[i]);
        xs.push_back(arr2[i]);
    }
    sort(xs.begin(), xs.end());
    auto e = unique(xs.begin(), xs.end());
    int ret = 0;
    for(int i = 0; i < n; ++i)
    {
        arr1[i] = lower_bound(xs.begin(), e, arr1[i]) - xs.begin() + 1;
        arr2[i] = lower_bound(xs.begin(), e, arr2[i]) - xs.begin() + 1;
        ret = max(max(arr1[i], arr2[i]), ret);
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(bit, 0, sizeof(bit));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        int x, y;
        x = Com(x1, x2, n);
        y = Com(y1, y2, n);
        for(int i = 1; i <= y; ++i)
            l[i].clear();
        for(int i = 0; i < n; ++i)
        {
            if(x1[i] == x2[i])
            {
                l[ min(y1[i], y2[i]) ].push_back(Line{x1[i], 1, false});
                l[ max(y1[i], y2[i]) ].push_back(Line{x1[i], -1, false});
            }
            else
                l[ y1[i] ].push_back(Line{min(x1[i], x2[i]), max(x1[i], x2[i]), true});
        }
        long long ans = 0;
        for(int i = 1; i <= y; ++i)
        {
            if(l[i].empty())
                continue;
            for(vector<Line>::size_type j = 0; j < l[i].size(); ++j)
            {
                if(l[i][j].vis == false && l[i][j].x2 == 1)
                    add(l[i][j].x1, l[i][j].x2, x);
            }
            for(vector<Line>::size_type j = 0; j < l[i].size(); ++j)
            {
                if(l[i][j].vis)
                    ans += sum(l[i][j].x2) - sum(l[i][j].x1 - 1);
            }
            for(vector<Line>::size_type j = 0; j < l[i].size(); ++j)
            {
                if(l[i][j].vis == false && l[i][j].x2 == -1)
                    add(l[i][j].x1, l[i][j].x2, x);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
//1011	Water problem
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
const double eps=1e-8;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[1010]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6};
int main()
{
    int t,n;
    a[30]=6,a[40]=5,a[50]=5,a[60]=5,a[70]=7,a[80]=6,a[90]=6,a[100]=10;
    for(int i=20;i<100;i+=10)
        for(int j=i+1;j<i+10;j++)
            a[j]=a[i]+a[j-i];
    for(int i=100;i<1000;i+=100){
        a[i]=a[i/100]+7;
        for(int j=i+1;j<i+100;j++)
            a[j]=a[i]+a[j-i]+3;
    }
    a[1000]=11;
    for(int i=2;i<=1000;i++)
        a[i]+=a[i-1];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
