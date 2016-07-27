//hdu5752 Sqrt Bo
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
char s[110];
int main(){
    int t;
    while(~scanf("%s",s)){
        int n=strlen(s);
        if(n>15){
            puts("TAT");
        }
        else{
            LL m=0;
            for(int i=0;i<n;i++){
                m*=10;
                m+=s[i]-'0';
            }
            if(m==0) puts("TAT");
            else if(m==1) puts("0");
            else if(m<4) puts("1");
            else if(m<16) puts("2");
            else if(m<256) puts("3");
            else if(m<65536) puts("4");
            else if(m<4294967296LL) puts("5");
            else puts("TAT");
        }
    }
    return 0;
}
//hdu5753 Permutation Bo
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
double a[1100];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%lf",&a[i]);

        }
        if(n==1) printf("%.6lf\n",a[1]);
        else{
            double sum=(a[1]+a[n])*3;
            for(int i=2;i<=n-1;i++){
                sum+=a[i]*2;
            }
            printf("%.6lf\n",sum/6);
        }
    }
    return 0;
}
//hdu5754 Life Winner Bo
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
int s[1010][1010];
int s2[1010][1010];
void init()
{
    s[2][1]=s[1][2]=1;
    s[0][0]=s[3][3]=-1;
    s[4][2]=s[2][4]=0;
    for(int i=9;i<=2000;i+=3)
    {
        for(int j=2;2*j<=i;j++)
        {
            if(i-j>1000||j>1000) continue;
            int s1=-s[j-2][i-j-1];
            int s2=-s[j-1][i-j-2];
            s[j][i-j]=s[i-j][j]=max(s1,s2);
        }
    }
    memset(s2,-1,sizeof(s2));
    s2[1][1]=s2[0][1]=s2[1][0]=1;
    for(int i=3;i<=2000;i++)
    {

        for(int j=1;2*j<=i;j++)
        {
             if(i-j>1000||j>1000) continue;
            int a1=-s2[j-1][i-j];
            int a2=-s2[j][i-j-1];
            int a3=-s2[j-1][i-j-1];
            if(a1>0||a2>0||a3>0)
                s2[j][i-j]=s2[i-j][j]=1;
            else s2[j][i-j]=s2[i-j][j]=-1;
        }
    }
}

int main()
{
    int T,t,m,n;
    init();
    cin>>T;
    while(T--)
    {
        cin>>t>>n>>m;
        int flag;
        if(t==1)
        {
            if(n&1 && m&1)flag=0;
            else flag=1;
        }
        else if(t==2)
        {
            if(m==n)
                flag=0;
            else flag=1;
        }
        else if(t==3)
        {
            if((n+m-2)%3!=0) flag=2;
            else
            {
                int k=s[n-1][m-1];
                if(k==-1) flag=0;
                if(k==0) flag=2;
                if(k==1) flag=1;
            }
        }
        else if(t==4)
        {
            n--;m--;
            int k = abs(n-m);
            n = n < m? n : m;
            int a_k= floor(k*(1.0 + sqrt(5.0))/2);
            if(n!=a_k) flag=1;
            else flag=0;
        }
        if(flag==0)cout<<"G"<<endl;
        if(flag==1)cout<<"B"<<endl;
        if(flag==2)cout<<"D"<<endl;
    }
}
//hdu5761 Rower Bo
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,v1,v2;
    while(~scanf("%d%d%d",&a,&v1,&v2)){
        if(a==0){
            printf("0.00000000\n");
            continue;
        }
        if(v1<=v2){
            printf("Infinity\n");
            continue;
        }
        printf("%.10lf\n",(a*v1*1.0/((v1*v1-v2*v2)*1.0)));
    }
    return 0;
}
//hdu5762 Teacher Bo
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
int x[100010],y[100010],v[200010];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=m*2;i++) v[i]=0;
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
        int flag=1;
        for(int i=1;i<=n&&flag;i++){
            for(int j=1;j<i&&flag;j++){
                int g=abs(x[i]-x[j])+abs(y[i]-y[j]);
                v[g]++;
                if(v[g]>=2) flag=0;
            }
        }
        if(flag) puts("NO");
        else puts("YES");
    }
    return 0;
}
