#include<stdio.h>
#include<string.h>
#include<math.h> 
#include<algorithm>
using namespace std;
int main()
{
	int x1,y1,x2,y2,x3,y3,x4,y4,t,s1;
	scanf("%d",&t);
	int k=1;
	while(t--)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		x4=(x1-x2)+x3;
		y4=(y1-y2)+y3;
		s1=abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
		printf("Case %d: %d %d %d\n",k++,x4,y4,s1);
	 } 
	 return 0;
}
