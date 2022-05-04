class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mx=INT_MIN,sum1=0,sum2=0,actsum=0,mxn=INT_MIN,mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
            sum2+=nums[i];
            if(sum1<0){
                sum1=0;
            }
            if(sum2>0){
                sum2=0;
            }
            
            mxn=max(mxn,nums[i]);
            actsum+=nums[i];
            
            mn=min(mn,sum2);
            mx=max(mx,sum1);
        }
        // cout<<mn<<" "<<mx<<" "<<actsum<<"\n";
        if(mxn<0){
            return mxn;
        }
        
        return max(mx,actsum-mn);
    }
};