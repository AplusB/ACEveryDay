#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
struct Gauss
{
    int equation, variable;
    double a[27][11], ret[10];
    void Init() {
        equation = 27;
        variable = 10;
        memset(a, 0, sizeof(a));
    }

    bool Eliminate() {
        int col = 0, row = 0;
        for(; row < equation && col < variable; row++, col++) {
            int max_row = row;
            for(int i = row + 1; i < equation; i++) {
                if(fabs(a[i][col]) > fabs(a[max_row][col])) {
                    max_row = i;
                }
            }

            if(fabs(a[max_row][col]) < eps) {
                row--;
                continue;
            }

            if(max_row != row) {
                for(int i = col; i <= variable; i++)  {
                    swap(a[max_row][i], a[row][i]);
                }
            }

            for(int i = 0; i < equation; i++) if(i!=row){
                if(fabs(a[i][col]) < eps) {
                    continue;
                }
                double ta = a[row][col];
                double tb = a[i][col];
                for(int j = col; j <= variable; j++) {
                    a[i][j] = a[i][j] - a[row][j] * tb / ta;
                }
            }
        }
        /*
        for(int i = 0; i < 27; i++) {
            for(int j = 0; j <= 10; j++) {
                printf("%.0f ", a[i][j]);
            }
            puts("");
        }
        */
        for(int i = row; i < equation; i++) {
            if(fabs(a[i][variable]) > eps) {
                return false;
            }
        }
        for(int i = 0; i < row; i++) {
            ret[i] = a[i][variable] / a[i][i];
        }
        for(int i = row; i < variable; i++) {
            ret[i] = 0;
        }
        return true;
    }
}gauss;


string num[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

int main()
{
    freopen("A-large-practice.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T, ca = 1;
    cin >> T;
    string s;
    while(T--) {
        cin >> s;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < s.length(); i++) {
            cnt[s[i]-'A']++;
        }
        map<int, int> edge[26];
        for(int i = 0; i < 10; i++) {
            for(auto it : num[i]) {
                edge[it-'A'][i]++;
            }
        }
        gauss.Init();
        for(int i = 0; i < 26; i++) {
            for(auto it : edge[i]) {
                gauss.a[i][it.first] = it.second;
            }
            gauss.a[i][10] = cnt[i];
        }
        for(int i = 0; i < 10; i++) {
            gauss.a[26][i] = (int)num[i].length();
        }
        gauss.a[26][10] = (int)s.length();
        bool flag = gauss.Eliminate();
        cout << "Case #" << ca++ << ": ";
        for(int i = 0; i < 10; i++) {
            int cnt = (int)(gauss.ret[i]+0.5);
            for(int j = 0; j < cnt; j++) {
                printf("%c", '0'+i);
            }
        }
        cout << endl;
    }
    return 0;
}
