struct POS
{
    int x;
    int y;
    POS(int newx, int newy): x(newx), y(newy) {}
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(board[i][j] == 'O')
                {
                    if(i == 0 || i == m-1 || j == 0 || j == n-1)
                    {// remain 'O' on the boundry
                        dfs(board, i, j, m, n);
                    }
                }
            }
        }
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int i, int j, int m, int n)
    {
        stack<POS*> stk;
        POS* pos = new POS(i, j);
        stk.push(pos);
        board[i][j] = '*';
        while(!stk.empty())
        {
            POS* top = stk.top();
            if(top->x > 0 && board[top->x-1][top->y] == 'O')
            {
                POS* up = new POS(top->x-1, top->y);
                stk.push(up);
                board[up->x][up->y] = '*';
                continue;
            }
            if(top->x < m-1 && board[top->x+1][top->y] == 'O')
            {
                POS* down = new POS(top->x+1, top->y);
                stk.push(down);
                board[down->x][down->y] = '*';
                continue;
            }
            if(top->y > 0 && board[top->x][top->y-1] == 'O')
            {
                POS* left = new POS(top->x, top->y-1);
                stk.push(left);
                board[left->x][left->y] = '*';
                continue;
            }
            if(top->y < n-1 && board[top->x][top->y+1] == 'O')
            {
                POS* right = new POS(top->x, top->y+1);
                stk.push(right);
                board[right->x][right->y] = '*';
                continue;
            }
            stk.pop();
        }
    }
};
