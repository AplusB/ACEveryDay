//按绝对值排序，贪心走一波
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[500005];
int n,m;
int cmp(int a,int b){
    return abs(a) < abs(b);
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(int i = 0; i < m; ++i)
            scanf("%d",&a[i]);
        sort(a,a + m,cmp);
        
        int res = 1;
        int tmp;
        if(a[0] < 0)
            tmp = -1;
        else
            tmp = 1;
        for(int i = 1; i < m; ++i){
            if(a[i] * tmp < 0){
                res++;
                tmp = -tmp;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
