class Solution {
public:
    vector<vector<int>>dp;
    int getAns(vector<int>& nums, vector<int>& m,int i,int front ){
        
        if(i==m.size()){
            return 0;
        }
        
        if(dp[i][front]!=INT_MIN){
           return dp[i][front];
       }
       int end=(nums.size()-1)-(i-front);
        
       
        int x=getAns(nums,m,i+1,front+1)+m[i]*nums[front];
        int y=getAns(nums,m,i+1,front)+m[i]*nums[end];
        return dp[i][front]=max(x,y);
    }
    int maximumScore(vector<int>& nums, vector<int>& m) {
        int p=m.size();
         dp.resize(p + 1, vector<int>(p + 1, INT_MIN));
       return getAns(nums,m,0,0);
    }
};