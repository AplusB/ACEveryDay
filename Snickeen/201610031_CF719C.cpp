#include<bits/stdc++.h>
using namespace std;
char a[200010];
int t,n,m;
int main()
{
	int i,j,k,l;
	scanf("%d%d%s",&n,&t,a);
	for(k=0;k<n&&a[k]!='.';k++);
	for(i=k+1;i<n&&a[i]<'5';i++);
	if(i==n)return 0*puts(a);
	for(;i>k+1&&a[i]>'4'&&t--;a[i]='\0',a[i-1]++,i--);
	if(a[k+1]>'4'&&t--){
		a[k]='\0';a[k-1]++;
		for(i=k-1;i>=0&&a[i]==10+'0';i--){
			a[i]='0';
			i>0?a[i-1]++:putchar('1');
		}
	}
	return 0*puts(a);
}
