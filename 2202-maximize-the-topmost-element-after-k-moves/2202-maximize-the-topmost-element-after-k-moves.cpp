class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1&&k%2==1){
            return -1;
        }
        if(k==0){
            return nums[0];
        }
        int mx=INT_MIN;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(k!=1){
                mx=max(mx,nums[i]);
            }
            k--;
            if(k==0){
                if(i+1<nums.size()){
                    mx=max(mx,nums[i+1]);
                }
                break;
            }
            
        }
        
        return mx==INT_MIN?-1:mx;
    }
};