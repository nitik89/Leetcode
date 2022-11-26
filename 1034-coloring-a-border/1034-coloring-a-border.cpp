class Solution
{
    public:
        bool vis[51][51];
    vector<vector < int>> res;
    int ROW, COL, COLOR;
    bool isBorder(vector<vector < int>> &grid, int r, int c)
    {
        if (r == 0 || c == 0 || r == ROW - 1 || c == COL - 1)
        {
            return true;
        }
        if (grid[r+1][c]!=COLOR || grid[r-1][c]!=COLOR || grid[r][c+1]!=COLOR || grid[r][c-1]!=COLOR)
        {
            return true;
        }
        return false;
    }
    bool isValid(vector<vector < int>> &grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != COLOR || vis[r][c]) return false;
        return true;
    }
    void dfs(vector<vector < int>> &grid, int r, int c, int clr)
    {
        vis[r][c] = true;
        if (isBorder(grid, r, c))
        {
            res[r][c] = clr;
        }
        if (isValid(grid, r + 1, c))
        {
            dfs(grid, r + 1, c, clr);
        }
        if (isValid(grid, r, c + 1))
        {
            dfs(grid, r, c + 1, clr);
        }
        if (isValid(grid, r - 1, c))
        {
            dfs(grid, r - 1, c, clr);
        }
        if (isValid(grid, r, c - 1))
        {
            dfs(grid, r, c - 1, clr);
        }
    }

    vector<vector < int>> colorBorder(vector<vector < int>> &grid, int row, int col, int color)
    {
        ROW = grid.size();
        COL = grid[0].size();
        COLOR = grid[row][col];
        memset(vis, sizeof vis, false);
        res.resize(ROW, vector<int> (COL));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                res[i][j] = grid[i][j];
            }
        }
        dfs(grid, row, col, color);
        return res;
    }
};