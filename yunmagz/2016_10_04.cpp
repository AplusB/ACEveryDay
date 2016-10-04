//2016中国大学生程序设计竞赛（长春）-重现赛
//1002	Fraction
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL a[10],b[10];
int main()
{
    int t,cas=1,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        LL m=a[n-1],z=b[n-1];
        LL g=__gcd(m,z);
        m/=g;
        z/=g;
        for(int i=n-2;i>=0;i--){
            z+=a[i]*m;
            swap(z,m);
            z*=b[i];
            g=__gcd(m,z);
            m/=g;
            z/=g;
        }
        printf("Case #%d: %lld %lld\n",cas++,z,m);
    }
    return 0;
}
//1004	Triangle
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[]={1,2,3,5,8,13};
int b[]={0,0,0,0,1,1,2,3,3,4,5,6,7,7,8,9,10,11,12,13,14};
int main()
{
    int t,cas=1,n;
    cin>>t;
    while(t--){
        cin>>n;
        printf("Case #%d: %d\n",cas++,b[n]);
    }
    return 0;
}
//1006	Harmonic Value Description
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[10010];
int v[10010];
int main()
{
    int t,cas=1,n,k;
    cin>>t;
    while(t--){
            memset(v,0,sizeof v);
        cin>>n>>k;
        int x=k-1;
        int m=(n&1)?n-1:n;
        for(int i=0;i<=x;i++){
            a[i]=m-i*2;
            v[m-i*2]=1;
        }
        int j=x+1;
        for(int i=1;i<=n;i++){
            if(!v[i]) a[j++]=i;
        }
        printf("Case #%d:",cas++);
        for(int i=0;i<n;i++) printf(" %d",a[i]);
        puts("");
    }
    return 0;
}
//1008	Sequence I
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair< PI, int> PII;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
#define Key_value ch[ch[root][1]][0]
const int MAXN = 100000+100;
const int MAXM = 10100;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

/*  * nex[]的含义：x[i-nex[i]...i-1]=x[0...nex[i]-1]
* nex[i]为满足x[i-z...i-1]=x[0...z-1]的最大z值（就是x的自身匹配）  */
void kmp_pre(int x[],int m,int nex[])
{
    int i,j;
    j=nex[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j && x[i]!=x[j])j=nex[j];
        nex[++i]=++j;
    }
}

/*  * kmpnex[]的意思：
nex'[i]=nex[nex[...[nex[i]]]]
(直到nex'[i]<0或者 x[nex'[i]]!=x[i])  *
 这样的预处理可以快一些  */
void preKMP(int x[],int m,int kmpnex[])
{
    int i,j;
    j=kmpnex[0]=-1;
    i=0;
    while(i<m)
    {


        while(-1!=j && x[i]!=x[j])j=kmpnex[j];
        if(x[++i]==x[++j])kmpnex[i]=kmpnex[j];
        else kmpnex[i]=j;
    }
}
/*  * 返回x在y中出现的次数，可以重叠  */

int nex[1000010];
int p,q;
int KMP_Count(int x[],int m,int y[],int n)  //x是模式串，y是主串
{
    int i,j;
    int ans=0;
    //preKMP(x,m,nex);
    kmp_pre(x,m,nex);
    j=0;
    i=q;
    while(i<n)
    {
        while(-1!=j && y[i]!=x[j])
            j=nex[j];
        i+=p;
        j++;
        if(j>=m)
        {
            ans++;
            j=nex[j];
        }
    }
    return ans;
}

int a[1000000+10];
int b[1000000+10];

