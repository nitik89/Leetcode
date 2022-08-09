class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // priority_queue<pair<int,int>,vector<pair<int,int>>temp;
         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>temp;
        
        int i=0;
        for(auto x:servers){
            pq.push({x,i++});
        }
        int t=0;
        vector<int>ans;
        for(int i=0;i<tasks.size();i++){
        // cout<<t<<" ";
            while(!temp.empty()&&temp.top()[0]<=t){
                auto x=temp.top();
                pq.push({x[1],x[2]});
                temp.pop();
            }
            if(!pq.empty()){
                ans.push_back(pq.top().second);
                temp.push({t+tasks[i],pq.top().first,pq.top().second});
                pq.pop();
            }
            else{
                auto x=temp.top();
                ans.push_back(x[2]);
                temp.pop();
                 t=x[0];
                temp.push({t+tasks[i],x[1],x[2]});
            }
           if(t<i+1){
               t=i+1;
           }
            
           
            
        }
        return ans;
    }
};