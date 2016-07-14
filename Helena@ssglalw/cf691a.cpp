#include<cstdio>
using namespace std;
const int MAX_N = 1005;
int a[MAX_N];
int n;

int main()
{
	scanf("%d", &n);
	int cnt = 0;
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 0) cnt++;
	}
	if(n==1 && cnt==1) printf("NO\n");
	else if(n>1 && cnt != 1) printf("NO\n");
	else printf("YES\n");
	return 0;
}
