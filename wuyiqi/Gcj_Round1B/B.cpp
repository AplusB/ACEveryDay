#include <bits/stdc++.h>

char s[50], t[50], a[50], b[50];
int len;
long long Abs(long long x) {
    if(x < 0) {
        return -x;
    }
    return x;
}
struct Node{
    char s[50], t[50];
    bool operator < (const Node & cmp) const {
        long long a = 0, b = 0;
        long long A = 0, B = 0;
        for(int i = 0; i < len; i++) {
            a = a * 10 + s[i] - '0';
            b = b * 10 + t[i] - '0';

            A = A * 10 + cmp.s[i] - '0';
            B = B * 10 + cmp.t[i] - '0';
        }
        if(Abs(a-b) != Abs(A - B)) {
            return Abs(a - b) < Abs(A - B);
        } else {
            if(a != A) {
                return a < A;
            } else {
                return b < B;
            }
        }

    }
};
int main() {
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%s%s", s, t);
        len = strlen(s);
        int p = -1;
        std::vector<Node> ret;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < len; i++) {
            for(int x = 0; x < 10; x++) {
                for(int y = 0; y < 10; y++) {
                    a[i] = x + '0';
                    b[i] = y + '0';
                    if(s[i] != '?') {
                        a[i] = s[i];
                    }
                    if(t[i] != '?') {
                        b[i] = t[i];
                    }
                    for(int j = i + 1; j < len; j++) {
                        a[j] = s[j]; b[j] = t[j];
                        if(s[j] == '?') {
                            a[j] = '0';
                        }
                        if(t[j] == '?') {
                            b[j] = '9';
                        }
                    }
                    Node tmp;
                    memcpy(tmp.s, a, sizeof(a));
                    memcpy(tmp.t, b, sizeof(b));
                    ret.push_back(tmp);

                    for(int j = i + 1; j < len; j++) {
                        a[j] = s[j]; b[j] = t[j];
                        if(s[j] == '?') {
                            a[j] = '9';
                        }
                        if(t[j] == '?') {
                            b[j] = '0';
                        }
                    }
                    memcpy(tmp.s, a, sizeof(a));
                    memcpy(tmp.t, b, sizeof(b));
                    ret.push_back(tmp);
                }
            }
            if(s[i] != t[i] && s[i] != '?' && t[i] != '?') {
                p = i;
                break;
            }
            if(s[i] == t[i]) {
                if(s[i] == '?') {
                    a[i] = '0';
                    b[i] = '0';
                } else {
                    a[i] = s[i];
                    b[i] = t[i];
                }
            } else {
                if(s[i] != '?') {
                    a[i] = s[i];
                    b[i] = s[i];
                } else {
                    a[i] = t[i];
                    b[i] = t[i];
                }
            }
        }
        if(p == -1) {
            Node tmp;
            memcpy(tmp.s, a, sizeof(a));
            memcpy(tmp.t, b, sizeof(b));
            ret.push_back(tmp);
        }
        std::sort(ret.begin(), ret.end());
        printf("Case #%d: %s %s\n", ca++, ret[0].s, ret[0].t);
    }
    return 0;
}
