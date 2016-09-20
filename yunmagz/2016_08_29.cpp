//Codeforces Round #369 (Div. 2)
//A - Bus to Udayland
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
char s[1010][10];
int main()
{
    int n,a;
    cin>>n;
    int f=0;
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        if(s[i][0]=='O'&&s[i][1]=='O'&& !f){
            s[i][0]='+';
            s[i][1]='+';
            f=1;
        }
        else if(s[i][3]=='O'&&s[i][4]=='O'&& !f){
            s[i][3]='+';
            s[i][4]='+';
            f=1;
        }
    }
    if(f){
        puts("YES");
        for(int i=0;i<n;i++) puts(s[i]);
    }
    else puts("NO");
	return 0;
}
