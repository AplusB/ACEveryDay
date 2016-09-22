//UVALive 7324 - ASCII Addition
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
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
char s[10][1000];
int f[8][2]={-3,0,0,0,3,0,-2,-2,-2,2,2,-2,2,2,-2,0};
int v[1010];
char g[9][123]={"xxxxx....xxxxxxxxxxxx...xxxxxxxxxxxxxxxxxxxxxxxxxx",
             "x...x....x....x....xx...xx....x........xx...xx...x",
             "x...x....x....x....xx...xx....x........xx...xx...x",
             "x...x....xxxxxxxxxxxxxxxxxxxxxxxxxx....xxxxxxxxxxx",
             "x...x....xx........x....x....xx...x....xx...x....x",
             "x...x....xx........x....x....xx...x....xx...x....x",
             "xxxxx....xxxxxxxxxxx....xxxxxxxxxxx....xxxxxxxxxxx"};
int ans[20];
int main(){
    v[(1<<0)+(1<<2)+(1<<3)+(1<<4)+(1<<5)+(1<<6)]=0;
    v[(1<<4)+(1<<6)]=1;
    v[(1<<0)+(1<<2)+(1<<5)+(1<<4)+(1<<1)]=2;
    v[(1<<0)+(1<<2)+(1<<1)+(1<<4)+(1<<6)]=3;
    v[(1<<1)+(1<<3)+(1<<4)+(1<<6)]=4;
    v[(1<<0)+(1<<2)+(1<<3)+(1<<1)+(1<<6)]=5;
    v[(1<<0)+(1<<2)+(1<<3)+(1<<1)+(1<<5)+(1<<6)]=6;
    v[(1<<0)+(1<<4)+(1<<6)]=7;
    v[(1<<0)+(1<<1)+(1<<2)+(1<<3)+(1<<4)+(1<<5)+(1<<6)]=8;
    v[(1<<0)+(1<<2)+(1<<3)+(1<<4)+(1<<1)+(1<<6)]=9;
    v[(1<<1)+(1<<7)]=10;
    while(~scanf("%s",s[0])){
        for(int i=1;i<7;i++) scanf("%s",s[i]);
        int n=strlen(s[0]),a=0,b=0,flag=1;
        for(int i=2;i<n;i+=6){
            int tmp=0;
            for(int j=0;j<8;j++){
                int x=3+f[j][0];
                int y=i+f[j][1];
                if(s[x][y]=='x'){
                    tmp+=(1<<j);
                }
            }
            if(flag){
                if(v[tmp]==10) flag=0;
                else a=a*10+v[tmp];
            }
            else b=b*10+v[tmp];
        }
        a+=b;
        memset(ans,0,sizeof ans);
        int m=0;
        if(a==0) m=1;
        while(a){
            ans[m++]=a%10;
            a/=10;
        }
        for(int k=0;k<7;k++)
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<5;j++) printf("%c",g[k][ans[i]*5+j]);
            printf("%c",i==0?'\n':'.');
        }
    }
    return 0;
}
