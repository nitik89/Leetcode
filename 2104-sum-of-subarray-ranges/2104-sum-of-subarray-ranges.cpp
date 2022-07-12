class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int>stk;
        int n=nums.size();
        vector<int>rightmin(n,n);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty()&&nums[stk.top()]>=nums[i]){
                stk.pop();
            }
            if(!stk.empty()){
                rightmin[i]=stk.top();
            }
            stk.push(i);
            
        }
        while(!stk.empty()){stk.pop();}
        vector<int>leftmin(n,-1);
        for(int i=0;i<n;i++){
            while(!stk.empty()&&nums[stk.top()]>nums[i]){
                stk.pop();
            }
            if(!stk.empty()){
                leftmin[i]=stk.top();
            }
            stk.push(i);
            
        }
        while(!stk.empty()){stk.pop();}
        vector<int>rightmax(n,n);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty()&&nums[stk.top()]<=nums[i]){
                stk.pop();
            }
            if(!stk.empty()){
                rightmax[i]=stk.top();
            }
            stk.push(i);
            
        }
while(!stk.empty()){stk.pop();}
        vector<int>leftmax(n,-1);
        for(int i=0;i<n;i++){
            while(!stk.empty()&&nums[stk.top()]<nums[i]){
                stk.pop();
            }
            if(!stk.empty()){
                leftmax[i]=stk.top();
            }
            stk.push(i);
            
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            long long rgt=(rightmax[i]-i);
            long long lft=(i-leftmax[i]);
            long long rgt1=(rightmin[i]-i);
            long long lft1=(i-leftmin[i]);
            long long mx=nums[i]*(lft*rgt-rgt1*lft1);
            sum+=mx;
        }
        return sum;
    }
    
};




