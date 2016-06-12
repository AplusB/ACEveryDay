# include<cstdio>
# include<iostream>
# include<cstring>
# include<algorithm>
using namespace std;
# define MAX 1234
int f[MAX];
int main(void)
{
    int A,B,n;cin>>A>>B>>n;
    if(n==1||n==2)
    {
        printf("1\n");
        return 0;
    }
    f[1]=1;f[2]=1;
    int i;
    for(i=3;i<300;i++)
    {
        f[i]=((A*f[i-1]+B*f[i-2])%7+7)%7;
        if(f[i-1]==1&&f[i]==1) break;
    }
    f[0] = f[i-2];
    printf("%d\n",f[n%(i-2)]);
    return 0;
}
