#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

char str[400050];
int f[400050];
vector<int> arr;
int main()
{
    while(scanf("%s", str + 1) != EOF)
    {
        arr.clear();
        int j = 0;
        f[1] = 0;
        for(int i = 2; str[i]; ++i)
        {
            while(j > 0 && str[j + 1] != str[i])
                j = f[j];
            if(str[j + 1] == str[i])
                ++j;
            f[i] = j;
        }
        j = strlen(str + 1);
        while(f[j] > 0)
        {
            arr.push_back(f[j]);
            j = f[j];
        }
        reverse(arr.begin(), arr.end());
        for(int i = 0; i < arr.size();++i)
            printf("%d ", arr[i]);
        printf("%d\n", strlen(str + 1));
    }
    return 0;
}
