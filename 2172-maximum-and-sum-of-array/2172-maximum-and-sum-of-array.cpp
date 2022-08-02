class Solution {
public:
   int dp[20][1<<18+1];
    int getAns(vector<int>&nums,int idx,int total,int mask){
        
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][mask]!=-1){
            return dp[idx][mask];
        }
       int ans=INT_MIN;
        for(int i=1;i<=2*total;i++){
            if((mask&(1<<i))){
                continue;
            }
           ans=max(ans,(((i+1)/2)&nums[idx])+getAns(nums,idx+1,total,mask|(1<<i)));
            
        }
        return dp[idx][mask]=ans;
   
    
    }
    int maximumANDSum(vector<int>& nums, int slots) {
         memset(dp,-1,sizeof dp);
       return getAns(nums,0,slots,0);
    }
};