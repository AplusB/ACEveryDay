#include<bits/stdc++.h>

using namespace std;
char a[1007],ans[1007],t[1007];
int n,m,L,now,fl;

char calc(int x){
	char k = '9';
	for(int i=now;i<m+x+1;i++)
		if(a[i]<k){
			k = a[i];
			now = i+1;
		}
	if(k!='0') fl = 1;
	if(fl) printf("%c",k); 
}

int main()
{
	while(scanf("%s %d",a,&m) != EOF){
		L = strlen(a); now = 0; fl = 0;
		for(int i=0;i<L-m;i++)
			calc(i);
		if(!fl) printf("0");
		printf("\n");
	}
	return 0;
}
