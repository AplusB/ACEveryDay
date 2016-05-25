#include <bits/stdc++.h>

#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

using namespace std;

struct node {
    int idx;
    char d;
};

struct m {
    int idx1, idx2;
};
struct m R[10000 + 100];
int pos[10000 + 100];
struct node Ant2[10000 + 100];
int Idx[10000 + 100];

bool cmp(struct node a1, struct node a2) {
    if (a1.idx < a2.idx) return true;
    else return false;
}

bool cmp2(struct m m1, struct m m2) {
    if (m1.idx2 < m2.idx2) return true;
    else return false;
}

bool cmp3(struct m m1, struct m m2) {
    if (m1.idx1 < m2.idx1) return true;
    else return false;
}

int main() {
    int N;
    scanf("%d", &N);
    FOR(_t, 1, N) {
        int L, T, n;
        scanf("%d%d%d", &L, &T, &n);
        REP(i, n) {
            scanf("%d %c", &(Ant2[i].idx), &(Ant2[i].d));
            R[i].idx2 = Ant2[i].idx;
            if (Ant2[i].d == 'L') Ant2[i].idx -= T;
            else Ant2[i].idx += T;
            R[i].idx1 = i;
        }

        // make final seq
        //
        sort(R, R + n, cmp2);
        REP(i, n) {
            R[i].idx2 = i;
        }
        sort(R, R + n, cmp3);
        REP(i, n) {
            pos[R[i].idx1] = R[i].idx2;
        }

        sort(Ant2, Ant2 + n, cmp);

        printf("Case #%d:\n", _t);
        REP(j, n) {
            int i = pos[j];
            if ((Ant2[i].idx < 0) || (Ant2[i].idx > L)) printf("Fell off\n");
            else {
                bool overlap = false;
                if ((i - 1 >= 0) && (Ant2[i - 1].idx == Ant2[i].idx)) {
                    overlap = true;
                }
                if ((i + 1 < n) && (Ant2[i + 1].idx == Ant2[i].idx)) {
                    overlap = true;
                }
                if (overlap) printf("%d Turning\n", Ant2[i].idx);
                else {
                    printf("%d %c\n", Ant2[i].idx, Ant2[i].d);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
