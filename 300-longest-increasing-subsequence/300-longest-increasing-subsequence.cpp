class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            if(idx==ans.size()){
                ans.push_back(nums[i]);
            }
            else{
                ans[idx]=nums[i];
            }
        }
        return ans.size();
        
    }
};