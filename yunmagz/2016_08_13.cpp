//hdu5384 Danganronpa
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=258280327;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
struct Trie
{
    int next[500010][26],fail[500010],ed[500010];
    int root,L;
    int newnode()
    {
        for(int i = 0; i < 26; i++)
            next[L][i] = -1;
        ed[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        ed[now]++;
    }
    void build()
    {
        queue<int>Q;
        //fail[root] = root;
        for(int i = 0; i < 26; i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0; i < 26; i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    LL query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        LL res = 0;
        for(int i = 0; i < len; i++)
        {
            now = next[now][buf[i]-'a'];
            int temp = now;
            while( temp != root )
            {
                res += ed[temp];
                //ed[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
    void debug()
    {
        for(int i = 0; i < L; i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],ed[i]);
            for(int j = 0; j < 26; j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};
char buf[10010],s[100010][10010];
Trie ac;
int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        ac.init();
        for(int i = 0; i < n; i++) scanf("%s",s[i]);
        for(int i = 0; i < m; i++){
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        for(int i = 0; i < n; i++) printf("%lld\n",ac.query(s[i]));
    }
    return 0;
}
