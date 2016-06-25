//hdoj 1283

#include<cstdio>
#include<string.h>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

/*

switch(X)
	{
		case X1:
			{
				
				break;
			}
		case X2：
			{
				
				break; 
			} 
		...
	}
	
*/

int main()
{
    int m1,m2,i,l,r1,r2,r3;
    char s[210];
    while(scanf("%d %d%*c%s",&m1,&m2,s)!=EOF){
        r1=r2=r3=0;
        l=strlen(s);
        for(i=0;i<l;i++){
            switch(s[i]){
                case 'A': r1=m1;break;
                case 'B': r2=m2;break;
                case 'C': m1=r3;break;
                case 'D': m2=r3;break;
                case 'E': r3=r1+r2;break;
                case 'F': r3=r1-r2;break;
            }
        }
        printf("%d,%d\n",m1,m2);
    }
    return 0;
}

