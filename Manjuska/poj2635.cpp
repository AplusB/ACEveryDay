#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N=101;
const int MAXN=1000010;
char str[N];
bool isPrim[MAXN];
int key[N],L,prime[MAXN],data[N];

void initPrime()
{
    int i,k;
    memset(isPrim,0,sizeof(isPrim));
    isPrim[0]=0;
    isPrim[1]=0;
    k=0;
    for(i=2;i<MAXN;i++)
    {
        if(!isPrim[i])
        {
            prime[k++]=i;
            int j=2;
            while(i*j<MAXN)
            {
                isPrim[i*j]=1;
                j++;    
            }
        }
    }
}

int converse(char *a,int len)
{
    int i,j,l,k;
    if(0 == len%3)
        l=len/3;
    else
        l=len/3+1;
    k=l;
    int tmp=1;
    for(j=len-1;j>=0;j-=3)
    {
        l--;
        data[l]=0;
        tmp=1;
        
        for(i=j;i>=(j-2) && i>=0;i--)
        {
            data[l]+=(a[i]-'0')*tmp;
            tmp*=10;
        }
    }
    return k;
}
bool div(int *a,int t,int len)
{
    int result=0;
    for(int i=0;i<len;i++)
    {
        result=(result*1000+a[i])%t;
    }
    if(result)
        return false;
    return true;
}
int main()
{
    int j,len;
    initPrime();
    while(1)
    {
        memset(str,'\0',sizeof(str));
        scanf("%s%d",str,&L);
        if(0 == L)
            break;
        len=strlen(str);
        len=converse(str,len);
        bool flag=true;
        for(j=0;prime[j]<L;j++)
        {
            if(div(data,prime[j],len))
            {
                flag=false;
                break;
            }
        }
        if(!flag)
            printf("BAD %d\n",prime[j]);
        else
            printf("GOOD\n");
    }
    return 0;
}
