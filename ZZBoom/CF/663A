//思路就是一次不过，多交几次就过了。


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define ls 2*i
#define rs 2*i+1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define w(a) while(a)
#define LL long long
const double pi = acos(-1.0);
#define Len 200005
#define mod 19999997
const int INF = 0x3f3f3f3f;
#define exp 1e-6


char ss[300];

int main()
{
    int flag,len;
    int sum1,sum2;
    gets(ss);

    len=strlen(ss);

    flag=0;
    int n;
    n=sum2=0;
    sum1=1;

    for(int i=0; i<len; i++)
    {
        if(ss[i]=='+')
        {
            sum1++;
        }
        else if(ss[i]=='-')
        {
            sum2++;
        }
        else if(ss[i]>='0'&&ss[i]<='9')
        {
            n=n*10+ss[i]-'0';
        }
    }
 //   printf("%d\n",n);

    int x1,x2;

    x1=sum1-sum2*n;
    x2=sum1*n-sum2;

    if(x1>n||n>x2)
    {
        printf("Impossible\n");
        return 0;
    }
    printf("Possible\n");

    int x;
    int y;

    x=y=0;

    for(x=sum1*n; x>=sum1; x--)
    {
        y=x-n;
        if(sum2<=y&&y<=sum2*n)
            break;
    }

    int y1,y2;

    x1=x/sum1;
    x2=x%sum1;

    if(sum2)
    {
        y1=y/sum2;
        y2=y%sum2;
    }

    if(x2)
    {
        printf("%d",x1+1);
        x2--;
    }
    else
        printf("%d",x1);

    int flat;

    for(int i=1; i<len; i++)
    {
        if(ss[i]=='-')
            flat=0;
        if(ss[i]=='+')
            flat=1;
        if(ss[i]=='?')
        {
            if(flat)
            {
                if(x2)
                {
                    printf("%d",x1+1);
                    x2--;
                }
                else
                    printf("%d",x1);
            }
            else
            {
                if(y2)
                {
                    printf("%d",y1+1);
                    y2--;
                }
                else
                    printf("%d",y1);
            }
        }
        else
            printf("%c",ss[i]);
    }
    return 0;
}


/*

? - ? + ? - ? - ? = 20

? - ? + ? + ? + ? + ? + ? = 5

*/