int main()
{
    int t;
    scanf("%d",&t);
    int casee=1;
    while(t--)
    {
        int n,m;
        scanf("%d%d%d",&n,&m,&p);
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<m; ++i)
        {
            scanf("%d",&b[i]);
        }
        printf("Case #%d: ",casee++);
        LL ans=0;
        LL len=min(p,n-(m-1)*p);
        for(LL i=0;i<len;++i)
        {
            q=i;
            ans+=KMP_Count(b,m,a,n);
        }
        cout<<ans<<endl;
    }

    return 0;
}
//1010	Ugly Problem
import java.util.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {

        // TODO Auto-generated method stub
        Scanner cin = new Scanner(System.in);
        int t,cas=1;
        t = cin.nextInt();
        int casee = 1;
        BigInteger s, tmp,tmp2,tmp3,tmp4,tmp5,hh;
        int[] a = new int[1050];
        int[] b = new int[1050];
        BigInteger []ans=new BigInteger[5005];
        BigInteger []pw=new BigInteger[1001];
        pw[1]=BigInteger.valueOf(10);
        for(int i=2;i<=1000;++i)
        {
            pw[i]=pw[i-1].multiply(BigInteger.valueOf(10));
        }
        while (t > 0) {
            t--;
            s = cin.nextBigInteger();
            tmp = s;
            int cnt = 0;
            int tol=0,ll;
            while(true)
            {
                if(s.compareTo(BigInteger.ZERO)==0) break;
                ll=String.valueOf(s).length();
                if(ll==1){
                    ans[tol++]=s;
                    break;
                }
                else if(ll==2){
                    while(s.compareTo(BigInteger.valueOf(9))>0){
                        ans[tol++]=BigInteger.valueOf(9);
                        s=s.subtract(BigInteger.valueOf(9));
                    }
                    if(s.compareTo(BigInteger.ZERO)!=0)
                    ans[tol++]=s;
                    break;
                }
                tmp=tmp2=s;
                int len=ll;
                boolean flag;
                if(len%2==1)
                {
                    tmp=tmp.mod(pw[len/2]);
                    tmp2=tmp2.divide(pw[len/2+1]);
                    flag=true;
                }
                else
                {
                    tmp=tmp.mod(pw[len/2]);
                    tmp2=tmp2.divide(pw[len/2]);
                    flag=false;
                }
                
                //  tmp2 前  tmp后  tmp4翻转后 tmp5翻转前
                ll=String.valueOf(tmp2).length();
                tmp3=BigInteger.ZERO;
                tmp4=tmp;
//                System.out.println(tmp);
                for(int i=0;i<ll;++i)
                {
                    tmp3=tmp3.multiply(BigInteger.valueOf(10));
                    tmp3=tmp3.add(tmp4.mod(BigInteger.valueOf(10)));
                    tmp4=tmp4.divide(BigInteger.valueOf(10));
                }
                tmp4=tmp3;
                
                tmp3=BigInteger.ZERO;
                tmp5=tmp2;
                for(int i=0;i<ll;++i)
                {
                    tmp3=tmp3.multiply(BigInteger.valueOf(10));
                    tmp3=tmp3.add(tmp5.mod(BigInteger.valueOf(10)));
                    tmp5=tmp5.divide(BigInteger.valueOf(10));
                }
                tmp5=tmp3;

//                System.out.print(tmp2);
//                System.out.print(" "+tmp);
//                System.out.print(" "+tmp4);
//                System.out.println(" "+tmp5);
                
                //  tmp2 前  tmp后  tmp4翻转后 tmp5翻转前
                if(tmp5.compareTo(tmp)<0)
                {
                    tmp3=s.divide(pw[len/2]).multiply(pw[len/2]);
                    tmp3=tmp3.add(tmp5);
                    ans[tol++]=tmp3;
                    //System.out.println(tmp3+" "+s);
                    s=s.subtract(tmp3);
                    //
                }
                else if(tmp5.compareTo(tmp)==0){
                    ans[tol++]=s;
                    break;
                }
                //  tmp2 前  tmp后  tmp4翻转后 tmp5翻转前
                else {
                    tmp=tmp.add(BigInteger.ONE);
                    tmp3=s.subtract(tmp);
//                    System.out.println("2345234 "+tmp3);
                    int jj=String.valueOf(tmp3).length();
                    boolean fff=jj%2==1?true:false;
                    //tmp +1  tmp3 s' 
                    if(fff){
                        tmp2=tmp3.divide(pw[jj/2+1]);
                        tmp5=tmp2;
                        hh=BigInteger.ZERO;
                        for(int i=0;i<jj/2;++i)
                        {
                            hh=hh.multiply(BigInteger.valueOf(10));
                            hh=hh.add(tmp5.mod(BigInteger.valueOf(10)));
                            tmp5=tmp5.divide(BigInteger.valueOf(10));
                        }
                        tmp5=hh;
//                        System.out.println("jj "+tmp5);
                        hh=tmp3.divide(pw[jj/2]).multiply(pw[jj/2]).add(tmp5);
                        ans[tol++]=hh;
                        hh=tmp3.subtract(hh);
                        s=tmp.add(hh);
                    }
                    else {
                        tmp2=tmp3.divide(pw[jj/2]);
                        tmp5=tmp2;
                        hh=BigInteger.ZERO;
                        for(int i=0;i<jj/2;++i)
                        {
                            hh=hh.multiply(BigInteger.valueOf(10));
                            hh=hh.add(tmp5.mod(BigInteger.valueOf(10)));
                            tmp5=tmp5.divide(BigInteger.valueOf(10));
                        }
                        tmp5=hh;
                        hh=tmp3.divide(pw[jj/2]).multiply(pw[jj/2]).add(tmp5);
                        ans[tol++]=hh;
                        hh=tmp3.subtract(hh);
                        s=tmp.add(hh);
                    }
                }
                
            }
            System.out.println("Case #"+cas+":");
            cas++;
            System.out.println(tol);
            
            
            for (int i = 0; i < tol; ++i) {
                System.out.println(ans[i]);
                // a[cnt++]=tmp.mod(BigInteger.valueOf(10)).intValue();
            }

        }

    }
}
