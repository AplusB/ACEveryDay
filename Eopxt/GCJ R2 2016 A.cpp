#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define sqr(x) ((x)*(x))
#define mem(a,x) memset(a,x,sizeof(a))
#define REP(i,n) for (int i=0; i<(n); i++)
#define rep(i,n) for (int i=1; i<=(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for (int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
typedef long long lld;
typedef pair<int,int> pii;
typedef set<int>::iterator setIter;

string str[3][20];

char *alp="PRS";

string dp(int ch,int i) {
    string &ret=str[ch][i];
    if (ret!="") return ret;
    if (i==0) return ret=alp[ch];
    if (ch==0) ret=min(dp(1,i-1)+dp(0,i-1),dp(0,i-1)+dp(1,i-1));
    if (ch==1) ret=min(dp(1,i-1)+dp(2,i-1),dp(2,i-1)+dp(1,i-1));
    if (ch==2) ret=min(dp(0,i-1)+dp(2,i-1),dp(2,i-1)+dp(0,i-1));
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int cas; scanf("%d",&cas);
    rep(cs,cas) {
        int nn,r,p,s;
        scanf("%d%d%d%d",&nn,&r,&p,&s);
        int n=nn;
        bool flag=true;
        while (n>=2) {
            int tmp=(r+p+s)/4;
            int p1=r-tmp;
            int s1=p-tmp;
            int r1=s-tmp;
            if (p1<0 || s1<0 || r1<0) {flag=false; break;}
            n-=2; p=p1; r=r1; s=s1;
        }
        if (p==2 || r==2 || s==2) flag=false;
        printf("Case #%d: ",cs);
        if (!flag) {
            printf("IMPOSSIBLE\n");
        }
        else {
            int ch;
            if (n==0) {
                if (p==1) ch=0;
                if (r==1) ch=1;
                if (s==1) ch=2;
            }
            else {
                if (p==0) ch=1;
                if (r==0) ch=2;
                if (s==0) ch=0;
            }
            //if (cs==9) fprintf(stderr,"~%d\n",ch);
            cout<<dp(ch,nn)<<endl;
        }
    }
    return 0;
}
