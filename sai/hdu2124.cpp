#include <iostream>
using namespace std;
int cmp(const void *a, const void *b)
{
    return  *((int *)b) - *((int *)a);
}
int main()
{
    int L, N, i;
    int a[601], sum, len;
    while(cin >> L >> N)
    {
        for(i = 0; i < N; i++)
            cin >> a[i];

        qsort(a, N, sizeof(a[0]), cmp);
        sum = len = 0;
        for(i = 0; i < N; i++)
        if(len < L)
        {
            len += a[i];
            sum++;
        }
        else
            break;
        if(len < L)
            cout << "impossible" << endl;
        else
            cout << sum << endl;
    }
    return 0;
}
