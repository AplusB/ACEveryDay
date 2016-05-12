    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <string>
    #include <queue>
    #include <vector>

    using namespace std;

    int a,b,c;

    // DROP <0,1> or <0,2>
    // FILL <1,0> or <2,0>
    // POUR <1,2> or <2,1>
    struct measure {
        int from, to;  
        int aa, bb;
        int cnt;
        int before;
    }q[1000];
    bool vis[103][103];

    void output(int n)
    {
        if (q[n].from == 0 && q[n].to == 1) printf("DROP(1)\n");
        if (q[n].from == 0 && q[n].to == 2) printf("DROP(2)\n");
        if (q[n].from == 1 && q[n].to == 0) printf("FILL(1)\n");
        if (q[n].from == 2 && q[n].to == 0) printf("FILL(2)\n");
        if (q[n].from == 1 && q[n].to == 2) printf("POUR(1,2)\n");
        if (q[n].from == 2 && q[n].to == 1) printf("POUR(2,1)\n");
        //cout << q[n].aa << "  " << q[n].bb << endl;
    }

    void dfs(int n)
    {
        if (n < 0) return;
        dfs(q[n].before);
        output(n);
    }

    void bfs() 
    {
        memset(q, 0, sizeof(q));
        memset(vis, false, sizeof(vis));
        measure t;
        t.from = 0, t.to = 0, t.aa = 0, t.bb = 0, t.cnt = 0, t.before = -1;
        int head  = 0, tail = 1;
        q[head] = t;
        vis[0][0] = true;
        //bool flag = true;
        while (head < tail) {
            measure tmp = q[head++];
           // cout << tmp.aa << "  " << tmp.bb << endl;
            if (tmp.aa == c || tmp.bb == c) {
                printf("%d\n",tmp.cnt);
                dfs(head - 1);
                return;
            }
            //cout << tmp.aa << "  " << tmp.bb << endl;
            measure n;
            if (!vis[0][tmp.bb]) {
                n.from = 0, n.to = 1,
                n.aa = 0, n.bb = tmp.bb,
                n.before = head - 1,
                n.cnt = tmp.cnt + 1,
                q[tail++] = n, 
                vis[0][tmp.bb] = true;
            }   
            if (!vis[tmp.aa][0]) {
                n.from = 0, n.to = 2,
                n.aa = tmp.aa, n.bb = 0, 
                n.before = head - 1,
                n.cnt = tmp.cnt + 1,
                q[tail++] = n,
                vis[tmp.aa][0] = true;
            }
            if (!vis[a][tmp.bb]) {
                n.from = 1, n.to = 0,
                n.aa = a, n.bb = tmp.bb,
                n.before = head - 1,
                n.cnt = tmp.cnt + 1,
                q[tail++] = n, 
                vis[a][tmp.bb] = true;
            }
            if (!vis[tmp.aa][b]) {
                n.from = 2,
                n.to = 0,
                n.aa = tmp.aa, 
                n.bb = b, 
                n.before = head - 1,
                n.cnt = tmp.cnt + 1,
                q[tail++] = n,
                vis[tmp.aa][b] = true;
                }
            //int b1 = (tmp.aa + tmp.bb) % b;
            //int a1 = tmp.aa + tmp.bb - b1;
            int a1, b1;
            if (tmp.aa + tmp.bb <= b) a1 = 0, b1 = tmp.aa + tmp.bb;
            else a1 = tmp.aa + tmp.bb - b, b1 = b;    
            if (!vis[a1][b1]) {
                n.from = 1, n.to = 2,
                n.aa = a1, n.bb = b1, 
                n.before = head - 1,
                n.cnt = tmp.cnt + 1,
                q[tail++] = n,
                vis[a1][b1] = true;
                }
            //int a2 = (tmp.aa + tmp.bb) % a;
            //int b2 = tmp.aa + tmp.bb - a2;
            int a2, b2;
            if (tmp.aa + tmp.bb <= a) a2 = tmp.aa + tmp.bb, b2 = 0;
            else a2 = a, b2 = tmp.aa + tmp.bb - a;  
            if (!vis[a2][b2]) {
                n.from = 2, n.to = 1,
                n.aa = a2, n.bb = b2, 
                n.before = head - 1,
                n.cnt = tmp.cnt + 1,
                q[tail++] = n,
                vis[a2][b2] = true;
                }            
        }
        printf("impossible\n");  
        return;  
    }

    int main()
    {
        while (scanf("%d%d%d", &a, &b, &c) != EOF) {
            bfs();
        }
        
        return 0;
    }