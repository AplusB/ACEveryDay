#include <bits/stdc++.h>

const int N = 500010;
char s[N], op[N];
int main()
{
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    scanf("%s", s);
    std::list<char> list;
    for(int i = 0; s[i]; i++) {
        list.push_back(s[i]);
    }
    auto it = list.begin();
    for(int i = 1; i < p; i++) it++;
    scanf("%s", op);
    for(int i = 0; op[i]; i++) {
        if(op[i] == 'L') {
            --it;
        } else if(op[i] == 'R'){
            ++it;
        } else {
            if(*it == '(') {
                it = list.erase(it);
                int cnt = 1;
                while(cnt > 0) {
                    cnt += (*it == '(') * 2 - 1;
                    it = list.erase(it);
                }
            } else {
                it = list.erase(it);
                int cnt = 1;
                while(cnt > 0) {
                    cnt += (*--it == ')') * 2 - 1;
                    it = list.erase(it);
                }
            }
            if(it == list.end()) --it;
        }
    }
    for(auto it : list) 
        putchar(it);
    puts("");
    return 0;
}
