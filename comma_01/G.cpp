#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n, iCase = 0;
    cin >> n;
    //scanf("%d", &n);
    while (n--) {
        int c;
        string S1,S2,SS,s1,s2,ss;
        cin >> c >> S1 >> S2 >> SS;
        s1 = S1, s2 = S2;
        bool flag = false;
        int cnt = 0;
        while (1) {
            ss = "";
            for (int i = 0; i < c; ++i) {
                ss += s2[i];
                ss += s1[i];
            }
            //cout << "ss  " << ss << endl;
            ++cnt;
            if (!ss.compare(SS)) {
                cout << ++iCase << " " << cnt << endl;;
                //printf("%d %d\n", ++iCase, cnt);
                flag = true;
                break;
            }
            s1 = "", s2 = "";
            for (int i = 0; i < c; ++i) s1+= ss[i];
            for (int i = c; i < c * 2; ++i) s2 += ss[i];
            //cout << "s1  " << s1 << endl;
            //cout << "s2  " << s2 << endl;
            if (!s1.compare(S1) && !s2.compare(S2)) break;
        }
        if (!flag) cout << ++iCase << " " << -1 << endl;
        //if (!flag) printf("%d -1\n", ++iCase);
    }
    
    return 0;
}