//hdu5003
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
double a[100];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        double m=1.0;
        for(int i=1;i<=n;i++)
            scanf("%lf",&a[i]);
        sort(a+1,a+n+1);
        double ans=0;
        for(int i=n;i>=1;i--){
            ans+=m*a[i];
            m*=0.95;
        }
        printf("%.12lf\n",ans);
    }
    return 0;
}
