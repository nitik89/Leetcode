class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
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
      
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1]+nums[i];
        }
        long long ans=INT_MIN,mod=1e9+7;
        for(int i=0;i<n;i++){
            long long preright=pre[rgt[i]-1];
            long long preleft=lft[i]==-1?0:pre[lft[i]];
            long long sum=(preright-preleft)*nums[i];
        
            ans=max(ans,sum);
            
        }
        return ans%mod;
        
    }
};