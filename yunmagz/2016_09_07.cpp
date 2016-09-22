//Codeforces Round #278 (Div. 2)
//C - Fight the Monster
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define INF 0x7fffffff
int min(int x,int y)
{
    if(x<y)
        return x;
    return y;
}
int main()
{
    int wh,wa,wd,mh,ma,md,ch,ca,cd;
    scanf("%d %d %d",&wh,&wa,&wd);
    scanf("%d %d %d",&mh,&ma,&md);
    scanf("%d %d %d",&ch,&ca,&cd);
    int cost = INF;
    
    for(int da=0;da<=200;da++)
    {
        for(int dd=0;dd<=200;dd++)
        {
            for(int dh=0;dh<=1000;dh++)
            {
            if(wa+da-md<=0) continue;
            int t = (mh-1)/(wa+da-md)+1;
            if(dh<t*(ma-wd-dd)-wh+1)
                 continue;
            cost = min(cost,ca*da+cd*dd+ch*dh);
            }
        }
    }
    printf("%d\n",cost);
    return 0;
}
