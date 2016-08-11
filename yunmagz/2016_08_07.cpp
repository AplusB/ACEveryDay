//hdu5007 Post Robot
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
const int inf=0x3f3f3f3f;
////LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main()
{
    string s;
    while(cin>>s)
    {
        string ss;
        int n=SZ(s);
        for(int i=0;i<n;i++){
            ss=s.substr(i,4);
            if(ss=="iPad"||ss=="iPod") puts("MAI MAI MAI!");
            else if(ss=="Sony") puts("SONY DAFA IS GOOD!");
            ss=s.substr(i,5);
            if(ss=="Apple") puts("MAI MAI MAI!");
            ss=s.substr(i,6);
            if(ss=="iPhone") puts("MAI MAI MAI!");
        }
    }
    return 0;
}
//hdu5011 Game
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
const int inf=0x3f3f3f3f;
////LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main()
{
    int t,n,a;
    while(~scanf("%d",&n))
    {

        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            ans^=a;
        }
        if(ans) puts("Win");
        else puts("Lose");
    }
    return 0;
}
//hdu5012 Dice
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
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
////LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int dice[4][6]={3,2,0,1,4,5,2,3,1,0,4,5,5,4,2,3,0,1,4,5,2,3,1,0};
struct node{
	int dir[6];
	int t;
}d[4];
bool ok;
queue<node>q;
bool jg(node a,node b){
    for(int i=0;i<6;i++){
        if(a.dir[i]!=b.dir[i])
            return false;
    }
    return true;
}
int bfs(){
	q.push(d[0]);
	while(!q.empty()){
		d[2]=q.front();
		if(d[2].t>4)
			return -1;
		q.pop();
		if(jg(d[1],d[2]))
			return d[2].t;
		for(int i=0;i<4;i++){
			for(int j=0;j<6;j++)
				d[3].dir[j]=d[2].dir[dice[i][j]];
			d[3].t=d[2].t+1;
			q.push(d[3]);
		}
	}
}
int main(){
	while(~scanf("%d",&d[0].dir[0])){
		while(!q.empty())
			q.pop();
		ok=false;
		for(int i=1;i<6;i++) scanf("%d",&d[0].dir[i]);
		for(int i=0;i<6;i++) scanf("%d",&d[1].dir[i]);
		d[0].t=0;
		printf("%d\n",bfs());
	}
	return 0;
}
//hdu5014 Number Sequence
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
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
////LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define Matr 15 //矩阵大小,注意能小就小   矩阵从1开始   所以Matr 要+1
struct mat//矩阵结构体，a表示内容，size大小 矩阵从1开始   但size不用加一
{
	LL a[Matr][Matr];
	mat()//构造函数
	{
		memset(a,0,sizeof(a));
	}
};
int Size;

mat multi(mat m1,mat m2)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算的优化
{
	mat ans=mat();
	for(int i=1;i<=Size;i++)
		for(int j=1;j<=Size;j++)
			if(m1.a[i][j])//稀疏矩阵优化
				for(int k=1;k<=Size;k++)
					ans.a[i][k]=(ans.a[i][k]+m1.a[i][j]*m2.a[j][k])%mod; //i行k列第j项
	return ans;
}

mat quickmulti(mat m,LL n)//二分快速幂
{
	mat ans=mat();
	int i;
	for(i=1;i<=Size;i++)ans.a[i][i]=1;
	while(n)
	{
		if(n&1)ans=multi(m,ans);
		m=multi(m,m);
		n>>=1;
	}
	return ans;
}

 void print(mat m)//输出矩阵信息，debug用
{
    int i,j;
    printf("%d\n",Size);
    for(i=1;i<=Size;i++)
    {
        for(j=1;j<=Size;j++)
            printf("%I64d ",m.a[i][j]);
        printf("\n");
    }
}
int main()
{
	mat gou,chu=mat();
	LL n,m;
	LL ans;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		Size=n+2;
		chu=mat();
		chu.a[1][n+1]=23;
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&chu.a[1][i]);
			chu.a[1][i]%=mod;
		}
		chu.a[1][n+2]=3;
		gou=mat();
		for(int j=1;j<=n;j++)
		{
			if(j==1)
			{
				gou.a[n+1][j]=10;
				gou.a[n+2][j]=1;
			}
			gou.a[j][j]=1;
			for(int i=1;i<=n+2;i++)
			{
				gou.a[i][j]+=gou.a[i][j-1];
			}
		}
		gou.a[n+1][n+1]=10;
		gou.a[n+2][n+2]=1;
		gou.a[n+2][n+1]=1;
		ans=multi(chu,quickmulti(gou,m)).a[1][n];
		//print(multi(chu,quickmulti(gou,m)));
		printf("%I64d\n",ans%mod);
	}
	return 0;
}
//hdu5015 233 Matrix
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
const int inf=0x3f3f3f3f;
////LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[100010],x[100010];
int main()
{
    int t,n;
    while(~scanf("%d",&n))
    {
        memset(a,-1,sizeof a);
        LL ans=0;
        for(int i=0;i<=n;i++)
            scanf("%d",&x[i]);
        for(int i=n;i>=0;i--){
            if(a[i]!=-1) continue;
            int xx=i;
            int flag=0;
            for(int j=20;j>=0;j--){
                if(xx&(1<<j)) flag=1;
                if(flag) xx^=(1<<j);
            }
            a[i]=xx;
            a[xx]=i;
            ans+=(xx^i)*2;
        }
        printf("%I64d\n",ans);
        for(int i=0;i<=n;i++) printf("%d%c",a[x[i]],i==n?'\n':' ');
    }
    return 0;
}
