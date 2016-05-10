#include<bits/stdc++.h>
using namespace std;

struct noname {
	int x,y;
	noname() {}
	noname(int a,int b){
		this->x = a;
		this->y = b;
	}
} a[200007];

int n,tot,x,y,now;
char pe[3] = " \n";


void qs(int l,int r){
	int i=l,j=r, x = a[(l+r)/2].x;
	noname T;
	while(1){
		while(a[i].x < x) i++;
		while(a[j].x > x) j--;
		if(i<=j){
			T = a[i];
			a[i] = a[j];
			a[j] = T;
			i++;j--;
		} else break;
	}
	if(i<r) qs(i,r);
	if(l<j) qs(l,j);
}

int main()
{
	while(scanf("%d",&n) && n!=0){
		tot = 0; now = 0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			a[i+i-1] = noname(x,1);
			a[i+i] = noname(y+1,-1);
		}
		qs(1,n+n);
		a[n+n+1] .x = n+1;
		for(int i=1;i<=n;i++){
			while(a[now+1].x <= i){
				now++;
				tot += a[now].y;
			}
			printf("%d%c",tot,pe[i==n]);
		}
	}
	return 0;
}
