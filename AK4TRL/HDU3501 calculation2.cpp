//求1~n里面比n小，但是与n不互素的数的总和。
#include <iostream>
#include <cmath>
using namespace std;
int cals(int x){
    int res=x;
    for(int i = 2; i < (int)sqrt(x * 1.0) + 1; ++i)
        if(!(x % i)){
            res=res/i*(i-1);
            while(x%i==0)
            x/=i;
        }
        if(x>1)
        res=res/x*(x-1);
        return res;
}
int main(void){
    long long n;
    while(scanf("%I64d", &n), n){
        long long sum = n * (n + 1) / 2 - n, res;
        res = sum - (n * cals(n) / 2);
        printf("%I64d\n", res % 1000000007);
    }
    return 0;
}
