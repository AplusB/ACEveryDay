#include<bits/stdc++.h>
using namespace std;

int N,i,j;
double L,C,T,bt;
double vr,vt1,vt2,tr,tt;
int a[107];
double b[107];

void solve(int x){
	/*for(int i=1;i<=3;i++)printf("%.4lf(lv=%d)|",b[i],i);
	printf("\n");*/
	double rt;
	int i;
	if(L-a[x]>C) rt =b[x]+ bt+(L-a[x]-C)/vt2;
	else rt =b[x]+(L-a[x])/vt1;
	if(rt<tt) tt=rt;
	for(i=x+1;i<=N;i++){
		if(a[i]-a[x]>C) rt =b[x]+ bt+(a[i]-a[x]-C)/vt2;
		else rt =b[x]+ (a[i]-a[x])/vt1;
		if(b[i]>rt+T) b[i] = rt+T;  
	}	
}

int main()
{
	while(scanf("%lf",&L)!=EOF){
		scanf("%d%lf%lf",&N,&C,&T);
		scanf("%lf%lf%lf",&vr,&vt1,&vt2);
		tr = L/vr;
		tt = L/vt2;
		bt = C/vt1;
		for(i=1;i<=N;i++) scanf("%d",&a[i]);
		sort(a+1,a+N+1);
		a[0] = 0;
		b[0] = 0;
		for(i=1;i<=N;i++) b[i] = a[i]*1.0/vt2+T;
		for(i=0;i<=N;i++)
			solve(i);
		if(tt<tr) puts("What a pity rabbit!");
		else puts("Good job,rabbit!");
	}
	return 0;
} 
