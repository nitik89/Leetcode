class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            unordered_map<int, int> m;
            for (int i = 0; i < nums.size(); i++)
            {

                m[nums[i]] = i;
            }
            vector<int> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                int v = target - nums[i];
                if (m.find(v) != m.end() && m[v] != i)
                {
                    ans.push_back(i);
                    ans.push_back(m[target - nums[i]]);
                    break;
                }
            }
            return ans;
        }
};