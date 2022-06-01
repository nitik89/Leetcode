class Solution {
public:
    int totalSteps(vector<int>& nums) {
       
        int n=nums.size();
        stack<pair<int,int>>stk;
        stk.push({nums[n-1],0});
        int ans=0;
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            int round=0;
            while(!stk.empty()&&nums[i]>stk.top().first){
                
              cnt=max(cnt+1,stk.top().second);
                stk.pop();
            
            }
             // cout<<nums[i]<<" "<<cnt<<" "<<stk.size()<<"\n";
             ans=max(ans,cnt);
            
            stk.push({nums[i],cnt});
           
            
        }
        
        return ans;
    }
};