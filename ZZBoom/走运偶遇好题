//poj  1753

#include<cstdio>
#include<queue>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int head,tail;
bool vis[1<<17];
int step[1<<17];
int q[1<<17];

int judge(int x)
{
    if(x>=0&&x<=15)
        return 1;
    return 0;
}

int change[16] =   //16种状态转换，对应4*4的翻子位置
{
    51200,58368,29184,12544,
    35968,20032,10016,4880,
    2248,1252,626,305,
    140,78,39,19
};


int bfs(int x)
{

    memset(vis,0,sizeof(vis));
    memset(step,0,sizeof(step));
    head=0;
    tail=1;

    step[x]=0;
    vis[x]=1;
    q[head]=x;

    while(head<tail)
    {
        int v=q[head];
        head++;
        int ne;

        if(v==0||v==(65535))
        {
            return step[v];
        }
        
        //这波状态真是写到吐血，一开始没怎么注意...
        for(int i=0; i<16; i++)
        {
            ne=v;
            int u=0;
            if(i==0)
            {
                u=(1<<0)|(1<<1)|(1<<4);
            }
            else if(i==2||i==1)
            {
                int a,b,c;
                a=i-1;
                b=i+1;
                c=i+4;
                u=(1<<a)|(1<<b)|(1<<c);
                u^=(1<<i);
            }
            else if(i==3)
            {
                u=(1<<2)|(1<<7);
                u^=(1<<i);
            }
            else if(i==4||i==8)
            {
                int a,b,c;
                a=i-4;
                b=i+1;
                c=i+4;
                u=(1<<a)|(1<<b)|(1<<c);
                u^=(1<<i);
            }
            else if(i==5||i==6||i==9||i==10)
            {
                int a,b,c,d;
                a=i-1;
                b=i+1;
                c=i+4;
                d=i-4;
                u=(1<<a)|(1<<b)|(1<<c)|(1<<d);
                u^=(1<<i);
            }
            else if(i==7||i==11)
            {
                int a,b,c;
                a=i-4;
                b=i-1;
                c=i+4;
                u=(1<<a)|(1<<b)|(1<<c);
                u^=(1<<i);
            }
            else if(i==12)
            {
                u=(1<<8)|(1<<13);
                u^=(1<<i);
            }
            else if(i==13||i==14)
            {
                int a,b,c;
                a=i-4;
                b=i+1;
                c=i-1;
                u=(1<<a)|(1<<b)|(1<<c);
                u^=(1<<i);
            }
            else if(i==15)
            {
                u=(1<<14)|(1<<11);
                u^=(1<<i);
            }
            ne^=u;

            //ne=v^change[i];   //说多了都是泪

            if(!vis[ne])
            {
                vis[ne]=1;
                step[ne]=step[v]+1;
                if(ne==0||ne==(65535))
                {
                    return step[ne];
                }
                q[tail++]=ne;
            }
        }
    }
    return -1;
}
int main()
{
	int i,j;
	char s[5][5];
	while(~scanf("%s",s[0]))
	{
		for(i=1;i<4;i++)
		scanf("%s",s[i]);
		
		int ans=0;
		for(i = 0 ; i < 4 ; ++i)
		{
			for(j = 0 ; j < 4 ; ++j)
			{
				if(s[i][j]=='b')
					ans|=(1<<(i*4+j));
			}
		}
   		int qq=bfs(ans);
		if(qq!=-1)
			printf("%d\n",qq);
		else
			printf("Impossible\n");
	}
 }
/*
bwwb
bbwb
bwwb
bwww
*/

