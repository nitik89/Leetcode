class Solution {
public:
    int dp[101];
    int getAns(vector<int>&nums,int i){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int a=nums[i]+getAns(nums,i+2);
        int b=getAns(nums,i+1);
        return dp[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return getAns(nums,0);
    }
};