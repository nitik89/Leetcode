class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int>leftmin(nums.size());
        leftmin[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            leftmin[i]=min(leftmin[i-1],nums[i]);
        }
        
        stack<int>stk;
        int n=nums.size();
        stk.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            // stack<int>temp=stk;
            if(nums[i]>leftmin[i]){
                while(!stk.empty()&&(stk.top()<=leftmin[i])){
                    stk.pop();
                }
                
                if(!stk.empty()){
                    // cout<<temp.top()<<" "<<nums[i]<<" "<<leftmin[i]<<"\n";
                    if(stk.top()<nums[i]&&leftmin[i]<stk.top()){
                        return true;
                    }
                }
               stk.push(nums[i]); 
            }
            
            
        }
        return false;
    }
};