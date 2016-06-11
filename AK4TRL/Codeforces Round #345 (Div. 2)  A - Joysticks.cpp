#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a1, a2;
int main(){
	scanf("%d%d",&a1,&a2);
	int ans = 0;
	while(a1!=0 && a2!=0){
		if(a1==1 && a2==1)
		  break;
		ans++;
		if(a1<a2)
		  swap(a1,a2);
		a1=max(0,a1-2);
		a2++;
	}
	printf("%d",ans);
	
	return 0;
}
