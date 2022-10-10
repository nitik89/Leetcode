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
    void _union(int x, int y)
    {
        int x1 = find(x);
        int y1 = find(y);
        if (x1 != y1)
        {
            if (rank[x1] > rank[y1])
            {
                par[y1] = x1;
                
            }
            else if (rank[y1] > rank[x1])
            {
                par[x1] = y1;
               
            }
            else
            {
                par[y1] = x1;
                rank[x1]++;
            }
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector < int>> &ed, vector< vector< int>> &q)
    {
        rank.resize(n);
        par.resize(n);
        for (int i = 0; i < n; i++)
        {
            rank[i] = 1;
            par[i] = i;
        }
        for (int i = 0; i < q.size(); i++)
        {

            q[i].push_back(i);
        }
        sort(ed.begin(), ed.end(), [& ](vector<int> &a, vector<int> &b)
        {
            return a[2] < b[2];
	});
        sort(q.begin(), q.end(), [& ](vector<int> &a, vector<int> &b)
        {
            return a[2] < b[2];
	});
        int j = 0;
        vector<bool> ans(q.size(), false);
        for (int i = 0; i < q.size(); i++)
        {
            int x = q[i][0], y = q[i][1], cost = q[i][2];
           	while (j < ed.size() && ed[j][2] < cost)
           	{
           	    _union(ed[j][0], ed[j][1]);
           	    j++;
           	}
           	if (find(x) == find(y))
           	{
           	   	ans[q[i][3]] = true;
           	}
        }
        return ans;
    }
};