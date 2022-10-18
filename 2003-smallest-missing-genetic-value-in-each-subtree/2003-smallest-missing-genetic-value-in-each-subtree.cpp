class Solution
{
    public:

        vector<int> mark;
    vector<int> vis;
    void dfs(vector<vector < int>> &vec, int node, vector< int > &nums)
    {
        if (vis[node])
        {
            return;
        }
        vis[node] = 1;
        mark[nums[node]] = 1;
        for (auto &x: vec[node])
        {
            dfs(vec, x, nums);
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int> &pr, vector<int> &nums)
    {
        int n = pr.size();

        vis.resize(n, 0);
        vector<vector < int>> vec(n);

        for (int i = 1; i < pr.size(); i++)
        {
           	
            vec[pr[i]].push_back(i);
        }
        int node = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                node = i;//searching only in the subtrees where 1 is present so we will apply dfs to find out which all the values are present in those subtrees and we will then find the minimum possible value out of them so we will keep on moving to its parents only
                break;
            }
        }
        int mx = INT_MIN;
        for (auto x: nums)
        {
            mx = max(x, mx);
        }
        mark.resize(mx + 1, 0);

        int miss = 1;
        vector<int> ans(n, 1);

        while (node != -1)
        {
            dfs(vec, node, nums);
            while (miss <= n && mark[miss])
            {
                miss++;
            }
           	// cout<<node<<" ";
            ans[node] = miss;
            node = pr[node];
        }
        return ans;
    }
};