//TCO2016 2B 300
#line 6 "TriangleTriples.cpp"
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
LL f(LL x){
    if(x<0) return 0;
    return (x*x%mod*x%mod-x)%mod*166666668%mod;
}
LL solve(LL a,LL b,LL c){
    LL ans=0;
    if(c>=a+b){
        ans=(c-a-b+1)*a%mod*b%mod;
        c=a+b-1;
    }
    return ans+f(c)-f(c-a)-f(c-b);;
}
class TriangleTriples
{
        public:
        int count(int a, int b, int c)
        {
            LL ans=1ll*a*b%mod*c%mod;
            ans-=solve(a,b,c);
            ans-=solve(a,c,b);
            ans-=solve(c,b,a);
            ans=(ans%mod+mod)%mod;
            return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 20; int Arg3 = 10; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1000000000; int Arg3 = 6; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; int Arg3 = 505; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 123456789; int Arg1 = 987654321; int Arg2 = 555555555; int Arg3 = 64296241; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TriangleTriples ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE

//女生赛
//01
#include <bits/stdc++.h>
using namespace std;
#define LL long long
struct node {
    string s;
    int x;
}a[15];
bool cmp(node a,node b)
{
    return a.x>b.x;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].s>>a[i].x;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
            cout<<a[i].s<<(i!=n-1?' ':'\n');
    }
    return 0;
}
//02
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<"1";
        for(int i=0;i<n-1;i++)
            cout<<"0";
        cout<<endl;
    }
    return 0;
}
//03
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int a[110],v[110];
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int sum=0;
        memset(v,0,sizeof v);
        for(int i=0;i<n-1;i++){
            cin>>a[i];
            sum+=a[i];
            v[a[i]]++;
        }
        double p=0;
        int m=0;
        for(int i=0;i<=100;i++){
            double av=(sum+i)*2/3.0/n;
            if(av<i) continue;
            int flag=1;
            for(int j=i+1;j<=av&&flag;j++){
                if(v[j])
                    flag=0;
            }
            if(!flag) continue;
            if(1.0/(v[i]+1)>=p){
                p=1.0/(v[i]+1);
                m=i;
            }
        }

        printf("%d %.2lf\n",m,p);
    }
    return 0;
}
//04
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    int h,m,s,a,cas=1;
    while(~scanf("%d:%d:%d",&h,&m,&s)){
        scanf("%d",&a);
        int t=(h*60+m)*60+s;
        t++;
        double sz=t*0.1/12;
        double fz=t%3600*0.1;
        if(sz>fz) swap(sz,fz);
        double pre=fz-sz,dlt;
        if(pre>180) pre=360-pre;
        while(1){
            t++;
            sz=t*0.1/12;
            fz=t%3600*0.1;
            if(sz>fz) swap(sz,fz);
            dlt=fz-sz;
            if(dlt>180) dlt=360-dlt;
            if((pre>=a&&dlt<a)||(pre<=a&&dlt>a))
                break;
            pre=dlt;
        }
        t--;
        t%=3600*12;
        printf("Case #%d: %02d:%02d:%02d\n",cas++,t/3600,t%3600/60,t%60);
    }
    return 0;
}
//05
#include <bits/stdc++.h>
using namespace std;
#define LL long long
char mp[1010][1010];
int f[4][2]={0,1,1,0,0,-1,-1,0};
string cat="cat";
string girl="girl";
int n,m;
int dfsg(int x,int y,int s){
    if(s>=4) return 1;
    int ans=0;
    for(int i=0;i<4;i++){
        int xx=x+f[i][0];
        int yy=y+f[i][1];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[xx][yy]==girl[s]){
            ans+=dfsg(xx,yy,s+1);
        }
    }
    return ans;
}
int dfsc(int x,int y,int s){
    if(s>=3) return 1;
    int ans=0;
    for(int i=0;i<4;i++){
        int xx=x+f[i][0];
        int yy=y+f[i][1];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[xx][yy]==cat[s]){
            ans+=dfsc(xx,yy,s+1);
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>mp[i]+1;
        int cntg=0,cntc=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]=='g') cntg+=dfsg(i,j,1);
                if(mp[i][j]=='c') cntc+=dfsc(i,j,1);
            }
        }
        cout<<cntg<<" "<<cntc<<endl;
    }
    return 0;
}
//06
#include <bits/stdc++.h>
using namespace std;
#define LL long long
char a[2010],b[2010],c[2010];
bool dp[2010][2010];
int main()
{
    while(~scanf("%s%s%s",a+1,b+1,c+1)){
        int na=strlen(a+1);
        int nb=strlen(b+1);
        int nc=strlen(c+1);
        if(na+nb!=nc)
            puts("No");
        else {
            dp[0][0]=1;
            for(int i=0;i<=na;i++){
                for(int j=0;j<=nb;j++){
                    if(i&&j) dp[i][j]=0;
                    if(i&&dp[i-1][j]&&a[i]==c[i+j])dp[i][j]=1;
                    if(j&&dp[i][j-1]&&b[j]==c[i+j])dp[i][j]=1;
                }
            }
            if(dp[na][nb]) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
//07
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int mp[110][110];
int main()
{
    int t,q,k,n,m;
    cin>>t;
    while(t--){
        cin>>q>>k;
        k++;
        while(q--){
            cin>>n>>m;
            if(n>m) swap(n,m);
            if(n==1){
                if(m&1) puts("Bob");
                else puts("Alice");
            }
            else {
                if(n%k==0) puts("Alice");
                else {
                    int x=n/k;
                    if(k>2 && x&1){
                        if((n+m)&1) puts("Bob");
                        else puts("Alice");
                    }
                    else {
                        if((n+m)&1) puts("Alice");
                        else puts("Bob");
                    }
                }
            }
        }
    }
    return 0;
}
//09
#include <bits/stdc++.h>
using namespace std;
#define LL long long
char s[233];
int main()
{
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a>2*b) puts("0");
        else if(a==2*b) puts("1");
        else {
            int sum=b*9,l=b*2-a;
            int g=__gcd(sum,l);
            sum/=g;
            l/=g;
            if(l*5>sum) puts("0");
            else {
                memset(s,0,sizeof s);
                sum-=l*5;
                for(int i=0;i<l;i++){
                    s[i]='5'+min(sum,4);
                    sum-=min(sum,4);
                }
                while(sum){
                    s[l++]='0'+min(sum,4);
                    sum-=min(sum,4);
                }
                reverse(s,s+l);
                cout<<s<<endl;
            }
        }
    }
    return 0;
}
//10
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PII pair<int, int>
const int inf=0x3f3f3f3f;
int n,m,k,l;
int d[20][20],dp[(1<<17)+10][20],a[20],b[20];
priority_queue<PII>q;
void floyd(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main()
{
    int t,cas=1;
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>l;
        memset(d,inf,sizeof d);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=0;i<m;i++){
            int x,y,v;
            cin>>x>>y>>v;
            d[x][y]=min(d[x][y],v);
            d[y][x]=min(d[y][x],v);
        }
        floyd();
        memset(dp,inf,sizeof dp);
        dp[1][0]=0;
        int ans=0;
        for(int i=0;i<(1<<(n+1));i++){
            int flag=0;
            for(int j=0;j<=n;j++){
                if(dp[i][j]<=l){
                    if(dp[i][j]+d[j][0]<=l) flag=1;
                    for(int h=1;h<=n;h++){
                        dp[i|(1<<h)][h]=min(dp[i|(1<<h)][h],dp[i][j]+d[j][h]);
                    }
                }
            }
            if(flag){
                while(!q.empty())
                    q.pop();
                for(int j=1;j<=n;j++)
                    if(i&(1<<j))
                        q.push(make_pair(a[j],b[j]));
                if(q.empty()) continue;
                int sum=0;
                for(int j=0;j<k;j++){
                    PII pp=q.top();
                    q.pop();
                    sum+=pp.first;
                    pp.first=max(pp.first-pp.second,0);
                    q.push(pp);
                }
                ans=max(ans,sum);
            }
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
