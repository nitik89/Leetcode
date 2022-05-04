class Solution {
public:

int maximumProduct(vector<int>& nums)
{
    int n = nums.size();

    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int val = nums[i];
        if(val >= max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = val;
        }
        else if(val >= max2)
        {
            max3 = max2;
            max2 = val;
        }
        else if(val >= max3)
            max3 = val;

        if(val <= min1)
        {
            min2 = min1;
            min1 = nums[i];
        }
        else if(val <= min2)
            min2 = val;
    }

    return max(min1 * min2 * max1, max1 * max2 * max3);
}

};