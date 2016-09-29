//HDU 3720 Arranging Your Team
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
char n[25][105],ss[25][15],s1[105],s2[105];
int a[25];
map<string,int>q;
int go[25],mi[25],de[25],st[25],now[15];
int p[25][25];
int main()
{
    int M,v;
    while(~scanf("%s",n[0])){
        q.clear();
        q[n[0]]=0;
        memset(p,0,sizeof p);
        int g=0,m=0,s=0,d=0;
        scanf("%d%s",&a[0],ss[0]);
        if(ss[0][0]=='g') go[g++]=0;
        else if(ss[0][0]=='m') mi[m++]=0;
        else if(ss[0][0]=='s') st[s++]=0;
        else if(ss[0][0]=='d') de[d++]=0;
        for(int i=1;i<23;i++){
            scanf("%s%d%s",n[i],&a[i],ss[i]);
            q[n[i]]=i;
            if(ss[i][0]=='g') go[g++]=i;
            else if(ss[i][0]=='m') mi[m++]=i;
            else if(ss[i][0]=='s') st[s++]=i;
            else if(ss[i][0]=='d') de[d++]=i;
        }
        scanf("%d",&M);
        while(M--){
            scanf("%s%s%d",s1,s2,&v);
            p[q[s1]][q[s2]]=p[q[s2]][q[s1]]=v;
        }
        if(g<1||s<2||m<4||d<4){
            puts("impossible");
            continue;
        }
        int ans=-1e9;
        for(int i0=0;i0<g;i0++){
            int sum0=a[go[i0]];
            now[0]=go[i0];
            for(int i1=0;i1<s-1;i1++){
                int sum1=sum0+a[st[i1]];
                now[1]=st[i1];
                for(int i2=i1+1;i2<s;i2++){
                    int sum2=sum1+a[st[i2]];
                    now[2]=st[i2];
                    for(int i3=0;i3<m-3;i3++){
                        int sum3=sum2+a[mi[i3]];
                        now[3]=mi[i3];
                        for(int i4=i3+1;i4<m-2;i4++){
                            int sum4=sum3+a[mi[i4]];
                            now[4]=mi[i4];
                            for(int i5=i4+1;i5<m-1;i5++){
                                int sum5=sum4+a[mi[i5]];
                                now[5]=mi[i5];
                                for(int i6=i5+1;i6<m;i6++){
                                    int sum6=sum5+a[mi[i6]];
                                    now[6]=mi[i6];
                                    for(int i7=0;i7<d-3;i7++){
                                        int sum7=sum6+a[de[i7]];
                                        now[7]=de[i7];
                                        for(int i8=i7+1;i8<d-2;i8++){
                                            int sum8=sum7+a[de[i8]];
                                            now[8]=de[i8];
                                            for(int i9=i8+1;i9<d-1;i9++){
                                                int sum9=sum8+a[de[i9]];
                                                now[9]=de[i9];
                                                for(int i10=i9+1;i10<d;i10++){
                                                    int sum10=sum9+a[de[i10]];
                                                    now[10]=de[i10];
                                                    for(int i=0;i<11;i++)
                                                        for(int j=i+1;j<11;j++)
                                                            sum10+=p[now[i]][now[j]];
                                                    ans=max(ans,sum10);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//HDU 3722 Card Game
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
const int MAXN = 800000;
const int MAXM = 1250;
int nx,ny;
int g[MAXM][MAXM];
int linker[MAXM],lx[MAXM],ly[MAXM];
int slack[MAXM];
bool visx[MAXM],visy[MAXM];
bool DFS(int x)
{
    visx[x] = true;
    for(int y = 0; y < ny; y++)
    {
        if(visy[y])continue;
        int tmp = lx[x] + ly[y] - g[x][y];
        if(tmp == 0)
        {
            visy[y] = true;
            if(linker[y] == -1 || DFS(linker[y]))
            {
                linker[y] = x;
                return true;
            }
        }
        else if(slack[y] > tmp)
            slack[y] = tmp;
    }
    return false;
}
int KM()
{
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    for(int i = 0; i < nx; i++)
    {
        lx[i] = -INF;
        for(int j = 0; j < ny; j++)
            if(g[i][j] > lx[i])
                lx[i] = g[i][j];
    }
    for(int x = 0; x < nx; x++)
    {
        for(int i = 0; i < ny; i++)
            slack[i] = INF;
        while(true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(DFS(x))break;
            int d = INF;
            for(int i = 0; i < ny; i++)
                if(!visy[i] && d > slack[i])
                    d = slack[i];
            for(int i = 0; i < nx; i++)
                if(visx[i])
                    lx[i] -= d;
            for(int i = 0; i < ny; i++)
            {
                if(visy[i])ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < ny; i++)
        if(linker[i] != -1)
            res += g[linker[i]][i];
    return res;
}
//HDU 2255
int main()
{
    int n;
    string str[205];
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
            cin>>str[i];
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                g[i][j]=0;
        for(int i=0; i<n; ++i)
        {
            int len=str[i].size();
            string tmp=str[i];
            reverse(tmp.begin(),tmp.end());
            for(int j=0; j<n; ++j)
            {
                if(i==j)
                continue;
                int t=min(len,(int)str[j].size());
                int cnt=0;
                for(int k=0; k<t; ++k)
                {
                    if(tmp[k]==str[j][k])
                    {
                        cnt++;
                    }
                    else
                        break;
                }
                g[i][j]=cnt;
            }
        }
        nx = ny = n;
        printf("%d\n",KM());
    }
    return 0;
}
//hdu3729 I'm Telling the Truth
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector<int>map[70];
int vis[100005];
int mark[100005];
int pre[100005];
int n;
int find(int x)  //二分匹配。(x为girl)
{
    int i;
    int m=map[x].size();
    for(i=0; i<m; i++) //(girl find boy)
    {
        int v=map[x][i];
        if(!vis[v]) //这个男生没被找过。
        {
            vis[v]=1;  //标记找过
            if(pre[v]==-1 ||find(pre[v]))  //没被找过 or 找下一个男生
            {
                pre[v]=x;  //男生i和女生x匹配，这里很重要，保证这个女生不会和其他男生去匹配。
                mark[x]=1;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int partner,girl,boy;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i;
        memset(pre,-1,sizeof(pre));
        memset(mark,0,sizeof(mark));
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            map[i].clear();
            for(int j=x; j<=y; j++)
                map[i].push_back(j);
        }
        int ans=0;
        for(i=n; i>=1; i--)
        {
            memset(vis,0,sizeof(vis));  //每次查找时都初始化。
            if(find(i))  //girl find boy。
                ans++;
        }
        printf("%d\n",ans);
        int res=0;
        for(i=1; i<=n; i++)
        {
            if(mark[i])
            {
                res++;
                if(res==ans)
                    cout<<i<<endl;
                else
                    cout<<i<<" ";
            }
        }
    }
    return 0;
}
