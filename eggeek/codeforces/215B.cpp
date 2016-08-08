#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define maxn 5555
using namespace std;
double a[3][maxn];
double A,B;
int cnt[3];
int main()
{
	int i,j;
	double ans;
	double r1,p1,p2;
//	freopen("test.txt","r",stdin);
	for(i=0;i<3;i++){
		scanf("%d",&cnt[i]);
		for(j=0;j<cnt[i];j++)scanf("%lf",&a[i][j]);
		sort(a[i],a[i]+cnt[i]);
	}
	scanf("%lf%lf",&A,&B);
	r1=a[0][cnt[0]-1];
	p1=a[1][cnt[1]-1];
	p2=a[2][0];
	ans=r1*r1*p1/(p2*A/B+p1);
	ans=sqrt(ans);
	printf("%.6lf\n",ans);
	return 0;
}
