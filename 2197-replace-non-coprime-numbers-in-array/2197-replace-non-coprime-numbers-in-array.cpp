class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
       stack<long long>stk;
        stk.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            long long v=nums[i];
            while(!stk.empty()&&__gcd(v,stk.top())>1){
                long long x=stk.top();
                v=(long long)(x*v)/__gcd(v,x);
                stk.pop();
            }
            stk.push(v);
        }
        vector<int>ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};