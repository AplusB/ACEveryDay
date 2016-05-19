#include<bits/stdc++.h>
using namespace std;
int a[10007] , tot , ans , t , flag , n;
int BSearch(int *array, int size, int key)
{
    int l=0,r=size-1;
    int m, pos=0;       //pos记录第一个大于key的元素位置
    while(l<r)
    {
    	m=(l+r)>>1;
        if(array[m] <= key){
            l = m+1;
            pos = l;
        }
        else{
            r = m;         
            pos = r;              
        }
    }
    return pos;
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		tot = 1;
		a[0] = 30007;
		for(int i=1;i<=n;i++){
			scanf("%d",&t);
			flag = BSearch(a,tot+1,t);
			if(flag<tot)
				a[flag] = t;
			else
				a[tot++] = t;
		}
		printf("%d\n",tot);
	}
	
}
