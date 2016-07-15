#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define PB push_back
#define all(a) a.begin(),a.end()

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

const int N=102;
LL t,n,m,cnt;
LL MOD=1e9+7;
LL a[N],b[N];
struct Matrix{
    LL a[N][N];
    Matrix(){memset(a,0,sizeof(a));}
};

Matrix MUL(Matrix A,Matrix B){
	Matrix res;LL i,j,k,l;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			res.a[i][j]=0;
			for(k=1;k<=n;k++){
				res.a[i][j]+=A.a[i][k]*B.a[k][j]%MOD;
				res.a[i][j]%=MOD;
			}
		}
	}
	return res;
}
Matrix FPM(Matrix A,LL b){
	Matrix res;
	for(LL i=1;i<=n;i++)res.a[i][i]=1ll;
	while(b){
		if(b&1)res=MUL(res,A);
		b>>=1;A=MUL(A,A);
	}
	return res;
}

LL get(LL x){
	LL res=0;
	while(x){
		res+=(x&1ll);
		x>>=1;
	}
	return res;
}

void test(){
	LL i,j,k,l,dp[N][N]={0};
	for(i=1;i<=n;i++)dp[1][i]=1;
	for(i=2;i<=m;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				l=get(a[j]^a[k]);
				if(l%3==0){
					dp[i][j]+=dp[i-1][k];
					dp[i][j]%=MOD;
				}
			}
//			printf("%I64d ",dp[i][j]);
		}
//		puts("");
	}
	LL res=0;
	for(i=1;i<=n;i++)res+=dp[m][i],res%=MOD;
	printf("%I64d\n",res);
}

int main()
{
    //FIN;//FOUT;
    LL i,j,k,res=0;
    gn(n);gn(m);
    for(i=1;i<=n;i++)gn(a[i]);
    Matrix A;
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		A.a[i][j]=0;
    		if(get(a[i]^a[j])%3==0)A.a[i][j]++;
		}
	}
	A=FPM(A,m-1);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			res+=A.a[i][j];
			res=(res+MOD)%MOD;
		}
	}
	printf("%I64d\n",res);
//    test();
    
    return 0;
}
