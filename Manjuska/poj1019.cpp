#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a1[32000] ;        
__int64 a[32000] ;   
int num[150000];   
int main()
{
    int i;
    a1[0]=0 ;
    a1[1]=1;
    for ( i = 2 ; i < 32000 ; i ++ )
        a1[i] = a1[i-1] + (int)log10(1.0*i)+1;   
    a[0]=1;
    for ( i = 1 ; i < 32000 ; i ++ )
        a[i]=a[i-1]+a1[i-1];                   
    int k = 1;
    for ( i = 1 ; i < 31300 ; i ++ )
    {
        char str[20];
        
        str[0]='0';
        int ti = i ;
        int len = 0 ;
        while (ti)
        {
            str[len]=ti%10+'0';
            ti=ti/10;
            len++;
        }
        while ( len -- )
        {
            num[k]=str[len]-'0';
            k++;
        }
    }
    int t;
    cin >> t;
    while ( t-- )
    {
        int mn;
        cin >>mn;
        for ( i =1; i < 32000 ; i ++ )
            if ( a[i]>=mn )
                break;
        if ( a[i] ==mn )
            cout<<1<<endl;
        else
        {
            cout<<num[mn-a[i-1]+1]<<endl;
        }
    }
    return 0;
}
