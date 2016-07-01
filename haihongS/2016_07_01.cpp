#include <cstdio>

int main()
{
    int n,a,b;
    while(~scanf("%d%d%d",&n,&a,&b))
    {
        b=(b%n+n)%n;
        a-=1;
        a+=b;
        printf("%d\n",a%n+1);
    }
    return 0;
}
