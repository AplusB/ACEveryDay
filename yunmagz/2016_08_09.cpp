// 2016 Multi-University Training Contest 7
//1002 Balls and Boxes
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
int main(){
    LL n,m;
    while(~scanf("%I64d%I64d",&n,&m)&&n&&m){
        LL fz=n*(m-1),fm=m*m;
        LL g=__gcd(fz,fm);
        printf("%I64d/%I64d\n",fz/g,fm/g);
    }
    return 0;
}
// 1005 Elegant Construction 
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
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
struct node {
    int x,id;
}a[1010];
bool cmp(node a,node b){
    return a.x<b.x;
}
int ans[2][1000010];
int main(){
    int t,n,cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i].x);
            a[i].id=i+1;
        }
        sort(a,a+n,cmp);
        int flag=1;
        int cnt=0;
        for(int i=0;i<n&&flag;i++){
            if(a[i].x>i) flag=0;
            for(int j=0;j<a[i].x;j++){
                ans[0][cnt]=a[i].id;
                ans[1][cnt]=a[j].id;
                cnt++;
            }
        }
        printf("Case #%d: ",cas++);
        if(flag){
            puts("Yes");
            printf("%d\n",cnt);
            for(int i=0;i<cnt;i++) printf("%d %d\n",ans[0][i],ans[1][i]);
        }
        else puts("No");
    }
    return 0;
}
//1008 Hearthstone 
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
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
bool cmp(int a,int b){
    return a>b;
}
LL jc[25];
int a[25];
int n,m,p;
LL dfs(int sxcp,int s,int cjz){
    int now=0,tmp=0,cnt=sxcp+cjz,tot=0;
    for(int i=0;i<m;i++){
        if(s&(1<<i)){
            now+=a[i];
            tot++;
            continue;
        }
        if(cnt){
            tmp+=a[i];
            cnt--;
        }
    }
    if(now>=p) return jc[m-tot+sxcp];
    if(now+tmp<p) return 0;
    if(cjz==0||(sxcp==0&&s==((1<<m)-1))) return 0;
    LL ans=0;
    if(sxcp) ans+=dfs(sxcp-1,s,cjz+1)*sxcp;
    for(int i=0;i<m;i++){
        if(!(s&(1<<i))){
            ans+=dfs(sxcp,s|(1<<i),cjz-1);
        }
    }
    return ans;
}
int main(){
    int t;
    jc[0]=1;
    for(int i=1;i<=20;i++) jc[i]=i*jc[i-1];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&p,&n,&m);
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        sort(a,a+m,cmp);
        LL z=dfs(n,0,1);
        LL g=__gcd(z,jc[n+m]);
        printf("%I64d/%I64d\n",z/g,jc[n+m]/g);
    }
    return 0;
}
//1010 Joint Stacks
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
struct node{
    int x,id;
    bool operator < (const node &a) const {
        return id<a.id;
    }
};
priority_queue<node>q[2];
char s[10],a[5],b[5];
int main(){
    int n,m,cas=1;
    while(~scanf("%d",&n)&&n){
        while(!q[0].empty()) q[0].pop();
        while(!q[1].empty()) q[1].pop();
        int A=0,B=1;
        node h;
        printf("Case #%d:\n",cas++);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            if(s[1]=='u'){
                scanf("%s%d",a,&h.x);
                h.id=i;
                if(a[0]=='A') q[A].push(h);
                if(a[0]=='B') q[B].push(h);
            }
            else if(s[1]=='o'){
                scanf("%s",a);
                if(a[0]=='A'){
                    h=q[A].top();
                    q[A].pop();
                    printf("%d\n",h.x);
                }
                if(a[0]=='B'){
                    h=q[B].top();
                    q[B].pop();
                    printf("%d\n",h.x);
                }
            }
            else {
                scanf("%s%s",a,b);
                if(SZ(q[0])<SZ(q[1])){
                    while(!q[0].empty()){
                        q[1].push(q[0].top());
                        q[0].pop();
                    }
                    if(a[0]=='A'){
                        A=1;
                        B=0;
                    }
                    else {
                        A=0;
                        B=1;
                    }
                }
                else {
                    while(!q[1].empty()){
                        q[0].push(q[1].top());
                        q[1].pop();
                    }
                    if(a[0]=='A'){
                        A=0;
                        B=1;
                    }
                    else {
                        A=1;
                        B=0;
                    }
                }
            }
        }
    }
    return 0;
}
