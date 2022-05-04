class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx=INT_MIN,sum=0,actsum=0,mxn=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            mxn=max(mxn,nums[i]);
            actsum+=nums[i];
            nums[i]=-nums[i];
            
            mx=max(mx,sum);
        }
        int mn=INT_MIN;
        if(mxn<0){
            return mxn;
        }
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            
           
            
            mn=max(mn,sum);
        }
        
        return max(mx,mn+actsum);
    }
};