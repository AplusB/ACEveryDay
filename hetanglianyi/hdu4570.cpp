#include<cstdio>   
#include<cstring>   
#include<cmath>   
#include<algorithm>   
#include<iostream>   
using namespace std;  
   
const int N = 70;  
long long f[N];  
long long a[N];  
int n;  
int main()  
{  
    int t;  
    scanf("%d", &t);  
    while(t--)  
    {  
        scanf("%d", &n);  
        long long re = 0;  
        for(int i = 1; i <= n; i++)  
        {  
            cin >> a[i];  
            re += a[i] * 2;  
        }  
   
        f[n] = a[n] * 2;  
        f[n+1] = 0;  
        for(int i = n-1; i >= 1; i--)  
        {  
            f[i] = ((1LL << 62) - 1);  
            for(int j = i+1; j <= min(i+20,n+1); j++)  
            {  
                f[i] = min(f[i], f[j] + a[i] * (1 << (j-i)));  
            }  
        }  
   
        cout << min(re, f[1]) << endl;  
    }  
    return 0;  
}  
