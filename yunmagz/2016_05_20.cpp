//lightoj 1060 - nth Permutation
#include <bits/stdc++.h>
using namespace std;
#define LL long long
string s;
int v[30],l;
LL sum,n,jc[30];
void solve(){
    for(int i=l;i>0;i--){
        for(int j=0;j<26;j++){
            if(!v[j]) continue;
            LL tot=v[j]*jc[i-1];
            for(int k=0;k<26;k++) tot/=jc[v[k]];
            if(n>tot) n-=tot;
            else {
                v[j]--;
                printf("%c",'a'+j);
                break;
            }
        }
    }
    puts("");
}
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int t,cas=1;
    jc[0]=1;
    for(int i=1;i<=20;i++) jc[i]=jc[i-1]*i;
    cin>>t;
    while(t--){
        cin>>s>>n;
        memset(v,0,sizeof v);
        l=s.size();
        printf("Case %d: ",cas++);
        for(int i=0;i<l;i++) v[s[i]-'a']++;
        sum=jc[l];
        for(int i=0;i<26;i++) sum/=jc[v[i]];
        if(n>sum) puts("Impossible");
        else solve();
    }
    return 0;
}
