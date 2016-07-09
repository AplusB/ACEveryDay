#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const int maxit=10;

int place(int i,int j);
int fresh(int i,int j,int num,int flag);
int dfs(int now);

char pre[maxit][maxit];
int mapp[maxit][maxit];
int row[maxit][maxit],col[maxit][maxit],brick[maxit][maxit];
int store[100],loca;

int main()
{
    char s[100];
    int t=0;
    while(scanf("%s",s)!=EOF)
    {
        memset(store,-1,sizeof(store));
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(brick,0,sizeof(brick));
        loca=0;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(i!=0||j!=0) scanf("%s",s);
                if(s[0]=='?') mapp[i][j]=0;
                else mapp[i][j]=s[0]-'0';
                if(mapp[i][j]==0)
                    store[loca++]=9*i+j;
                else
                {
                    row[i][mapp[i][j]]=1;
                    col[j][mapp[i][j]]=1;
                    brick[place(i,j)][mapp[i][j]]=1;
                }
            }
        }
        dfs(0);
        if(t) printf("\n");
        else t++;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
                {
                    if(j) printf(" ");
                    printf("%d",mapp[i][j]);
                }
            printf("\n");
        }
    }
    return 0;
}

int place(int i,int j)
{
    if(i<3)
    {
        if(j<3)
            return 0;
        else if(j<6)
            return 1;
        else
            return 2;
    }
    else if(i<6)
    {
        if(j<3)
            return 3;
        else if(j<6)
            return 4;
        else
            return 5;
    }
    else
    {
        if(j<3)
            return 6;
        else if(j<6)
            return 7;
        else
            return 8;
    }
}

int dfs(int now)
{

    if(now==loca)
        return 1;
    for(int i=1; i<10; i++)
    {
        if(row[store[now]/9][i]==0 && col[store[now]%9][i]==0
                && brick[place(store[now]/9,store[now]%9)][i]==0)
        {
            mapp[store[now]/9][store[now]%9]=i;
            fresh(store[now]/9,store[now]%9,i,1);
            int ans=dfs(now+1);
            if(ans==1) return 1;
            else
                fresh(store[now]/9,store[now]%9,i,0);
        }
    }
    return -1;
}

int fresh(int i,int j,int num,int flag)
{
    row[i][num]=flag;
    col[j][num]=flag;
    brick[place(i,j)][num]=flag;
    return 0;
}
