#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char a[100];
    int n;
    while(scanf("%s %d",a,&n)!=EOF)
    {
        int l=strlen(a);
        n=n%8;
        while(n<0)n+=8;

        switch(n)
        {
        case 0:
            printf("%s\n",a);
            break;
        case 1:
            for(int i=l-1; i>=0; i--)
            {
                for(int j=0; j<i; j++)
                    printf(" ");
                printf("%c\n",a[i]);
            }
            break;
        case 2:
            for(int i=0; i<l; i++)
			{
				for(int j=0; j<=l/2; j++)
				{
					if(j==l/2)
                        printf("%c\n",a[l-i-1]);
                    else
                        printf(" ");
				}
			}
            break;
        case 3:
            for(int i=l-1; i>=0; i--)
            {
                for(int j=l-1; j>i; j--)
                    printf(" ");
                printf("%c\n",a[i]);
            }
            break;
        case 4:
            for(int i=l-1; i>=0; i--)
                printf("%c",a[i]);
            printf("\n");
            break;
        case 5:
            for(int i=0; i<l; i++)
            {
                for(int j=l-1; j>i; j--)
                    printf(" ");
                printf("%c\n",a[i]);
            }
            break;
        case 6:
            for(int i=0; i<l; i++)
			{
				for(int j=0; j<=l/2; j++)
				{
					if(j==l/2)
                        printf("%c\n",a[i]);
                    else
                        printf(" ");
				}
			}
            break;
        case 7:
            for(int i=0; i<l; i++)
            {
                for(int j=0; j<i; j++)
                    printf(" ");
                printf("%c\n",a[i]);
            }
            break;
        }
    }
    return 0;
}
