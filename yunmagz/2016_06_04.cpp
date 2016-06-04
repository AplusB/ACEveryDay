//CCCC初赛
//L1-1
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
  cin>>s;
  double ans=1;
  int i=0;
  int n=s.size();
  int m=n;
  if(s[0]=='-'){
        i++;
        ans*=1.5;
        m--;
  }
  int cnt=0;
  if((s[n-1]-'0')%2==0) ans*=2;
  for(;i<n;i++){
        if(s[i]=='2')
            cnt++;
  }
  printf("%.2lf%%\n",cnt*1.0/m*ans*100);
    return 0;
}
//L1-2
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int h,m;
  scanf("%d:%d",&h,&m);
  if((h==12&&m)||h>=13){
        if(m)
            h++;
        for(int i=0;i<h-12;i++)
            printf("Dang");
        puts("");
  }
  else {
        printf("Only %02d:%02d.  Too early to Dang.\n",h,m);
  }
    return 0;
}
//L1-3
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int n,A,B,a,b,aa,bb;
    cin>>A>>B;
    cin>>n;
    int cnta=0,cntb=0;
    for(int i=0;i<n;i++){
        cin>>a>>b>>aa>>bb;
        if(b==(a+aa)&&bb!=(a+aa))
            cnta++;
        if(b!=(a+aa)&&bb==(a+aa))
            cntb++;
        if(cnta>A){
            puts("A");
            cout<<cntb<<endl;
            break;
        }
        if(cntb>B){
            puts("B");
            cout<<cnta<<endl;
            break;
        }
    }
    return 0;
}
//L1-4
#include <bits/stdc++.h>
using namespace std;
int v[100010];
int vis[100010];
map<int,int>mp;
int cnt[100010];
int gg[100010];
int main()
{
    int n,m,k,a;
    cin>>n;
    for(int i=0;i<n;i++){
        mp.clear();
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a;
            if(!mp[a]){
                mp[a]=1;
                cnt[a]++;
            }
            if(k!=1) gg[a]=1;
        }
    }
    cin>>m;
    int flag=1;
    for(int i=0;i<m;i++){
        cin>>a;
        if((!cnt[a] ||(cnt[a]==1&& !gg[a]))&& !vis[a]){
            if(flag) printf("%05d",a);
            else printf(" %05d",a);
            vis[a]=1,flag=0;
        }
    }
    if(flag) puts("No one is handsome");
    return 0;
}
//L1-5
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"I'm gonna WIN!"<<endl;
    cout<<"I'm gonna WIN!"<<endl;
    cout<<"I'm gonna WIN!"<<endl;
    return 0;
}
//L1-6
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int n,a;
    int j=0,o=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a&1) j++;
        else o++;
    }
    cout<<j<<" "<<o<<endl;
    return 0;
}
//L1-7
#include <bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    string b="GPLT";
    for(int i=0;i<n;i++){
        if(s[i]=='g'||s[i]=='G')
            a[0]++;
        else if(s[i]=='p'||s[i]=='P')
            a[1]++;
        else if(s[i]=='l'||s[i]=='L')
            a[2]++;
        else if(s[i]=='t'||s[i]=='T')
            a[3]++;
    }
    while(1){
            int flag=1;
        for(int i=0;i<4;i++){
            if(a[i]){
                a[i]--;
                flag=0;
                cout<<b[i];
            }
        }
        if(flag) break;
    }
    puts("");
    return 0;
}
//L1-8
#include <bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
  int n;
  cin>>n;
  n--;
  cout<<(n+2)%7+1<<endl;
    return 0;
}
//L2-1
#include <bits/stdc++.h>
using namespace std;
struct node{
    int id,sum,v;
}b[10010];
bool cmp(node a,node b){
    if(a.v==b.v){
        if(a.sum==b.sum)
            return a.id<b.id;
        else
            return a.sum>b.sum;
    }
    else return a.v>b.v;
}
int main()
{
    int n,m,k,a;
    int p;
    cin>>n;
    for(int i=1;i<=n;i++){
        b[i].id=i;
        b[i].v=0;
        b[i].sum=0;
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a>>p;
            p;
            cnt+=p;
            b[a].v+=p;
            b[a].sum++;
        }
        b[i].v-=cnt;
    }
    sort(b+1,b+n+1,cmp);
    for(int i=1;i<=n;i++){
        printf("%d %.2lf\n",b[i].id,b[i].v/100.0);
    }
    return 0;
}
//L2-2
#include <bits/stdc++.h>
using namespace std;
bool dr[110][110];
bool py[110][110];
bool ppy[110][110];
int main()
{
    int n,m,k,a,b,p;
    cin>>n>>k>>m;
    memset(py,false,sizeof py);
    memset(ppy,false,sizeof ppy);
    memset(dr,false,sizeof dr);
    for(int i=0;i<k;i++){
        cin>>a>>b>>p;
        if(p==-1){
            dr[a][b]=1;
            dr[b][a]=1;
        }
        if(p==1){
            ppy[a][b]=1;
            ppy[b][a]=1;
            py[a][b]=1;
            py[b][a]=1;
            for(int j=1;j<=100;j++){
                if(py[a][j]){
                    py[b][j]=1;
                    py[j][b]=1;
                }
                else if(py[b][j]){
                    py[a][j]=1;
                    py[j][a]=1;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(!py[a][b]&&dr[a][b]) puts("No way");
        else if(py[a][b] && !dr[a][b]) puts("No problem");
        else if(!py[a][b]&& !dr[a][b]) puts("OK");
        else if(py[a][b]&&dr[a][b]) puts("OK but...");
//            int flag=0;
//            for(int j=1;j<=n;j++)
//                if(py[a][j]&&py[b][j]) flag=1;
//            if(flag)puts("OK but...");
//            else puts("No way");
//        }
    }
    return 0;
}
//L2-4
#include <bits/stdc++.h>
using namespace std;
int t[10000];
void init(int a,int i){
    t[i]=a;
    while(i>=2){
        if(t[i]<t[i/2]){
            swap(t[i],t[i/2]);
            i/=2;
        }
        else break;
    }
}
int main()
{
    string s,is="is",ad="and",root="root",child="child",parent="parent";
    int n,m,k,a,b,p;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        init(a,i);
    }
    while(m--){
        int aid,bid;
        cin>>a;
        cin>>s;
        if(s==ad){
            cin>>b;
            cin>>s;
            cin>>s;
            for(int i=1;i<=n;i++){
                if(t[i]==a) aid=i;
                if(t[i]==b) bid=i;
            }
            if(aid/2==bid/2) puts("T");
            else puts("F");
        }
        else {
            cin>>s;
            cin>>s;
            if(s==root){
                if(t[1]==a) puts("T");
                else puts("F");
            }
            else if(s==child){
                cin>>s;
                cin>>b;
                for(int i=1;i<=n;i++){
                    if(t[i]==a) aid=i;
                    if(t[i]==b) bid=i;
                }
                if(aid/2==bid) puts("T");
                else puts("F");
            }
            else if(s==parent){
                cin>>s;
                cin>>b;
                for(int i=1;i<=n;i++){
                    if(t[i]==a) aid=i;
                    if(t[i]==b) bid=i;
                }
                if(aid==bid/2) puts("T");
                else puts("F");
            }
        }
    }
    return 0;
}
//L3-2
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<int>mp[10010];
int v[10010];
pii p;
int main()
{
    int n,m,k,a,b;
    cin>>n>>m>>k;
    while(m--){
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    while(k--){
        cin>>a;
        if(!mp[a].size()) puts("0");
        else {
            memset(v,0,sizeof v);
            v[a]=1;
            int ans=0,cnt=0;
            queue<pii>q;
            q.push(make_pair(a,1));
            while(!q.empty()){
                pii g=q.front();
                q.pop();
                for(int i=0;i<mp[g.first].size();i++){
                    if(!v[mp[g.first][i]]){
                        v[mp[g.first][i]]=1;
                        if(g.second>cnt){
                            cnt=g.second;
                            ans=mp[g.first][i];
                        }
                        else if(g.second==cnt&&mp[g.first][i]<ans) ans=mp[g.first][i];
                        q.push(make_pair(mp[g.first][i],g.second+1));
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
