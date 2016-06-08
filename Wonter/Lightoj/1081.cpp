    #include <bits/stdc++.h>
    using namespace std;
    int tree[3010][3010];
    int n, q;
     
    void Build_y(int left, int right, int x, int y)
    {
        tree[x][y] = INT_MIN;
        if(left == right)
            return ;
        int mid = left + (right - left) / 2;
        Build_y(left, mid, x, y * 2 + 1);
        Build_y(mid + 1, right, x, y * 2 + 2);
    }
     
    void Build_x(int left, int right, int x)
    {
     
        Build_y(1, n, x, 0);
        if(left == right)
            return ;
        int mid = left + (right - left) / 2;
        Build_x(left, mid, x * 2 + 1);
        Build_x(mid + 1, right,x * 2 + 2);
    }
     
    void Insert_y(int left, int right, int i, int j, int x, int y, int val)
    {
        tree[x][y] = max(tree[x][y], val);
        if(left == right)
            return ;
        int mid = left + (right - left) / 2;
        if(j <= mid)
            Insert_y(left, mid, i, j, x, y * 2 + 1, val);
        else
            Insert_y(mid + 1, right, i, j, x, y * 2 + 2, val);
    }
     
    void Insert_x(int left, int right, int i, int j, int x, int val)
    {
        Insert_y(1, n, i, j, x, 0, val);
        if(left == right)
            return ;
        int mid = left + (right - left) / 2;
        if(i <= mid)
            Insert_x(left, mid, i, j, x * 2 + 1, val);
        else
            Insert_x(mid + 1, right, i, j, x * 2 + 2, val);
    }
     
    int Query_y(int left, int right, int j_l, int j_r, int x, int y)
    {
        if(left == j_l && right == j_r)
            return tree[x][y];
        int mid = left + (right - left) / 2;
        if(j_r <= mid)
            return Query_y(left, mid, j_l, j_r, x, 2 * y + 1);
        else if(j_l > mid)
            return Query_y(mid + 1, right, j_l, j_r, x, 2 * y + 2);
        return max(Query_y(left, mid, j_l, mid, x, 2 * y + 1),
                   Query_y(mid + 1, right, mid + 1, j_r, x, 2 * y + 2));
    }
     
    int Query_x(int left, int right, int i_l, int i_r, int j, int s, int x)
    {
        if(left == i_l && right == i_r)
            return Query_y(1, n, j, j + s - 1, x, 0);
        int mid = left + (right - left) / 2;
        if(i_r <= mid)
            return Query_x(left, mid, i_l, i_r, j, s, 2 * x + 1);
        else if(i_l > mid)
            return Query_x(mid + 1, right, i_l, i_r, j, s, 2 * x + 2);
        return max(Query_x(left, mid, i_l, mid, j, s, 2 * x + 1),
                   Query_x(mid + 1, right, mid + 1, i_r, j, s, 2 * x + 2));
    }
     
    int main()
    {
        int T;
        scanf("%d", &T);
        int _case = 1;
        while(T--)
        {
            scanf("%d%d", &n, &q);
            Build_x(1, n, 0);
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                {
                    int x;
                    scanf("%d", &x);
                    Insert_x(1, n, i, j, 0, x);
                }
            printf("Case %d:\n", _case++);
            while(q--)
            {
                int i, j, s;
                scanf("%d%d%d", &i, &j, &s);
                printf("%d\n", Query_x(1, n, i, i + s - 1, j, s, 0));
            }
        }
        return 0;
    }
