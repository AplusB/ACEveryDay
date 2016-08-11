//2016 Multi-University Training Contest 8
//1006 physics 
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
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
double a[100010];
int main()
{
    double c;
    int t,n,x,k,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d%lf",&n,&c);
        for(int i=0;i<n;i++)
            scanf("%lf%d%d",&a[i],&x,&x);
        sort(a,a+n);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&x,&k);
            printf("%.3lf\n",sqrt(c*2*x+a[k-1]*a[k-1]));
        }
    }
    return 0;
}
//1011 Rikka with Parenthesis II 
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
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
char s[100010];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s);
        int flag=0;
        int cnt=0;
        for(int i=0;i<n&&flag!=2;i++){
            if(s[i]=='('){
                cnt++;
            }
            else {
                cnt--;
                if(cnt==-1){
                    if(flag==0){
                        cnt=1;
                        flag=1;
                    }
                    else if(flag==1){
                        flag=2;
                    }
                }
            }
        }
        if(flag==0){
            if(cnt==0){
                if(n==2) puts("No");
                else puts("Yes");
            }
            else puts("No");
        }
        else if(flag==1&&cnt==2) puts("Yes");
        else puts("No");
    }
    return 0;
}

