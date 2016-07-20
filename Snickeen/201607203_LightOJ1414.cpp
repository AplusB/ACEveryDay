/*
    题意：求两个时间间的2.29的个数 
*/
#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
char mon[20][25]={"January","February","March","April","May","June","July","August","September","October","November","December"};  
int check(int y){if((y%400==0)||(y%100!=0&&y%4==0))return 1;else return 0;}
int main()
{
	int t,ca=0,i,j,k,l;
    for(i=0;i<12;i++)mp[mon[i]]=i+1;
    scanf("%d",&t);
    int y,m,t1,t2;char a[25];
    while(t--)  
    {
        scanf("%s%d,%d",a,&m,&y);
        t1=t2=0;
        if(check(y)&&mp[a]>2)y++;
        y--;  
        t1+=(y/4-y/100+y/400);
        scanf("%s%d,%d",a,&m,&y);
        if(check(y)&&(mp[a]>2||(mp[a]==2&&m==29)))y++;
        y--;  
        t2+=(y/4-y/100+y/400);
        printf("Case %d: %d\n",++ca,t2-t1);
    }
    return 0;
}
