#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define INF 0x7ffffff
#define ll long long
using namespace std;
#define N 200100
#define endl '\n'
struct Matrix
{
    long long m[110][110];
    unsigned long long n;
    Matrix(unsigned long long x)
    {
        n=x;
        for(unsigned long long i=0;i<n;i++)
            for(unsigned long long j=0;j<n;j++)
              m[i][j]=0;
    }
};
Matrix operator *(Matrix a,Matrix b)
{
        unsigned long long n=a.n;
        Matrix ans = Matrix(n);
        for(unsigned long long i=0;i<n;i++)
            for(unsigned long long j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    ans.m[i][j]+=(a.m[i][k]*b.m[k][j]%2009)%2009;
        return ans;
}
Matrix operator ^( Matrix a,unsigned long long k)
{
       unsigned long long n=a.n;
       Matrix c(n);
       unsigned long long i, j;
       for(i=0;i<n;i++)
           for(j=0;j<n;j++)
              c.m[i][j]=(i==j);
        for(;k;k>>=1)
        {
            if(k&1) c=c*a;
            a=a*a;
        }
        return c;
}
int main()
{
    long long n,t;
    char c[100];
    cin>>n>>t;
    Matrix A(n*9);
    for(int i=0;i<n;i++)
    {
        scanf("%s",c);
        for(int j=0;j<n;j++) if(c[j]!='0') A.m[i*9+c[j]-'0'-1][j*9]=1;
        for(int j=i*9;j<i*9+8;j++) A.m[j][j+1]=1;
    }
    A=A^t;
    cout<<A.m[0][(n-1)*9]%2009<<endl;
    return 0;
}
