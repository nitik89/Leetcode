bool isValid(int row, int col, int m, int n)
{

if (row < 0 || col < 0 || row >= m || col >= n)
    return false;

return true;
}

class Solution {
public:
int minCost(vector<vector<int>> &grid)
{

    int dirx[4] = {1, 0, -1, 0};
    int diry[4] = {0, 1, 0, -1};

    int m = grid.size();
    int n = grid[0].size();
    int max = 1e9;

    queue<pair<int, int>> q;
    q.push({0, 0});
    int dist[m][n];
    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {
            dist[i][j] = max;
        }
    }
    dist[0][0] = 0;
    while (!q.empty()) {

        pair<int, int> top = q.front();

        q.pop();

        int x = top.first;
        int y = top.second;

        if (isValid(x + 1, y, m, n)) {

            if (grid[x][y] == 3) {
                if (dist[x + 1][y] > dist[x][y]) {
                    dist[x + 1][y] = dist[x][y];
                    q.push({x + 1, y});
                }
            }
            else {
                if (dist[x + 1][y] > dist[x][y] + 1) {
                    dist[x + 1][y] = dist[x][y] + 1;
                    q.push({x + 1, y});
                }
            }
        }

        if (isValid(x - 1, y, m, n)) {

            if (grid[x][y] == 4) {
                if (dist[x - 1][y] > dist[x][y]) {
                    dist[x - 1][y] = dist[x][y];
                    q.push({x - 1, y});
                }
            }
            else {
                if (dist[x - 1][y] > dist[x][y] + 1) {
                    dist[x - 1][y] = dist[x][y] + 1;
                    q.push({x - 1, y});
                }
            }
        }

        if (isValid(x, y + 1, m, n)) {

            if (grid[x][y] == 1) {
                if (dist[x][y + 1] > dist[x][y]) {
                    dist[x][y + 1] = dist[x][y];
                    q.push({x, y + 1});
                }
            }
            else {
                if (dist[x][y + 1] > dist[x][y] + 1) {
                    dist[x][y + 1] = dist[x][y] + 1;
                    q.push({x, y + 1});
                }
            }
        }

        if (isValid(x, y - 1, m, n)) {

            if (grid[x][y] == 2) {
                if (dist[x][y - 1] > dist[x][y]) {
                    dist[x][y - 1] = dist[x][y];
                    q.push({x, y - 1});
                }
            }
            else {
                if (dist[x][y - 1] > dist[x][y] + 1) {
                    dist[x][y - 1] = dist[x][y] + 1;
                    q.push({x, y - 1});
                }
            }
        }
    }

    return dist[m - 1][n - 1];
}
};