class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;
        int low=0;
        while(low<costs.size()&&low<c){
            
            pq1.push(costs[low++]);
        }
        low--;
        int high=costs.size()-1;
        int cnt=0;
        while(high>=0&&high>low&&cnt<c){
            // cout<<costs[high]<<" ";
            cnt++;
            pq2.push(costs[high--]);
        }
        high++;
        long long cost=0;
        while(k--){
            if(pq1.empty()){
               cost+=pq2.top();
                pq2.pop();
                high--;
                if(high>low){
                    pq2.push(costs[high]);
                }
            }
           else if(pq2.empty()){
               cost+=pq1.top();
                pq1.pop();
                low++;
                if(high>low){
                    pq1.push(costs[low]);
                }
            }
            else{
                if(pq1.top()>pq2.top()){
                    cost+=pq2.top();
                     pq2.pop();
                    high--;
                if(high>low){
                    pq2.push(costs[high]);
                }
                }
               else if(pq1.top()<=pq2.top()){
                    cost+=pq1.top();
                     pq1.pop();
                low++;
                if(high>low){
                    pq1.push(costs[low]);
                }
                }
                
            }
        }
        return cost;
        
    }
};