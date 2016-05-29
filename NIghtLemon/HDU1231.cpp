#include<bits/stdc++.h>
#define N 10007
using namespace std;

int n;
int a[N],b[N],fl,ans,fans;


void init(){
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}

void calc(){
	b[1] = 1;fl = 1;ans = a[1]; fans = a[1];
	for(int i=2;i<=n;i++){
		if(a[i-1]>0){
			a[i] +=a[i-1];
			b[i] = b[i-1];
			if(a[i]>ans){
				fl = i;
				fans = a[i] - a[i-1];
				ans = a[i];
			}
		} else{
			b[i] = i;
			if(a[i]>ans){
				fl = i;
				fans = a[i];
				ans = a[i];
			}
		}
	} 	
}

int main() 
{
	while(scanf("%d",&n) && n){
		init();
		calc();
		if(ans<0) printf("%d %d %d\n",0,a[1],a[n]);
		else printf("%d %d %d\n",ans,a[b[fl]],fans);
	}
	
	
	return 0;
}
