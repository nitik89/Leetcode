class Solution
{
    public:

        vector<int> par;
    vector<int> rank;
    int find(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        int y = find(par[x]);
        par[x] = y;
        return y;
    }
    void _union(int a, int b)
    {
        int x = find(a);
        int y = find(b);
        if (x == y)
        {
            return;
        }
        if (rank[x] > rank[y])
        {
            par[y] = x;
        }
        else if (rank[y] > rank[x])
        {
            par[x] = y;
        }
        else
        {
            par[x] = y;
            rank[y]++;
        }
    }
    vector<bool> friendRequests(int n, vector<vector < int>> &res, vector< vector< int>> &req)
    {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 0;
        }

        vector<bool> ans;
        for (auto a: req)
        {
            int x = find(a[0]);
            int y = find(a[1]);
            int r = 1;
            for (auto &m: res)
            {
                int p = find(m[0]);
                int q = find(m[1]);
                if ((p == x && y == q) || (p == y && x == q)) //restriction exits
                {
                    r = 0;
                    break;
                }
            }
            ans.push_back(r);
            if (r)
            {
                _union(a[0], a[1]);//make them friend
            }
        }
        return ans;
    }
};