class Solution
{
    public:
        vector<int> ans;

    bool dfs(int n, int idx, vector<int> &used)
    {
        if (idx == ans.size())
        {

            return true;
        }
        if (ans[idx] != 0)
        {
            return dfs(n, idx + 1, used);
        }
        else
        {
            for (int i = n; i >= 1; i--)
            {
                if (used[i]) continue;
                else
                {
                    used[i] = 1;
                    ans[idx] = i;
                    if (i == 1)
                    {

                        if(dfs(n, idx + 1, used)){
                            return true;
                        }
                    }
                    else if (i + idx < ans.size() && ans[i + idx] == 0)
                    {
                        ans[i + idx] = i;
                        if (dfs(n, idx + 1, used))
                        {
                            return true;
                        }
                        ans[i + idx] = 0;
                    }
                    ans[idx] = 0;
                    used[i] = 0;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n)
    {
        ans.resize(2 *(n) - 1, 0);

        vector<int> used(n + 1, 0);
        dfs(n, 0, used);
        return ans;
    }
};