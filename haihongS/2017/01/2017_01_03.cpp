#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

char a[maxn],ans[100][100];

int main()
{
	while(~scanf("%s",a))
	{
		memset(ans,0,sizeof(ans));
		int len=strlen(a),n2,n1;
		n1=(len+2)/3;
		n2=len+2-2*n1;
		n1--;
		int i;
		for(i=0;i<n1;i++)
			ans[i][0]=a[i];
		for(int j=0;j<n2;j++)
			ans[n1][j]=a[i++];
		for(int j=n1-1;j>=0;j--)
			ans[j][n2-1]=a[i++];
		for(int i=0;i<n1+1;i++)
		{
			for(int j=0;j<n2;j++)
				printf("%c",ans[i][j]!='\0'?ans[i][j]:' ');
			printf("\n");
		}
	}

	return 0;
}

