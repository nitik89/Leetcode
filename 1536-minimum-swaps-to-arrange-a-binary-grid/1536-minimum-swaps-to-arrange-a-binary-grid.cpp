class Solution
{
    public:
        int minSwaps(vector<vector < int>> &grid)
        {
            int n = grid.size();
            vector<int> vec(n);
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                int j = n-1;
                while (j >= 0)
                {
                    if(grid[i][j]==1) break;
                    count++;
                    j--;
                }
                vec[i] = count;
            }
            
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
               	//find the best one 
                int req = (n - i - 1);
                int k = i;
                while (k < n && req > vec[k])
                {
                    k++;
                }
                if (k == n)
                {
                    return -1;
                }
                ans += (k - i);
                while (k > i)
                {
                    vec[k] = vec[k - 1];
                    k--;
                }
            }
            return ans;
        }
};