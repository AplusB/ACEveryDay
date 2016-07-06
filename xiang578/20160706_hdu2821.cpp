#include<bits/stdc++.h>
using namespace std;
int n,m,flag,cnt,g[100][100];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
char dir[]="UDLR";
stack<char>st;

int ok(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)
        return 0;
    else
        return 1;
}

int dfs(int x,int y,int now)
{

    if(now>=cnt) flag=1;
    if(flag) return flag;
    int k,tx,ty;

    for(int i=0;i<4;i++)
    {
        if(ok(x+dx[i],y+dy[i])==0||g[x+dx[i]][y+dy[i]]!=0) continue;
        tx=x;
        ty=y;
        while(1)
        {
            tx+=dx[i];
            ty+=dy[i];
            if(ok(tx,ty)==0||g[tx][ty]!=0) break;
        }
        if(ok(tx+dx[i],ty+dy[i])==0||ok(tx,ty)==0||g[tx][ty]==0) continue;
        k=g[tx][ty];
        g[tx+dx[i]][ty+dy[i]]+=k-1;
        g[tx][ty]=0;
        st.push(dir[i]);
        if(dfs(tx,ty,now+1)==1) return flag=1;
        st.pop();
        g[tx][ty]=k;
        g[tx+dx[i]][ty+dy[i]]-=k-1;
    }
    return 0;
}

int main()
{
    char s[100];
    while(~scanf("%d",&n))
    {
        scanf("%d",&m);
        cnt=0;
        memset(g,0,sizeof(g));
        for(int j=0;j<m;j++)
        {
            scanf("%s",s);
            for(int i=0;i<n;i++)
            {
                if(s[i]!='.')   g[i][j]=s[i]-'a'+1;
                cnt+=g[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]==0)
                {
                    flag=0;
                    while(!st.empty()) st.pop();
                    flag=dfs(i,j,0);
                }
                if(flag)
                {
                    printf("%d\n",j);
                    printf("%d\n",i);
                    stack<char>ans;
                    while(!st.empty())
                    {
                        ans.push(st.top());
                        st.pop();
                    }
                    while(!ans.empty())
                    {
                        printf("%c",ans.top());
                        ans.pop();
                    }
                    printf("\n");
                    break;
                }
            }
            if(flag) break;
        }
    }
    return 0;
}
