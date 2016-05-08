
#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<cstdlib>
#include<cmath>
#define PI 2*asin(1.0)
#define LL long long
#define pb push_back
#define pa pair<int,int>
#define clr(a,b) memset(a,b,sizeof(a))
#define lson lr<<1,l,mid
#define rson lr<<1|1,mid+1,r
#define bug(x) printf("%d++++++++++++++++++++%d\n",x,x)
#define key_value ch[ch[root][1]][0]C:\Program Files\Git\bin
const LL  MOD = 1E9+7;
const LL N = 2e5+15;
const int maxn = 5e5+15;
const int letter = 130;
const int INF = 1e17;
const double pi=acos(-1.0);
const double eps=1e-10;
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,a[15];
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
LL lcm(LL a,LL b){
    return a*b/gcd(a,b);
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<m;i++) {
            scanf("%d",a+i);
            if(!a[i])i--,m--;
        }
        n--;
        LL sum=0,ans;
        int num;
        for(int i=1;i<(1<<m);i++){
            ans=1;
            num=0;
            for(int j=0;j<m;j++){
                if((1<<j)&i){
                    num++;
                    ans=lcm(ans,1ll*a[j]);
                }
            }
            if(num%2) sum+=1ll*n/ans;
            else sum-=1ll*n/ans;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
