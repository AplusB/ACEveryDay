//CF#355Div.2
//A
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,h,a;
    cin>>n>>h;
    int ans=n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>h) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
//B
#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
    int n,h,k,a;
    cin>>n>>h>>k;
    LL ans=0,now=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(now+a<k) {
            now+=a;
            continue;
        }
        else if(now+a>h){
            ans+=now/k;
            if(now) ans++;
            now=0;
        }
        now+=a;
        ans+=now/k;
        now%=k;
    }
    if(now) ans++;
    cout<<ans<<endl;
    return 0;
}
//C
#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e9+7;
int a[100010],cnt[10];
int main(){
    for(int g=0;g<=6;g++)
    for(int i=0;i<64;i++)
        for(int j=0;j<64;j++)
            if((i&j)==(1<<g)-1)
                cnt[g]++;
    string s;
    cin>>s;
    int n=s.size();
    LL ans=1;
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9') a[i]=s[i]-'0';
        else if(s[i]>='A'&&s[i]<='Z') a[i]=s[i]-'A'+10;
        else if(s[i]>='a'&&s[i]<='z') a[i]=s[i]-'a'+36;
        else if(s[i]=='-') a[i]=62;
        else if(s[i]=='_') a[i]=63;
        int ct=0;
        for(int j=0;j<6;j++)
            if(a[i]&(1<<j)) ct++;
//        cout<<cnt[ct]<<endl;
//        cout<<ct<<endl;
        ans*=cnt[ct];
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
//D
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int inf=0x3f3f3f3f;
int v[310][310];
int ans[310][310];
int dis[310][310];
vector<pair<int,int> >s[90010];
int main(){
    int n,m,p,a;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a;
            s[a].pb(mp(i,j));
        }
    }
    memset(ans,inf,sizeof ans);
    s[0].pb(mp(1,1));
    for(int i=0;i<=p;i++){
        int l=s[i].size();
        for(int j=0;j<l;j++){
            int x=s[i][j].first;
            int y=s[i][j].second;
            if(x==1&&y==1&&ans[x][y]==0) ans[x][y]=inf;
            for(int k=1;k<=n;k++)
                if(v[k][y]==i) ans[x][y]=min(ans[x][y],dis[k][y]+abs(k-x));
        }
        for(int j=0;j<l;j++){
            int x=s[i][j].first;
            int y=s[i][j].second;
            for(int k=1;k<=m;k++)
            if(v[x][k]!=i+1){
                v[x][k]=i+1;
                dis[x][k]=ans[x][y]+abs(k-y);
            }
            else dis[x][k]=min(dis[x][k],ans[x][y]+abs(k-y));
        }
    }
    cout<<ans[s[p][0].first][s[p][0].second]<<endl;
    return 0;
}
