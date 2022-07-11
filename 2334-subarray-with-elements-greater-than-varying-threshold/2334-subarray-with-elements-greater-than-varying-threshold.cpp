class Solution {
public:
    int validSubarraySize(vector<int>& nums, int th) {
        int n=nums.size();
        stack<int>stk;
        vector<int>rgt(n);
        rgt[n-1]=n;
        stk.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!stk.empty()&&nums[stk.top()]>=nums[i]){
                stk.pop();
            }
            if(!stk.empty()){
                rgt[i]=stk.top();
            }
            else{
                rgt[i]=n;
            }
            stk.push(i);
        }
         stack<int>stk1;
        vector<int>lft(n);
        lft[0]=-1;
        stk1.push(0);
        for(int i=1;i<n;i++){
            while(!stk1.empty()&&nums[stk1.top()]>=nums[i]){
                stk1.pop();
            }
            if(!stk1.empty()){
                lft[i]=stk1.top();
            }
            else{
                lft[i]=-1;
            }
            stk1.push(i);
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            int a=rgt[i]-lft[i]-1;
            if(nums[i] > (th*1.0/a*1.0)){
                ans=max(ans,a);
            }
        }
        return ans;
        
    }
};