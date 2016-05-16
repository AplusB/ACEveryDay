/*
    一开始没注意数据范围，用的int，结果爆long long，后来改成ull
    这里求欧拉函数并没有用经典的线性筛，倒是类似于质数的埃拉托色尼筛法 
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 5000000+7
unsigned long long euler[N],n,m,i,j,k,l;

void get(){  
    euler[1] = 1;  
    for(i=2;i<N;i++)euler[i] = i;  
    for(i=2;i<N;i++)  
        if(euler[i]==i)  
            for(j=i;j<N;j+=i) euler[j]=euler[j]/i*(i - 1);//先进行除法是为了防止中间数据的溢出  
    for(i=1;i<N;i++)euler[i]=euler[i]*euler[i],euler[i]+=euler[i-1];
}

int main()
{
    get();
    scanf("%llu",&n);
    for(i=1;i<=n;i++){
        scanf("%llu %llu",&j,&k);
        printf("Case %llu: %llu\n",i,euler[k]-euler[j-1]);
    }
    return 0;
}
