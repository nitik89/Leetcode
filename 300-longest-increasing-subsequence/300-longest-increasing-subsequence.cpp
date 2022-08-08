class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            int idx=-1,val=INT_MIN;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&val<dp[j]){
                    val=dp[j];
                    idx=j;
                }
            }
            if(idx==-1){
                dp[i]=1;
            }
            else{
                dp[i]=val+1;
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(dp[i],mx);
        }
        return mx;
        
    }
};