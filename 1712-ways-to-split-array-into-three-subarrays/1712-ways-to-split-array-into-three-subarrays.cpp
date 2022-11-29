class Solution
{
    public:
        int getLf(vector<int> &nums, int s, int e, int c)
        {
            int ans = -1;
            while (s <= e)
            {
                int mid = ((e - s) / 2) + s;
                if (nums[mid] >= 2 *nums[c])
                {
                    ans = mid;
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            return ans;
        }
    int getRg(vector<int> &nums, int s, int e, int c, int n)
    {
        int ans = -1;
        while (s <= e)
        {
            int mid = ((e - s) / 2) + s;
            if ((nums[n - 1] + nums[c]) / 2 >= nums[mid])
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
    int waysToSplit(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }
        int ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n - 2; i++)
        {
            int lf = getLf(nums, i + 1, n - 2, i);
            if (lf == -1) { //why for this thing
                continue;
            }
            int rg = getRg(nums, lf, n - 2, i, n);
              if (rg == -1) {
                continue;
              }
            ans=ans%mod+(rg-lf+1);
        }
        return ans;
    }
};