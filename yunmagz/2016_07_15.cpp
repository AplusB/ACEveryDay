//Codeforces Round #362 (Div. 2)
//A - Pineapple Incident
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
int main()
{
    LL t,s,x;
    cin>>t>>s>>x;
    int flag=1;
    if(t==x) puts("YES");
    else if(x<t){
        puts("NO");
    }
    else{
        x-=t;
        if(x%s==0) puts("YES");
        else if((x-1)%s==0&&x/s>0){
            puts("YES");
        }
        else puts("NO");
    }
    return 0;
}
//B - Barnicle
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
string tmp;
string ad="";
string b="";
bool flag=0;
void solve(){
    for(int i=0; i<tmp.size(); ++i)
    {
        if(tmp[i]=='e')
        {
            flag=1;
            continue;
        }
        if(!flag)
        {
            ad.push_back(tmp[i]);
        }
        else
        {
            b.push_back(tmp[i]);
        }
    }
    int reab=atoi(b.c_str());
    string aaa="";
    int pos;
    flag=0;
    if(reab==0)
    {
        if(ad.size()==3&&ad[2]=='0') cout<<ad.substr(0,1)<<endl;
        else cout<<ad<<endl;
        return;
    }
    for(int i=0; i<ad.size(); ++i)
    {
        if(flag && reab==0)
        {
            int j=i;
            aaa.push_back('.');
            while(j<ad.size())
            {
                aaa.push_back(ad[j]);
                j++;
            }
            break;
        }
        if(flag)
        {
            reab--;
        }
        if(ad[i]=='.')
        {
            pos=i;
            flag=1;
            continue;
        }
        aaa.push_back(ad[i]);
    }
    while(reab)
    {
        aaa.push_back('0');
        reab--;
    }
    bool ss=1;
    for(int i=0;i<aaa.size(); ++i)
    {
        if(aaa[i]=='0' && ss)
        {
            continue;
        }
        ss=0;
        cout<<aaa[i];
    }
}
int main()
{
    cin>>tmp;
    solve();
    return 0;
}
//C - Lorenzo Von Matterhorn
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
map<LL,LL>p;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
            int id;
        scanf("%d",&id);
        if(id==1){
            LL u,v,w;
            scanf("%I64d%I64d%I64d",&u,&v,&w);
            while(u!=v){
                if(u<v){
                    p[v]+=w;
                    v/=2;
                }
                else {
                    p[u]+=w;
                    u/=2;
                }
            }
        }
        else {
            LL u,v;
            LL ans=0;
            scanf("%I64d%I64d",&u,&v);
            while(u!=v){
                if(u<v){
                    if(p[v]) ans+=p[v];
                    v/=2;
                }
                else {
                    if(p[u]) ans+=p[u];
                    u/=2;
                }
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
//D - Puzzles
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PII pair<int,int>
int v[100010],fa[100010];
vector<int>g[100010];
double ans[100010];
int dfs(int x){
if(v[x]) return v[x];
    int cnt=1,h=g[x].size();
    for(int i=0;i<h;i++){
        cnt+=dfs(g[x][i]);
    }
    return v[x]=cnt;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&fa[i]);
        g[fa[i]].pb(i);
    }
    dfs(1);
    ans[1]=1.0;
printf("%.6lf ",ans[1]);
    for(int i=2;i<=n;i++) {
        ans[i]=ans[fa[i]]+1.0+(v[fa[i]]-v[i]-1)/2.0;
printf("%.6lf ",ans[i]);
        }
    return 0;
}
