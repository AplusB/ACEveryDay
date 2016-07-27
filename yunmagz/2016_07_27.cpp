//hdu5308 I Wanna Become A 24-Point Master
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
int a[9999];
int main()
{
//    freopen("out.txt","r",stdin);
//    int n;
//    char s[5];
//    int b,c;
//    while(cin>>n){
//        for(int i=1;i<=n;i++) a[i]=n;
//        for(int i=1;i<n;i++){
//            cin>>b>>s>>c;
//            if(b>=n+i||c>=n+i) puts("aaa");
//            if(s[0]=='+') a[n+i]=a[b]+a[c];
//            if(s[0]=='-') a[n+i]=a[b]-a[c];
//            if(s[0]=='*') a[n+i]=a[b]*a[c];
//            if(s[0]=='/') a[n+i]=a[b]/a[c];
//        }
//        cout<<n<<" "<<a[n*2-1]<<endl;
//    }
    int n;
    while(cin>>n){
        if(n<14){
            if(n<=3) puts("-1");
            else if(n==4){
                puts("1 * 2");
                puts("5 + 3");
                puts("6 + 4");
            }
            else if(n==5){
                puts("1 * 2");
                puts("6 * 3");
                puts("7 - 4");
                puts("8 / 5");
            }
            else if(n==6){
                puts("1 / 2");
                puts("3 * 7");
                puts("4 * 8");
                puts("9 - 5");
                puts("10 - 6");
            }
            else if(n==7){
                puts("1 + 2");
                puts("8 + 3");
                puts("4 + 5");
                puts("6 + 10");
                puts("11 / 7");
                puts("9 + 12");
            }
            else if(n==8){
                puts("1 + 2");
                puts("9 / 3");
                puts("5 / 4");
                puts("11 + 10");
                puts("12 * 6");
                puts("13 + 7");
                puts("14 - 8");
            }
            else if(n==9){
                puts("1 + 2");
                puts("3 + 10");
                puts("4 / 5");
                puts("6 / 7");
                puts("8 / 9");
                puts("11 - 12");
                puts("15 - 13");
                puts("16 - 14");
            }
            else if(n==10){
                puts("1 + 2");
                puts("3 / 4");
                puts("5 / 6");
                puts("7 / 8");
                puts("9 / 10");
                puts("11 + 12");
                puts("16 + 13");
                puts("17 + 14");
                puts("18 + 15");
            }
            else if(n==11){
                puts("1 + 2");
                puts("3 + 4");
                puts("13 / 5");
                puts("12 + 14");
                puts("15 + 6");
                puts("16 - 7");
                puts("17 + 8");
                puts("18 - 9");
                puts("19 + 10");
                puts("20 - 11");
            }
            else if(n==12){
                puts("1 + 2");
                puts("13 + 3");
                puts("14 + 4");
                puts("15 / 5");
                puts("6 + 7");
                puts("17 + 8");
                puts("18 + 9");
                puts("19 + 10");
                puts("20 + 11");
                puts("21 / 12");
                puts("16 * 22");
            }
            else if(n==13){
                puts("1 + 2");
                puts("3 + 4");
                puts("14 / 5");
                puts("15 - 16");
                puts("17 + 6");
                puts("18 - 7");
                puts("19 + 8");
                puts("20 - 9");
                puts("21 + 10");
                puts("22 - 11");
                puts("23 + 12");
                puts("24 - 13");
            }
        }
        else {
                puts("1 - 2");
                for(int i=3;i<=n-12;i++) printf("%d * %d\n",i,n+i-2);
                printf("%d + %d\n",n-11,n-10);
                printf("%d + %d\n",2*n-12,n-9);
                printf("%d + %d\n",2*n-11,n-8);
                printf("%d / %d\n",2*n-10,n-7);
                printf("%d + %d\n",n-6,n-5);
                printf("%d + %d\n",2*n-8,n-4);
                printf("%d + %d\n",2*n-7,n-3);
                printf("%d + %d\n",2*n-6,n-2);
                printf("%d + %d\n",2*n-5,n-1);
                printf("%d / %d\n",2*n-4,n);
                printf("%d * %d\n",2*n-3,2*n-9);
                printf("%d + %d\n",2*n-2,2*n-13);
        }
    }
    return 0;
}
