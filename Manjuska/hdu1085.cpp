#include <cstdio>  
#include <cstring>  
  
const int N = 1e4;  
int val[3] = {1, 2, 5}, cnt[3];  
int c1[N], c2[N], mmax;  
  
int main()  
{  
    while (~scanf("%d%d%d", &cnt[0], &cnt[1], &cnt[2]) && (cnt[0] || cnt[1] || cnt[2])) {  
        memset(c1, 0, sizeof(c1));  
        memset(c2, 0, sizeof(c2));  
  
        mmax = 0;  
        for (int i = 0; i < 3; i++)  
            mmax += cnt[i] * val[i];  
  
        for (int i = 0; i <= cnt[0]; i++)   
            c1[i] = 1;  
  
        for (int i = 1; i < 3; i++) {    
            for (int j = 0; j <= mmax; j++) {  
                if (c1[j] != 0) {   
                    for (int k = 0; k <= val[i] * cnt[i]; k += val[i]) { 
                        if (j + k <= mmax)  
                            c2[j + k] += c1[j];  
                    }  
                }  
            }  
            // 把当前项保存在c1，清空c2  
            memcpy(c1, c2, sizeof(c1));  
            memset(c2, 0, sizeof(c2));  
        }  
  
        int i;  
        for (i = 0; i <= mmax; i++) {  
            if (c1[i] == 0)  
                break;  
        }  
        printf("%d\n", i);  
    }  
    return 0;  
}  
