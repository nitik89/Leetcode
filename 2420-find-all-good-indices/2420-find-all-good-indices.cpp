class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool>pre(n,false);
        int s=0,e=0;
        stack<int>stk;
        for(int i=0;i<nums.size();i++){
            if(!stk.empty()&&nums[i]>stk.top()){
            while(!stk.empty()){
                stk.pop();
            }
            }
            stk.push(nums[i]);
            if(stk.size()>=k){
                pre[i]=true;
            }
        }
        vector<bool>suff(n,false);
        
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            if(!st.empty()&&nums[i]>st.top()){
            while(!st.empty()){
                st.pop();
            }
            }
            st.push(nums[i]);
            if(st.size()>=k){
                suff[i]=true;
            }
        }
        vector<int>ans;
        for(int i=k;i<n-k;i++){
            if(suff[i+1]&&pre[i-1]) ans.push_back(i);
        }
        return ans;
    }
};