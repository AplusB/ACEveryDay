#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 100001;

char sz1[SIZE*2+10];
char sz2[SIZE];
int nextval[SIZE];
int N, M;


void KMP(int len1, int len2)
{
    int i, j;
    i = 0;     j = 0;
    while(i < len1 && j < len2)
    {
        if(j == -1 || sz1[i] == sz2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j];
        }
    }
    if(j >= M) printf("yes\n");
    else printf("no\n");
}



void get_nextval(int len2)
{
    int i, j;
    i = 0;     nextval[0] = -1;     j = -1;
    while(i < M)
    {
        if(j == -1 || sz2[i] == sz2[j])
        {
            ++i;    ++j;
            if(sz2[i] != sz2[j])    nextval[i] = j;
            else    nextval[i] = nextval[j];
        }
        else j = nextval[j];
    }
}



int main()
{
    int i, j;
    while(~scanf("%s%s", sz1, sz2))
    {
       memset(nextval, 0, sizeof(nextval));
       N = strlen(sz1);    M = strlen(sz2);
       if(N < M)
       {
         printf("no\n");
         continue;
       }
       for(i = 0; i < N; i++)
       {
          sz1[i+N] = sz1[i];
       }
       sz1[2*N-1] = '\0';
       get_nextval(M);
       KMP(2*N-1, M);
    }
    return 0;
}
