#include<bits/stdc++.h>
using namespace std;

int ans[1007];

void init()
{
	int j;
	ans[0] = 0;
	for(int i=0;i<=1000;i++){
		j = 1;
		while(i+j<=1000){
			ans[i+j] = 1-ans[i] | ans[i+j];
			j<<=1;
		}
	}
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF)
		if(ans[n]) printf("Kiki\n");
		else printf("Cici\n");
	return 0;
}
