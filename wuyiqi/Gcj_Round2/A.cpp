#include <bits/stdc++.h>

using namespace  std;

int a[5000], b[5000];
int N,R,P,S;

char ch[5] = "PRS";
int main()
{

        int T, ca = 1;
        cin >> T;
        while(T--)
        {
                cin >> N >> R >> P >> S;
                printf("Case #%d: ", ca++);
                int tot = 1;
                string ret = "";
                for(int last = 0; last < 3; last++) {
                        a[0] = last; tot = 1;
                        for(int i = 0; i < N; i++) {
                                int cnt = 0;
                                for(int j = 0; j < tot; j++) {
                                        if(a[j] == 0) {
                                                b[cnt++] = 0;
                                                b[cnt++] = 1;
                                        }
                                        if(a[j] == 1) {
                                                b[cnt++] = 1;
                                                b[cnt++] = 2;
                                        }
                                        if(a[j] == 2) {
                                                b[cnt++] = 0;
                                                b[cnt++] = 2;
                                        }
                                }
                                tot = cnt;
                                copy(b, b + tot, a);
                        }
                        int cot[3]; memset(cot,0,sizeof(cot));
                        string tmp = "";
                        for(int i = 0; i < tot; i++) {
                                tmp += ch[a[i]];
                                cot[a[i]]++;
                        }
                        int step = 2;
                        for(int i = 0; i < N; i++) {
                                for(int j = 0; j < tot; j += step) {
                                        string tmp1 = "";
                                        for(int k = j; k < j + step / 2; k++) {
                                                tmp1 += tmp[k];
                                        }
                                        string tmp2 = "";
                                        for(int k = j + step / 2; k < j + step; k++) {
                                                tmp2 += tmp[k];
                                        }
                                        if(tmp2 < tmp1) {
                                                for(int k = j; k < j + step / 2; k++) {
                                                        swap(tmp[k], tmp[k+step/2]);
                                                }
                                        }
                                }
                                step *= 2;
                        }
                        if(cot[0] == P && cot[1] == R && cot[2] == S) {
                                if(ret == "" || tmp < ret) {
                                        ret = tmp;
                                }
                        }
                }
                if(ret != "") cout << ret << endl;
                else cout << "IMPOSSIBLE" << endl;
        }
        return 0;
}
