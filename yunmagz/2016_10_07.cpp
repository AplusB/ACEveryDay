//poj 3734 Blocks
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <math.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
//typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e4+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int v[5];
int main()
{
    LL n;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<(powmod(2,n-1)+powmod(2,2*(n-1)))%mod<<endl;
    }
    return 0;
}
//poj 3735 Training little cats
#include <cstdio>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <set>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

#define Matr 110 //矩阵大小,注意能小就小   矩阵从1开始   所以Matr 要+1   最大可以100
#define ll __int64
struct mat//矩阵结构体，a表示内容，size大小 矩阵从1开始   但size不用加一
{
    ll a[Matr][Matr];
    mat()//构造函数
    {
        memset(a,0,sizeof(a));
    }
};
int Size=  0 ;

mat multi(mat m1,mat m2)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算的优化
{
    mat ans=mat();
    for(int i=1;i<=Size;i++)
        for(int j=1;j<=Size;j++)
            if(m1.a[i][j])//稀疏矩阵优化
                for(int k=1;k<=Size;k++)
                    ans.a[i][k]=(ans.a[i][k]+m1.a[i][j]*m2.a[j][k]); //i行k列第j项
    return ans;
}

mat quickmulti(mat m,ll n)//二分快速幂
{
    mat ans=mat();
    int i;
    for(i=1;i<=Size;i++)ans.a[i][i]=1;
    while(n)
    {
        if(n&1)ans=multi(m,ans);//奇乘偶子乘 挺好记的.
        m=multi(m,m);
        n>>=1;
    }
    return ans;
}

void print(mat m)//输出矩阵信息，debug用
{
    int i,j;
    printf("%d\n",Size);
    for(i=1;i<=Size;i++)
    {
        for(j=1;j<=Size;j++)
			printf("%d ",m.a[i][j]);
        printf("\n");
    }
}
char s[5];
int main()
{
    int n,m,k,x,y;
    while(cin>>n>>m>>k){
        if(!n && !m && !k) break;
        mat gz=mat(),chu=mat();//构造矩阵  初始矩阵
        Size=n+1;
        chu.a[1][1]=1;
        for(int i=1;i<=n+1;i++) gz.a[i][i]=1;
        for(int i=0;i<k;i++){
            cin>>s;
            if(s[0]=='s'){
                cin>>x>>y;
                for(int i=1;i<=n+1;i++) swap(gz.a[i][x+1],gz.a[i][y+1]);
            }
            else if(s[0]=='e'){
                cin>>x;
                for(int i=1;i<=n+1;i++) gz.a[i][x+1]=0;
            }
            else {
                cin>>x;
                gz.a[1][x+1]++;
            }
        }
        chu=multi(chu,quickmulti(gz,m));
        for(int i=2;i<=n+1;i++)
            printf("%I64d%c",chu.a[1][i],i>n?'\n':' ');
    }
    return 0;
}
//poj 3737 UmBasketella
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair< PI, int> PII;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
#define Key_value ch[ch[root][1]][0]
const int MAXN = 100010;
const int MAXM = 10100;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
inline int read()
{
    int s=0;
    char ch=getchar();
    for(; ch<'0'||ch>'9'; ch=getchar());
    for(; ch>='0'&&ch<='9'; ch=getchar())s=s*10+ch-'0';
    return s;
}
int main()
{
    double s;
    while(cin>>s)
    {
        double r=s/pi;
        r=sqrt(r);
        r/=2.0;

        double h=s/pi/r;
        h-=r;
        h*=h;
        h-=r*r;
        h=sqrt(h);

        double v=pi*r*r*h/3.0;

        printf("%.2f\n",v);
        printf("%.2f\n",h);
        printf("%.2f\n",r);
    }
    return 0;
}
//poj 3597 Polygon Division
#include <cstdio>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <set>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
unsigned long long a[5005],b[5005];
int main()
{
    a[2]=a[3]=1;
    b[3]=1;
    for(int n=4;n<=5000;n++){
        for(int i=2;i<=n-1;i++) b[n]+=a[i]*a[n-i+1];
        a[n]=b[n];
        for(int i=2;i<=n-2;i++) a[n]+=a[i]*b[n-i+1];
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%llu\n",a[n]);
    }
    return 0;
}
//poj 3600 Subimage Recognition
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[25][25],b[25][25];
int A[25],B[25];
char s[25];
int main()
{
    int r,c,R,C,m;
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++){
        scanf("%s",s);
        for(int j=0;j<c;j++){
            a[i][j]=s[j]-'0';
        }
    }

    for(int j=0;j<c;j++){
        A[j]=0;
        for(int k=0;k<r;k++)
            A[j]+=(1<<k)*a[k][j];
    }
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++){
        scanf("%s",s);
        for(int j=0;j<C;j++){
            b[i][j]=s[j]-'0';
        }
    }
    for(int i=0;i<(1<<R);i++){
        int cnt=0;
        for(int j=0;j<R;j++)
            if(i&(1<<j)) cnt++;
        if(cnt!=r) continue;
        for(int j=0;j<C;j++){
            B[j]=0;
            m=0;
            for(int k=0;k<R;k++)
                if(i&(1<<k)){
                    B[j]+=(1<<m)*b[k][j];
                    m++;
                }
        }
        for(int j=0,k=0;j<c&&k<C;j++){
            while(A[j]!=B[k]&&k<C){
                k++;
            }
            if(j==c-1&&k<C) return 0*puts("Yes");
        }
    }
    puts("No");
    return 0;
}
