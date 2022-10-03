class Solution {
public:
    int minCost(string s, vector<int>& cost) {
         int ans=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<s.size();i++){
            while(i+1<s.size()&&s[i]==s[i+1]){
                pq.push(cost[i]);
                i++;
            }
            pq.push(cost[i]);
           while(pq.size()>1){
               ans+=pq.top();
               pq.pop();
           }
            pq.pop();
        }
        return ans;
    }
};