class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(k>0&&nums[i]<0){
                nums[i]=-nums[i];
                k--;
            }
            else{
                break;
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,nums[i]);
        }
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        // cout<<k<<" ";
        
        if(k%2!=0){
            sum-=mn*2;
        }
        return sum;
        
    }
};