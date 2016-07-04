/*
    题意：从起点到终点间有n个camp，但是只住k个晚上。
        那么，n+1段路要k+1天走完，一天最多走多少路。求最大值的最小值。
    思路：二分答案，然后check
    拓展：1076是简单版
*/
#include<stdio.h>
int t,ca=0,n,m,ans,ff[1011];
int check(int x){
    int i,j,tmp=0,res=1;
    for(i=1;i<=n;i++){
        if(tmp+ff[i]>x){
            res++;
            tmp=ff[i];
        }
        else tmp+=ff[i];
    }
    return res<=m;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        int i,j,k,l=0,r=0;
        scanf("%d %d",&n,&m);
        n++;m++;
        for(i=1;i<=n;i++){
            scanf("%d",&ff[i]);
            if(ff[i]>l)l=ff[i];
            r+=ff[i];
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid)){
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        printf("Case %d: %d\n",++ca,ans);
        for(l=r=0,i=1;i<=n;i++){
            if(l+ff[i]>ans||n-i<m-r-1){
                printf("%d\n",l);
                r++;
                l=ff[i];
            }
            else l+=ff[i];
        }
        printf("%d\n",l);
    }
    return 0;
}
