#include<iostream>

using namespace std;
 
int main()
{
    int n;
    int a[1001];
    int b[1001];
    int max;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        b[i]=1;
    }
    for(int i = 0; i < n; i++)
    {
        max = 0;
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j] && b[j] > max)
            {
                max = b[j];
            }
        }
        b[i] = max + 1;
    }
    max = 0;
    for(i = 0; i < n; i++)
    {
        if(max < b[i])
            max = b[i];
    }
    printf("%d\n", max);
    return 0;
}