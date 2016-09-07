#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2500;
const int M=1e6+10;
char s[N],t[N];
int a[N][N],b[N][N];
vector< pair<int,int> >ans;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%s",s);
    scanf("%s",t);
    int n=strlen(s);
    int m=strlen(t);
    for(int i=n;i>0;i--)
    {
        s[i]=s[i-1];
    }
    for(int j=m;j>0;j--)
    {
        t[j]=t[j-1];
    }
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    ans.clear();
    for(int i=m;i>=1;i--)
    {
        for(int j=n;j>=1;j--)
        {
            if(t[i]==s[j]) a[i][j]=a[i+1][j+1]+1;
        }

        for(int j=1;j<=n;j++)
        {
            if(t[i]==s[j]) b[i][j]=b[i+1][j-1]+1;
        }
    }
    for(int i=1;i<=m;)
    {
        int t1=1;
        int t2=1;
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]>a[i][t1]) t1=j;
            if(b[i][j]>b[i][t2]) t2=j;
        }
        //printf("%d %d\n",a[i][t1],b[i][t2]);
        if(a[i][t1]==0&&b[i][t2]==0)
        {
            printf("-1\n");
            return 0;
        }
        if(a[i][t1]>b[i][t2])
        {
            pair<int,int>tmp=make_pair(t1,t1+a[i][t1]-1);
            ans.push_back(tmp);
            i+=a[i][t1];
        }
        else
        {
            pair<int,int>tmp=make_pair(t2,t2-b[i][t2]+1);
            ans.push_back(tmp);
            i+=b[i][t2];
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
