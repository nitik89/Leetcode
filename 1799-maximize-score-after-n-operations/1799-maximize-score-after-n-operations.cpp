class Solution {
public:
    int dp[1<<14][8];
    int getAns(vector<int>&nums,int mask,int r){
        if(r>=nums.size()/2+1){
            return 0;
        }
        if(dp[mask][r]!=-1){
            return dp[mask][r];
        }
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if((mask&(1<<i)))continue;
            
            for(int j=0;j<nums.size();j++){
                if((mask&(1<<j))||i==j)continue;
                
               ans=max(ans, (__gcd(nums[i],nums[j])*r)+getAns(nums,mask|(1<<j)|(1<<i),r+1));
            }
        }
        return dp[mask][r]=ans;
    }
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return getAns(nums,0,1);
    }
};