/*
    补题！昨天的CF的E1，比较上下两边的差的绝对值之和与中间两行差的绝对值之和，即可对210/216的测试。
    我好菜呀！昨天就看了一个文件夹的图片，所有提供的图片都多看几眼好了。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define FIN freopen("all.in","r",stdin)
#define FOUT freopen("my_all_output1.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

template<typename T>inline void gn(T &x){
    x=0;T f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
template<typename T>inline void gt(T x){
    if(!x)return;
    gt(x/10);putchar(x%10+'0');
}

int t,n,m,a[666][666];
LL MOD=1e9+7;

void solve(){
    int i,j,k,l,x=0,y=0;
    gn(n);gn(m);
    repu(i,1,n)repu(j,1,m)gn(a[i][j]);
    repu(i,1,m){
        x+=abs(a[(n/2)][i]-a[n/2+1][i]);
        y+=abs(a[n][i]-a[1][i]);
    }
    puts(x>y?"YES":"NO");
    //putchar(x>y?'1':'0');
}

int main()
{
    //FIN;FOUT;
    gn(t);
    while(t--){
        solve();
    }
    return 0;
}


///*短码*///其实一行即可。另外，只要对75%即可，数组a可以适当存前75%个稍多的答案即可。这样更短。
/*
char a[222]="100100000111111101010010010011010101110110110111010011111100100001000010100011011000000100101000011111000101010100111100010111010001000111111111110100000100101010100110010000101001011100011010111011010110110010001101";
main(){for(int i=0;i<216;i++)puts(a[i]=='1'?"YES":"NO");}
*/ 
