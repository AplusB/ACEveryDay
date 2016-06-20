#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int N = 2010;  
const int mod = 1007;  
int f[N][N];    
int main()  
{  
    memset(f, 0, sizeof(f));  
    for(int i = 1; i < N; i++)  
        f[i][1] = i % mod;   
    for(int i = 2; i < N; i++)
    {  
        f[i][i] = 1;  
        for(int j = 2; j < i; j++)  
            f[i][j] = (f[i-1][j] + f[i-1][j-1]) % mod;  
    } 
    int T;  
    scanf("%d", &T);  
    while(T--)  
    {  
        int n, m;  
        scanf("%d%d", &m, &n);  
        printf("%d\n", f[n][m]);  
    }  
    return 0;  
}  
