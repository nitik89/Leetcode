class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
       int dp1[nums.size()];
        int dp2[nums.size()];
        dp1[0]=1;
        dp2[0]=1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                
                dp1[i]=dp2[i-1]+1;
                dp2[i]=dp2[i-1];
            }
            else if(nums[i]>nums[i-1]){
              
                dp2[i]=dp1[i-1]+1;
                  dp1[i]=dp1[i-1];
                
            }
            else{
                dp1[i]=dp1[i-1];
                dp2[i]=dp2[i-1];
            }
        }
      
        return max(dp1[nums.size()-1],dp2[nums.size()-1]);
    }
};