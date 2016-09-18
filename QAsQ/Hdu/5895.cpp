#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <ctime>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#define LL long long
#define Pr pair<int,int>
#define fread(ch) freopen(ch,"r",stdin)
#define fwrite(ch) freopen(ch,"w",stdout)

using namespace std;
const int INF = 0x3f3f3f3f;
const int msz = 10000;
const double eps = 1e-8;
const int maxn = 112345;

LL MOD;

const int N=4;

struct martix
{
    LL num[N][N];
    void tz()
    {
        memset(num,0,sizeof(num));
    }
    void to()
    {
        this->tz();
        for(int i=0; i<N; i++) num[i][i]=1;
    }
};
martix operator * (const martix & A,const martix & B)
{
    martix C;
    C.tz();
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<N; k++)
                ( C.num[i][j] += A.num[i][k]*B.num[k][j] % MOD ) %=MOD ;
    return C;
}
martix pmod(martix x,LL n)
{
    martix res;
    res.to();
    while(n>0)
    {
        if(n & 1) res=res*x;
        x = x*x;
        n >>= 1;
    }
    return res;
}

LL g(LL tim,LL M)
{
    martix q;
    q.num[0][0] = 0; q.num[0][1] = 1; q.num[0][2] = 0; q.num[0][3] = 0;
    q.num[1][0] = 1; q.num[1][1] = 4; q.num[1][2] = 4; q.num[1][3] = 0;
    q.num[2][0] = 0; q.num[2][1] = 2; q.num[2][2] = 1; q.num[2][3] = 0;
    q.num[3][0] = 0; q.num[3][1] = 1; q.num[3][2] = 0; q.num[3][3] = 1;
    MOD = M;
    q = pmod(q,tim+1);
    return q.num[3][0];
}

LL phi(LL n)
{
    LL ans = n;
    for(int i=2;i*i<=n;i++){
        if(n % i == 0){
            ans -= ans / i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1) ans -= ans / n;
    return ans;
}

LL pmod(LL x,LL n,LL mod){
    LL ret = 1;
    while(n){
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n>>=1;
    }
    return ret;
}

int main()
{
    LL n,x,y,s;
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%I64d %I64d %I64d %I64d",&n,&y,&x,&s))
    {
        s++;
        LL ph = phi(s);
        LL tv = g(n*y,ph);
        printf("%I64d\n",pmod(x,tv+ph,s));
    }
    return 0;
}
