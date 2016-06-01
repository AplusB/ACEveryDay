#include<stdio.h>
#include<string.h>
#define max 35000
char num[max];
int main()
{
    int step;
    int addNum;
    int sumNum;
    int minNum;
    int theMaxCarry;
    int lenNum;
    while(scanf("%s",&num)!=EOF)
    {
        sumNum=0;
        addNum=0;
        theMaxCarry=-5;
        int numSize=strlen(num);
        for(step=0; step<numSize; step++)
        {
            if(num[step]>='0'&&num[step]<='9')
            {
                addNum=num[step]-'0';
            }
            if(num[step]>='A'&&num[step]<='Z')
            {
                addNum=num[step]-'A'+10;
            }
            if(num[step]>='a'&&num[step]<='z')
            {
                addNum=num[step]-'a'+36;
            }
            sumNum+=addNum;
            if(theMaxCarry<addNum)
                theMaxCarry=addNum;
        }
        if(theMaxCarry==0)
        {
            printf("2\n");
            continue;
        }
        minNum=70;
        for(step=theMaxCarry; step<=62; step++)
            if(sumNum%step==0)
            {
                minNum=step;
                break;
            }
        if(minNum<62)
            printf("%d\n",minNum+1);
        else
            printf("such number is impossible!\n");
    }
    return 0;
}
