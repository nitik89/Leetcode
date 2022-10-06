class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int>stk;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(stk.size()==0||nums[stk.top()]>nums[i])
            stk.push(i);
           
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty()&&nums[stk.top()]<=nums[i]){
                ans=max(i-stk.top(),ans);
                stk.pop();
            }
            
        }
        return ans;
    }
};