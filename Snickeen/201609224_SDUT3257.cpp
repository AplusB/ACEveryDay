#include<cstring>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;
typedef long long LL;

const LL maxn = 1e6+5;
LL t,n,m,ans;
LL f[maxn],pr[maxn],vis[maxn],cnt;

void check(LL x,LL id){
    LL i,j,k=1,l,a,b;
    a=b=1;
    for(i=1;i<=pr[0]&&pr[i]*pr[i]*pr[i]<=x;i++){
        if(x%pr[i]==0){
            l=0;
            while(x%pr[i]==0&&x>1){
                x/=pr[i];
                l++;
            }
            if(l%3==1){
                a*=pr[i];
                b*=pr[i]*pr[i];
            }
            else if(l%3==2){
                a*=pr[i]*pr[i];
                b*=pr[i];
            }
        }
    }
    k=sqrt(x);
    if(k*k==x){
        a*=x;
        b*=k;
    }
    else {
        a*=x;
        b*=x*x;
    }
    if(b>1000000)return ;

    if(vis[a]!=id){
        vis[a]=vis[b]=id;
        f[a]=1;
        f[b]=0;
    }
    else {
        f[a]++;
        ans+=f[b];
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    LL ca=0;
    LL i,j,k,l,u,v;
    for(i=2;i<1e2+10;i++){
        if(!pr[i]){
            pr[++pr[0]]=i;
            for(j=i+i;j<1e2+10;j+=i)pr[j]=1;
        }
    }
    cnt=0;
    cin>>t;
    while(t--){
        v=0;++ca;ans=0;

        cin>>n;
        for(i=1;i<=n;i++){
            cin>>u;
            check(u,ca);
        }
        cout<<ans<<endl;
    }
    return 0;
}


/***************************************************
User name: ccut001
Result: Accepted
Take time: 276ms
Take Memory: 1364KB
Submit time: 2016-09-22 18:43:35
****************************************************/
