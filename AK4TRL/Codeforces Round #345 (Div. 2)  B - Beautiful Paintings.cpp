//找数组内重新排列后最多的升序数
//计算一下出现次数，次数最多的可能作为开头，可忽略
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[1005],b[1005];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	while(cin >> n){
		int ans=0;
		memset(b,0,sizeof b);
		for(int i = 0; i < n; ++i){
			scanf("%d",&a[i]);
			b[a[i]]++;
		}
		sort(b,b+1005,cmp);
		for(int i = 1; i < 1005; ++i)
			ans+=b[i];
		printf("%d\n",ans);
	}
	
	return 0;
}
