//Codeforces Round #366 (Div. 2)
//A - Hulk 
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
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        if(i&1){
            printf("I love ");
        }
        else {
            printf("I hate ");
        }
        if(i<n-1) printf("that ");
        else printf("it");
	}
	return 0;
}
//B - Spider Man 
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
	int n,a;
	cin>>n;
	LL ans=0;
	for(int i=0;i<n;i++){
        cin>>a;
        ans+=a-1;
        if(ans&1) puts("1");
        else puts("2");
	}
	return 0;
}
//C - Thor 
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
int v[300010],a[300010],x[300010];
set<int>s[300010];
int main(){
    set<int>::iterator it;
	int n,q,id;
	cin>>n>>q;
	int ans=0,mx=0,cnt=1;
	for(int j=1;j<=q;j++){
        scanf("%d%d",&id,&x[j]);
        if(id==1){
            s[x[j]].insert(cnt);
            a[cnt++]=x[j];
            ans++;
        }
        else if(id==2){
            ans-=SZ(s[x[j]]);
            for(it=s[x[j]].begin();it!=s[x[j]].end();it++) v[*it]=1;
            s[x[j]].clear();
        }
        else {
            if(x[j]>mx){
                for(int i=mx+1;i<=x[j];i++)
                    if(!v[i]){
                        s[a[i]].erase(i);
                        ans--;
                        v[i]=1;
                    }
                mx=x[j];
            }
        }
        printf("%d\n",ans);
	}
	return 0;
}

