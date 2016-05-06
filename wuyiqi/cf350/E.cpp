#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
char s[N];
struct Node
{
    Node *pre, *nxt;
    char ch;
    int i;
    Node () {
        pre = nxt = NULL;
    }
};
char op[N];
int main()
{
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);

    scanf("%s", s+1);
    Node *now = new Node();
    Node *head = now;
    for(int i = 1; s[i]; i++) {
        Node *tmp = new Node();
        tmp->i = i;
        tmp->ch = s[i];
        now->nxt = tmp;
        tmp->pre = now;
        now = now->nxt;
    }
    Node *pt = head;
    for(int i = 0; i < p; i++) {
        pt = pt->nxt;
    }
    scanf("%s", op);
    for(int i = 0; op[i]; i++) {
        if(op[i] == 'L') {
            pt = pt->pre;
        } else if(op[i] == 'R') {
            pt = pt->nxt;
        } else {
            if(pt->ch == ')') {
                stack<char> stk;
                stk.push(')');
                Node *now = pt->nxt;
                while(!stk.empty()) {
                    pt = pt->pre;
                    if(pt->ch != stk.top()) {
                        stk.pop();
                    } else {
                        stk.push(pt->ch);
                    }
                }
                pt = pt->pre;
                pt->nxt = now;
                if(now != NULL) {
                    now->pre = pt;
                    pt = now;
                }  
            } else {
                stack<char> stk;
                stk.push('(');
                Node *now = pt->pre;
                while(!stk.empty()) {
                    pt = pt->nxt;
                    if(pt->ch != stk.top()) {
                        stk.pop();
                    } else {
                        stk.push(pt->ch);
                    }
                }
                pt = pt->nxt;
                now->nxt = pt;
                if(pt != NULL) {
                    pt->pre = now;
                } else {
                    pt = now;
                }
            }
        }
    }
    while(head->nxt) {
        head = head->nxt;
        printf("%c", head->ch);
    }
    puts("");
    return 0;
}
