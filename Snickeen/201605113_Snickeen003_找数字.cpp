/*
    二分查找的上下界，又学习了一下STL的upper_bound和lower_bound；
    作为最弱要努力看书努力刷题。
    都是边搜博文边学习，有不对的地方群巨多指点弱啊
*/

//下界
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000007],n,m,t,i,*k;
int main()
{
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        scanf("%d",&m);
        while(m--){
            scanf("%d",&t);
            k=lower_bound(a,a+n,t);
            if(*k==t)printf("%d\n",k-a+1);
            else puts("No!");
        }
    }
    return 0;
}


//上界
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000007],n,m,t,s,r,i,j,*k;
int main()
{
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        scanf("%d",&m);
        while(m--){
            scanf("%d",&t);
            k=upper_bound(a,a+n,t);
            if(*(k-1)==t)printf("%d\n",k-a);
            else puts("No!");
        }
    }
    return 0;
}
