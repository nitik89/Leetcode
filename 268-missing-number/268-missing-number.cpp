class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &x:nums){
            sum+=x;
        }
        int exc=(n*(n+1))/2;
        return exc-sum;
    }
};