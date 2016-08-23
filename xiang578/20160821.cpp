#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,_,use[30],in[30],out[30],g[30][30],vis[30];
void dfs(int x)
{
    vis[x]=1;
    for(int i=0; i<26; i++)
    {
        if(g[x][i])
        {
            g[x][i]-=1;
            dfs(i);
        }
    }
}
int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(use,0,sizeof(use));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            int u=s[0]-'a';
            int v=s[s.size()-1]-'a';
            use[u]=use[v]=1;
            in[v]++;
            out[u]++;
            g[u][v]++;
        }
        int st=-1,f1=0,f2=0;//st出度比入度大1的点，f1出度比入度大1的点的个数，f2入度比出度大1的点。
        for(int i=0; i<26; i++)
        {
            if(use[i]==0) continue;
            if(in[i]==out[i])
            {
                if(st==-1) st=i;
            }
            else if(in[i]==out[i]+1) f2++;
            else if(in[i]+1==out[i])
            {
                f1++;
                st=i;
            }
            else
            {
                f1=-1;
                f2=-1;
            }
            if(f1==-1&&f2==-1) break;
            if(f1>=2||f2>=2) break;
        }
        //printf("%d %d\n",f1,f2);
        if(f1>=2||f2>=2||f1==-1)
        {
            puts("The door cannot be opened.");
        }
        else if(f1==1&&f2!=1)
        {
            puts("The door cannot be opened.");
        }
        else if(f1!=1&&f2==1)
        {
            puts("The door cannot be opened.");
        }
        else
        {
            dfs(st);
            int ok=1;
            for(int i=0; i<26; i++)
            {
                if(vis[i]==0&&use[i])
                {
                    ok=0;
                    break;
                }
            }
            if(ok) puts("Ordering is possible.");
            else puts("The door cannot be opened.");
        }
    }
    return 0;
}
