class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int dp[nums.size()];
        
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
           while(pq.top().second<i-k){
               pq.pop();
           }
           pq.push({pq.top().first+nums[i],i});
           
           
            
        }
       while(pq.top().second!=nums.size()-1){
           pq.pop();
       }
      return pq.top().first;
    }
};