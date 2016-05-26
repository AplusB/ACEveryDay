//CF#354 div.2
//A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a==1||a==n) ans=max(ans,max(i-1,n-i));
    }
    cout<<ans<<endl;
    return 0;
}
//B
#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int n,t;
void solve(int i,int j,int x){
    if(i>n) return ;
    a[i][j]+=x;
    if(a[i][j]>(1<<n)){
        int y=a[i][j]-(1<<n);
        a[i][j]=(1<<n);
        solve(i+1,j,y/2);
        solve(i+1,j+1,y/2);
    }
}
int main()
{
    cin>>n>>t;
    int ans=0;
    for(int i=0;i<t;i++) solve(1,1,1<<n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(a[i][j]==(1<<n))
                ans++;
    cout<<ans<<endl;
    return 0;
}
//C
#include <bits/stdc++.h>
using namespace std;
string ss,s;
int main()
{
    int n,k;
    cin>>n>>k;
    cin>>ss;
    int ans=1;
    s="a";
    s+=ss;
    s.append("a");
    for(int i=0,j=0,cnt=0;i<=n+1;i++){
        if(s[i]=='a') cnt++;
        if(cnt==k+2){
            ans=max(ans,i-j-1);
            j++;
            while(s[j]=='b') j++;
            cnt--;
        }
        if(i==n+1&&j==0) ans=n;
    }
    s="b";
    s+=ss;
    s.append("b");
    for(int i=0,j=0,cnt=0;i<=n+1;i++){
        if(s[i]=='b') cnt++;
        if(cnt==k+2){
            ans=max(ans,i-j-1);
            j++;
            while(s[j]=='a') j++;
            cnt--;
        }
        if(i==n+1&&j==0) ans=n;
    }
    cout<<ans<<endl;
    return 0;
}
//D
#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int d[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
char s[1010][1010];
bool c[1010][1010][4];
int dis[1010][1010][4];
struct node{
    int x,y,d;
    node(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
};
void bfs(int sx,int sy,int n,int m)
{
    memset(dis,INF,sizeof(dis));
    queue<node>q;
    dis[sx][sy][0]=0;
    q.push(node(sx,sy,0));
    while(!q.empty())
    {
        node p=q.front();
        q.pop();
        if(dis[p.x][p.y][(p.d+1)%4]>dis[p.x][p.y][p.d]+1)
        {
            dis[p.x][p.y][(p.d+1)%4]=dis[p.x][p.y][p.d]+1;
            q.push(node(p.x,p.y,(p.d+1)%4));
        }
        for(int i=0;i<4;i++)
        {
            int tx=p.x+d[i][0];
            int ty=p.y+d[i][1];
            if(tx>=0 && tx<n && ty>=0 && ty<m && c[p.x][p.y][(i+p.d)%4] && c[tx][ty][(i+p.d+2)%4])
                if(dis[tx][ty][p.d]>dis[p.x][p.y][p.d]+1)
                {
                    dis[tx][ty][p.d]=dis[p.x][p.y][p.d]+1;
                    q.push(node(tx,ty,p.d));
                }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char t=s[i][j];
            if(t=='+'||t=='-'||t=='>'||t=='U'||t=='L'||t=='D')c[i][j][0]=1;
            if(t=='+'||t=='|'||t=='^'||t=='R'||t=='L'||t=='D')c[i][j][1]=1;
            if(t=='+'||t=='-'||t=='<'||t=='R'||t=='U'||t=='D')c[i][j][2]=1;
            if(t=='+'||t=='|'||t=='v'||t=='R'||t=='U'||t=='L')c[i][j][3]=1;
        }
    int st[2],ed[2];
    for(int i=0;i<2;i++){
        cin>>st[i];
        st[i]--;
    }
    for(int i=0;i<2;i++){
        cin>>ed[i];
        ed[i]--;
    }
    bfs(st[0],st[1],n,m);
    int res=INF;
    for(int i=0;i<4;i++)
        res=min(res,dis[ed[0]][ed[1]][i]);
    cout<<(res==INF?-1:res)<<endl;
    return 0;
}
